%{
   #include <stdio.h>
   #include <stdlib.h> 
   #include "expression_symbols.h"
   #include "search.h"

   extern int yylineno;
   int yylex ();
   int yyerror ();
   int level = 0;
   struct declarator *liste_declarators[16];
   int nb_declarators = 0;
%}

%token <string> IDENTIFIER
%token <n> CONSTANTI
%token <f> CONSTANTF
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token SUB_ASSIGN MUL_ASSIGN ADD_ASSIGN DIV_ASSIGN
%token SHL_ASSIGN SHR_ASSIGN
%token REM_ASSIGN
%token REM SHL SHR
%token AND OR
%token TYPE_NAME
%token INT FLOAT VOID
%token IF ELSE DO WHILE RETURN FOR
%type <s> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression 
%type <t> type_name
%type <d> declarator
%start program
%union {
  char *string;
  int n;
  float f;
  struct declarator *d;
  struct expression_symbol *s;
  enum simple_type t;
}
%%

conditional_expression
: logical_or_expression
;

logical_or_expression
: logical_and_expression
| logical_or_expression OR logical_and_expression
;

logical_and_expression
: comparison_expression
| logical_and_expression AND comparison_expression
;


shift_expression
: additive_expression   
    {
        if ($1->t == ENTIER)
            printf("Résultat : %d\n", $1->v.n);
        else
            printf("Résultat : %f\n", $1->v.f);
    }
| shift_expression SHL additive_expression
| shift_expression SHR additive_expression
;

primary_expression
: IDENTIFIER    {$$ = create_expression_symbol_int(0);}
| CONSTANTI {$$ = create_expression_symbol_int($1);}
| CONSTANTF {$$ = create_expression_symbol_float($1);}
| '(' expression ')'
{
  $$ = NULL; // Not implemented
}
| IDENTIFIER '(' ')'    {$$ = create_expression_symbol_int(0);}
| IDENTIFIER '(' argument_expression_list ')'   {$$ = create_expression_symbol_int(0);}
;

postfix_expression
: primary_expression    {$$ = $1;}
| postfix_expression INC_OP    
    {
        if ($$->t == ENTIER) 
            $$ = create_expression_symbol_int($1->v.n+1); 
        else
            $$ = create_expression_symbol_float($1->v.f+1.0); 
    }
| postfix_expression DEC_OP 
    {
        if ($$->t == ENTIER) 
            $$ = create_expression_symbol_int($1->v.n-1); 
        else
            $$ = create_expression_symbol_float($1->v.f-1.0); 
    }
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: postfix_expression    {$$ = $1;}
| INC_OP unary_expression
    {   
        if ($$->t == ENTIER)
            $$ = create_expression_symbol_int($2->v.n+1); 
        else
            $$ = create_expression_symbol_float($2->v.f+1.0); 
    }
| DEC_OP unary_expression
    { 
        if ($$->t == ENTIER) 
            $$ = create_expression_symbol_int($2->v.n-1); 
        else
            $$ = create_expression_symbol_float($2->v.f-1.0); 
    }
| unary_operator unary_expression
    { 
        if ($$->t == ENTIER) 
            $$ = create_expression_symbol_int(-($2->v.n)); 
        else
            $$ = create_expression_symbol_float(-($2->v.f)); 
    }
;

unary_operator
: '-'
;

multiplicative_expression
: unary_expression    {$$ = $1;}
| multiplicative_expression '*' unary_expression
    {
        if ($1->t == FLOTTANT)
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f)); 
            else
                $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n)); 
        }
        else
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f)); 
            else
                $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n)); 
        }
    }
| multiplicative_expression '/' unary_expression
    {
        if ($1->t == FLOTTANT)
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.f)); 
            else
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.n)); 
        }
        else
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float(($1->v.n) / ($3->v.f)); 
            else
                $$ = create_expression_symbol_int(($1->v.n) / ($3->v.n)); 
        }
    }
| multiplicative_expression REM unary_expression
    {
        if ($1->t == FLOTTANT || $3->t == FLOTTANT)
            printf("Erreur de type : modulo pas autorisé avec flottant\n");
        else
            $$ = create_expression_symbol_int(($1->v.n) % ($3->v.n)); 
    }
;

additive_expression
: multiplicative_expression    {$$ = $1;}
| additive_expression '+' multiplicative_expression
    {
        if ($1->t == FLOTTANT)
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float(($1->v.f) + ($3->v.f)); 
            else
                $$ = create_expression_symbol_float(($1->v.f) + ($3->v.n)); 
        }
        else
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float(($1->v.n) + ($3->v.f)); 
            else
                $$ = create_expression_symbol_int(($1->v.n) + ($3->v.n)); 
        }
    }
| additive_expression '-' multiplicative_expression
    {
        if ($1->t == FLOTTANT)
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float(($1->v.f) - ($3->v.f)); 
            else
                $$ = create_expression_symbol_float(($1->v.f) - ($3->v.n)); 
        }
        else
        {
            if ($3->t == FLOTTANT)
                $$ = create_expression_symbol_float(($1->v.n) - ($3->v.f)); 
            else
                $$ = create_expression_symbol_int(($1->v.n) - ($3->v.n)); 
        }
    }
;

