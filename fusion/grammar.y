%{
  #define _GNU_SOURCE
  
   #include <stdio.h>
   #include <stdlib.h> 
   #include "expression_symbols.h"
  //#include "expression.h"
   #include "search.h"
   #include "hash.c"

char *double_to_hex_str(double d){
  char *s = NULL;
  union {
    double a;
    long long int b;
  } u;
  u.a = d;
  asprintf(&s, "%#08llx", u.b);
  return s;
}
  
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
%token INT DOUBLE VOID
%token IF ELSE DO WHILE RETURN FOR
%type <s> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression shift_expression comparison_expression logical_and_expression logical_or_expression conditional_expression expression argument_expression_list
%type <t> type_name
%type <d> declarator
%type <n> assignment_operator
%type <string> program expression_statement statement external_declaration statement_list selection_statement function_definition iteration_statement jump_statement compound_statement declaration_list LB RB declaration IF FOR DO WHILE RETURN
%start compilation_program
%union {
  char *string;
  int n;
  double f;
  enum simple_type t;
  struct declarator *d;
  struct expression_symbol *s;
  //struct expression expr;
}
%%

conditional_expression
: logical_or_expression {$$ = $1;}
;

logical_or_expression
: logical_and_expression {$$ = $1;}
| logical_or_expression OR logical_and_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n || $3->v.n);
  }
  else if ($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n || $3->v.f);
  }
  else if ($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f || $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f || $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
;

logical_and_expression
: comparison_expression {$$ = $1;}
| logical_and_expression AND comparison_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n && $3->v.n);
  }
  else if ($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n && $3->v.f);
  }
  else if ($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f && $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f && $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
;


shift_expression
: additive_expression   
    {
      if ($1->t == ENTIER){
            printf("Résultat : %d\n", $1->v.n);
	    /*$$ = create_expression_symbol_int($1->v.n);
	      $$->var = $1->var;*/
	    
      }
      else{
            printf("Résultat : %f\n", $1->v.f);
	    /*$$ = create_expression_symbol_int($1->v.f);
	      $$->var = $1->var;*/
      }
      //$$->code = $1->code;
      $$ = $1;
    }
| shift_expression SHL additive_expression
| shift_expression SHR additive_expression
;

primary_expression
: IDENTIFIER    
{
  if(!is_in_hash($1)){
    yyerror("utilisation d'une variable non déclarée");
  }
  else {
    struct expression_symbol *e = recup_hash($1);
    /*if(e->t == ENTIER)
      $$ = create_expression_symbol_int(e->v.n);
    else if(e->t == DOUBL)
      $$ = create_expression_symbol_float(e->v.f);
      $$->var = e->var;*/
    $$ = e;
 }
}
| CONSTANTI {
  $$ = create_expression_symbol_int($1);
  asprintf(&$$->code,"%s%d = add i32 %d,0\n","%x",$$->var,$1);
  }
| CONSTANTF
{
  $$ = create_expression_symbol_float($1); // _float, mais en fait double
  asprintf(&$$->code,"%s%d = add double %s,0\n","%x",$$->var,double_to_hex_str($1));
  //printf("code: %s",$$->code);
}
| '(' expression ')'
{
  //$$ = NULL; // Not implemented
  $$ = $2;
}
| IDENTIFIER '(' ')'    
{
  $$ = create_expression_symbol_int(0);
}
| IDENTIFIER '(' argument_expression_list ')'   {
  //$$ = create_expression_symbol_int(0);
  $$ = $3;
  }
;

postfix_expression
: primary_expression    {$$ = $1;}
| postfix_expression INC_OP    
    {
      if ($$->t == ENTIER){ 
	$$ = create_expression_symbol_int($1->v.n+1);
	    $$->var = $1->var;
	    asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
      }
      else{
            $$ = create_expression_symbol_float($1->v.f+1.0);
	    $$->var = $1->var;
	    asprintf(&$$->code,"%s%s%d = add double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
      }
    }
| postfix_expression DEC_OP 
    {
      if ($$->t == ENTIER){
            $$ = create_expression_symbol_int($1->v.n-1);
	    $$->var = $1->var;
	    asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
      }
      else{
            $$ = create_expression_symbol_float($1->v.f-1.0);
	    $$->var = $1->var;
	    asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
      }
    }
;

argument_expression_list
: expression {$$ = $1;}
| argument_expression_list ',' expression
{
  $$ = $1;
  asprintf(&$$->code,"%s %s\n",$1->code,$3->code);
}
;

unary_expression
: postfix_expression    {$$ = $1;}
| INC_OP unary_expression
{   
  if ($2->t == ENTIER){
  //$$ = create_expression_symbol_int($2->v.n+1);
  //$$->var = $2->var;
    printf("l'erreur est après ca\n");
    $$ = $2;
    ($$->v.n)++;
    asprintf(&$$->code,"%s%s%d = add %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f+1.0);
    //$$->var = $2->var;
    $$ = $2;
    $$->v.f++;
    asprintf(&$$->code,"%s%s%d = add double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
  }
}
| DEC_OP unary_expression
{ 
  if ($2->t == ENTIER){
    //$$ = create_expression_symbol_int($2->v.n-1);
    //$$->var = $2->var;
    $$ = $2;
    $2->v.n--;
    asprintf(&$$->code,"%s%s%d = sub %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f-1.0);
    //$$->var = $2->var;
    $$ = $2;
    $$->v.n--;
    asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
  }
}
| unary_operator unary_expression
{ 
  if ($$->t == ENTIER){ 
    $$ = create_expression_symbol_int(-($2->v.n));
    $$->var = $2->var;
    asprintf(&$$->code,"%s %s%d = mul i32 %s%d,-1\n",$2->code,"%x",$$->var,"%x",$$->var);
  }
  else{
    $$ = create_expression_symbol_float(-($2->v.f));
    $$->var = $2->var;
    asprintf(&$$->code,"%s %s%d = fmul double %s%d,-1\n",$2->code,"%x",$$->var,"%x",$$->var);
  }
}
;

unary_operator
: '-'
;

multiplicative_expression
: unary_expression    {$$ = $1;}
| multiplicative_expression '*' unary_expression
    {
        if ($1->t == DOUBL)
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  
        }
        else
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = mul i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
        }
    }
| multiplicative_expression '/' unary_expression
    {
        if ($1->t == DOUBL)
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
        }
        else
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float(($1->v.n) / ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_int(($1->v.n) / ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = sdiv i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
        }
    }
| multiplicative_expression REM unary_expression
{ // REM = %
        if ($1->t == DOUBL || $3->t == DOUBL)
            printf("Erreur de type : modulo pas autorisé avec flottant\n");
        else{
            $$ = create_expression_symbol_int(($1->v.n) % ($3->v.n));
	    asprintf(&$$->code,"%s%s \n",$1->code,$3->code);
	    asprintf(&$$->code,"%s %s%d = sdiv i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	    asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n",$$->code,"%x",$3->var,"%x",$3->var,"%x",$$->var);
	    asprintf(&$$->code,"%s %s%d = sub i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	}
    }
;

additive_expression
: multiplicative_expression
{
  $$ = $1;
}
| additive_expression '+' multiplicative_expression
{
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  
}
| additive_expression '-' multiplicative_expression
{
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = sub i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
}
;

comparison_expression
: shift_expression
{
  $$ = $1;
}
| comparison_expression '<' shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n < $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n < $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f < $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f < $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
| comparison_expression '>' shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n > $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n > $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f > $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f > $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
| comparison_expression LE_OP shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n <= $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n <= $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f <= $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f <= $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
| comparison_expression GE_OP shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n >= $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n >= $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f >= $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f >= $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
| comparison_expression EQ_OP shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n == $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n == $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f == $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f == $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
| comparison_expression NE_OP shift_expression
{
  if ($1->t == ENTIER && $3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n != $3->v.n);
  }
  else if($1->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.n != $3->v.f);
  }
  else if($3->t == ENTIER){
    $$ = create_expression_symbol_int($1->v.f != $3->v.n);
  }
  else{
    $$ = create_expression_symbol_int($1->v.f != $3->v.f);
  }
  asprintf(&$$->code,"%s%s %s%d = add %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
;
 
expression
: unary_expression assignment_operator conditional_expression
{
  if ($2 == ASSIGN){
    if ($1->t == ENTIER && $3->t == ENTIER){
      $1->v.n = $3->v.n;
      asprintf(&$$->code,"%s %s%d = add i32 %s%d,0\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1; 
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
      $1->v.n = $3->v.f;      
      asprintf(&$$->code,"%s %s%d = sitofp i32 %s%d to double\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
      printf("ATTENTION: affectation d'un DOUBLE à une variable de type ENTIER sans conversion");
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
      $1->v.f = $3->v.n;
      asprintf(&$$->code,"%s %s%d = fptosi double %s%d to i32\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
      $1->v.f = $3->v.f;
      asprintf(&$$->code,"%s %s%d = add double %s%d,0\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
 }
/* pas demandé dans le sujet !!


  else if ($2 == ASSIGN_MUL){
    if ($1->t == ENTIER && $3->t == ENTIER){
      $1->v.n *= $3->v.n;
      $$ = $3;
      asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n",$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_DIV){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_REM){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SHL){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SHR){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_ADD){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SUB){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
    }*/
 }
| conditional_expression {$$ = $1;}
;

assignment_operator
: '=' {$$ = ASSIGN;}
| MUL_ASSIGN {$$ = ASSIGN_MUL;}
| DIV_ASSIGN {$$ = ASSIGN_DIV;}
| REM_ASSIGN {$$ = ASSIGN_REM;}
| SHL_ASSIGN {$$ = ASSIGN_SHL;}
| SHR_ASSIGN {$$ = ASSIGN_SHR;}
| ADD_ASSIGN {$$ = ASSIGN_ADD;}
| SUB_ASSIGN {$$ = ASSIGN_SUB;}
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
	struct expression_symbol *v = create_expression_symbol_general($1, level);
	e.data = (void *) v;
	
	// On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table avec un niveau inferieur
	ep = hsearch(e, FIND);
	
	if( ep != NULL && ((struct expression_symbol *)(ep->data))->lvl <= v->lvl){
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

      struct expression_symbol *v = (struct expression_symbol *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_expression_symbol_type(v), v->lvl);
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
| DOUBLE
{ $$ = DOUBL; }
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
: compound_statement {$$ = $1;}
| expression_statement {$$ = $1;}
| selection_statement {$$ = "";}
| iteration_statement {$$ = "";}
| jump_statement {$$ = $1;}
;

compound_statement
: LB RB 
| LB declaration_list RB {$$ = $2;}
| LB declaration_list statement_list RB {asprintf(&$$,"%s%s",$2,$3);}
| LB statement_list RB {$$ = $2;}
;

LB
:'{'            { level++; }
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
: statement {$$ = $1;}
| statement_list statement {asprintf(&$$,"%s%s",$1,$2);}
;

expression_statement
: ';' {$$ = '\0';}
| expression ';' {$$ = $1->code;}
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
: RETURN ';' {$$ = "ret void\n";}
| RETURN expression ';' 
{ if ($2->t == ENTIER)
    asprintf(&$$,"ret i32 %d",$2->v.n);
  else if($2->t == DOUBL)
    asprintf(&$$,"ret i32 %lf",$2->v.f);
  else if ($2->t == VIDE)
    $$ = "ret void\n";
}
;

compilation_program
:program 
{
  FILE* fichier = fopen("test_llvm.ll","w+");
  fprintf(fichier,"%s",$1);
  fclose(fichier);
}

program
: external_declaration {$$ = $1;}
| program external_declaration {asprintf(&$$,"%s%s",$1,$2);}
;

external_declaration
: function_definition {$$ = $1;}
| declaration {$$ = "";}
;

function_definition
: type_name declarator compound_statement 
{
  char *type;
  if ($1 == ENTIER)
    type = "i32";
  else if($1 == DOUBL)
    type = "double";
  else if ($1 == VIDE)
    type = "void";
  asprintf(&$$,"define %s @%s(){\n %s \n}\n",type,$2->nom,$3);
}
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
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
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