comparison_expression
: shift_expression
| comparison_expression '<' shift_expression
| comparison_expression '>' shift_expression
| comparison_expression LE_OP shift_expression
| comparison_expression GE_OP shift_expression
| comparison_expression EQ_OP shift_expression
| comparison_expression NE_OP shift_expression
;

expression
: unary_expression assignment_operator conditional_expression
| conditional_expression
;

assignment_operator
: '='
| MUL_ASSIGN
| DIV_ASSIGN
| REM_ASSIGN
| SHL_ASSIGN
| SHR_ASSIGN
| ADD_ASSIGN
| SUB_ASSIGN
;

declaration
: type_name declarator_list ';'
{
  int i;
  ENTRY e, *ep;
  
  for (i = 0; i < nb_declarators ; i++){

    // Erreur declaration : void var;
    if (liste_declarators[i]->d == VAR) {

      if($1 == VIDE){

	yyerror("Erreur : la variable suivante est de type void :");
	printf("%s\n", liste_declarators[i]->nom);
	
      } else {
	// Si pas d'erreur de declaration, on rentre la variable dans la hash table.
	
	e.key = liste_declarators[i]->nom;
	struct variable *v = create_variable($1, level);
	e.data = (void *) v;
	
	// On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table avec un niveau inferieur
	ep = hsearch(e, FIND);
	
	if( ep != NULL && ((struct variable *)(ep->data))->lvl <= v->lvl){
	  yyerror("Erreur : la variable suivante est deja declaree : ");
	  printf("%s\n", e.key);
	} else {
	  // Si pas d'erreur, on l'ajoute, et on remplace l'ancienne variable si elle a ete declaree a un niveau superieur (cela veut dire qu'on est sorti de ce niveau, la variable n'est plus dans la pile)
	  
	  ep = hsearch(e, ENTER);
	}
	if (ep == NULL) {
	  fprintf(stderr, "hash table : entry failed\n");
	  exit(EXIT_FAILURE);
	  }	
      }
    }
      
    
    // Erreur declaration : void f(), n ,...;
    if( liste_declarators[i]->d == FONCTION && nb_declarators > 1){
      yyerror("Erreur : la fonction suivante doit etre declaree individuellement :");
      printf("%s\n", liste_declarators[i]->nom);
    }

  }

  printf("\n");

  for (i = 0; i < nb_declarators; i++){
    e.key = liste_declarators[i]->nom;
    ep = hsearch(e, FIND);

    if(ep != NULL){

      struct variable *v = (struct variable *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_variable_type(v), v->lvl);
    }
  }

  // Declaration finie, on réinitialise le nombre de declarators.
  nb_declarators = 0;
}
;

declarator_list
: declarator
{
  nb_declarators++;
  liste_declarators[nb_declarators-1] = $1;
}
| declarator_list ',' declarator
{
  nb_declarators++;
  liste_declarators[nb_declarators-1] = $3;
}
;

type_name
: VOID
{ $$ = VIDE; }
| INT
{ $$ = ENTIER; }
| FLOAT
{ $$ = FLOTTANT; }
;

declarator
: IDENTIFIER    
{
  $$ = create_declarator(VAR, $1);
  printf("Identifier : %s\n",$1);  
}
| '(' declarator ')'
{
  $$ = create_declarator(VAR, $2->nom);
}
| declarator '(' parameter_list ')'
{ 
  $$ = create_declarator(FONCTION, $1->nom);
}
| declarator '(' ')'
{ 
  $$ = create_declarator(FONCTION, $1->nom);
}
;

parameter_list
: parameter_declaration
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator
{
  // Erreur parametre : void arg;
  if( $1 == VIDE && $2->d == VAR){
    yyerror("Erreur : l'argument suivant est de type void :");
    printf("%s\n", $2->nom); 
  }
}
;

statement
: compound_statement
| expression_statement
| selection_statement
| iteration_statement
| jump_statement
;

compound_statement
: LB RB
| LB declaration_list RB
| LB declaration_list statement_list RB
| LB statement_list RB
;

LB
:'{'
{ level++; }
;

RB
: '}'
{
  level--;
  
  if(level == 0)
    hdestroy();
  hcreate(MAX_VAR);
}
;

declaration_list
: declaration
| declaration_list declaration
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';'
;

selection_statement
: IF '(' expression ')' statement
| IF '(' expression ')' statement ELSE statement
| FOR '(' expression ';' expression ';' expression ')' statement
| FOR '(' expression ';' expression ';'            ')' statement
| FOR '(' expression ';'            ';' expression ')' statement
| FOR '(' expression ';'            ';'            ')' statement
| FOR '('            ';' expression ';' expression ')' statement
| FOR '('            ';' expression ';'            ')' statement
| FOR '('            ';'            ';' expression ')' statement
| FOR '('            ';'            ';'            ')' statement
;

iteration_statement
: WHILE '(' expression ')' statement
: DO statement WHILE '(' expression ')' 
;

jump_statement
: RETURN ';'
| RETURN expression ';'
;

program
: external_declaration
| program external_declaration
;

external_declaration
: function_definition
| declaration
;

function_definition
: type_name declarator compound_statement
;

%%
#include <stdio.h>
#include <string.h>

#define MAX_VAR 1024

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s ", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }

    hcreate(MAX_VAR);
    
    yyparse ();
    free (file_name);
    return 0;
}
