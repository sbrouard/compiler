%{
  #define _GNU_SOURCE
  
   #include <stdio.h>
   #include <stdlib.h> 
   #include "expression_symbols.h"
  //#include "expression.h"
   #include "search.h"
   #include "hash.h"

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

   enum simple_type liste_parametres[16];
   int nb_parametres = 0;
   int is_param = 1;
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
%type <t> type_name parameter_declaration
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
  asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
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

  asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  
  int reg3 = var_name();
  int reg4 =var_name();
  if($1->t == $3->t){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = and i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
    }
    else{
      int reg5 = var_name();
      asprintf(&$$->code, "%s %s%d = fptosi double %s%d to i32\n",$$->code,"%x",reg4,"%x",reg1);
      asprintf(&$$->code, "%s %s%d = fptosi double %s%d to i32\n",$$->code,"%x",reg5,"%x",reg2);
      asprintf(&$$->code, "%s %s%d = and i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg4);
    }
  }
  else{
    
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = fptosi double %s%d to i32\n",$$->code,"%x",reg4,"%x",reg2);
      asprintf(&$$->code, "%s %s%d = and i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg4);
    }
    else if ($3->t == ENTIER){
    asprintf(&$$->code, "%s %s%d = fptosi double %s%d to i32",$$->code,"%x",reg1,"%x",reg4);
    asprintf(&$$->code, "%s %s%d = and i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg2);
    }
  }
  $$->var = reg3;
  $$->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
} // ATTENTION tous les elements sont excecuté, meme si un etait faux avant
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
  
  /* if(!is_in_hash($1) && !is_param){
    yyerror("utilisation d'une variable non déclarée");
  }*/
  //  else if(!is_param) {
    struct expression_symbol *e = recup_hash($1);
    /*if(e->t == ENTIER)
      $$ = create_expression_symbol_int(e->v.n);
    else if(e->t == DOUBL)
      $$ = create_expression_symbol_float(e->v.f);
      $$->var = e->var;*/

    struct expression_symbol *res = expression_symbol_copie(e);
    $$ = res;
    printf("\n\n\n\n %d \n\n\n\n", $$->var);
    //$$->code = "";
    /* }
  $$->code = "";*/
  //  printf("\n\n\n%d\n\n\n", $$->var);
}
| CONSTANTI {
  $$ = create_expression_symbol_int($1);
  asprintf(&$$->code,"%s%d = add i32 %d,0\n","%x",$$->var,$1);
  //$$->code = "";
  }
| CONSTANTF
{
  $$ = create_expression_symbol_float($1); // _float, mais en fait double
  asprintf(&$$->code,"%s%d = fadd double %s,0.0\n","%x",$$->var,double_to_hex_str($1));
  //$$->code = "";
}
| '(' expression ')'
{
  //$$ = NULL; // Not implemented
  $$ = $2;
  //$2->code = "";
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
      $$ = $1;
      if ($$->t == ENTIER){
	($$->v.n)++;
	//asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&$$->code,"%s%s%d = load i32, i32* %s%d\n",$$->code,"%x",reg1,"%x", $1->var);
	asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
	asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$$->code,"%x",reg2,"%x", $1->var);
      }
      else{
	($$->v.f)++;
	//asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&$$->code,"%s%s%d = load double, double* %s%d\n",$$->code,"%x",reg1,"%x", $1->var);
	asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
	asprintf(&$$->code,"%s store double %s%d, double* %s%d\n",$$->code,"%x",reg2,"%x", $1->var);
      }
    }
| postfix_expression DEC_OP 
    {
      $$ = $1;
      if ($$->t == ENTIER){
	($$->v.n)--;
	//asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&$$->code,"%s%s%d = load i32, i32* %s%d\n",$$->code,"%x",reg1,"%x", $1->var);
	asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
	asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$$->code,"%x",reg2,"%x", $1->var);
      }
      else{
	($$->v.f)--;
	//asprintf(&$$->code,"%s%s%d = fsub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&$$->code,"%s%s%d = load  double* %s%d\n",$$->code,"%x",reg1,"%x", $1->var);
	asprintf(&$$->code,"%s%s%d = fsub double %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
	asprintf(&$$->code,"%s store double %s%d, double* %s%d\n",$$->code,"%x",reg2,"%x", $1->var);
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
    $$ = $2;
    ($$->v.n)++;
    //asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&$$->code,"%s%s%d = load i32, i32* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
    asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
    asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f+1.0);
    //$$->var = $2->var;
    $$ = $2;
    $$->v.f++;
    //asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&$$->code,"%s%s%d = load  double* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
    asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
    asprintf(&$$->code,"%s store double %s%d, double* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
  }
}
| DEC_OP unary_expression
{ 
  if ($2->t == ENTIER){
    //$$ = create_expression_symbol_int($2->v.n-1);
    //$$->var = $2->var;
    $$ = $2;
    $2->v.n--;
    //asprintf(&$$->code,"%s%s%d = sub %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&$$->code,"%s%s%d = load i32, i32* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
    asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
    asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f-1.0);
    //$$->var = $2->var;
    $$ = $2;
    $$->v.n--;
    //asprintf(&$$->code,"%s%s%d = fsub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&$$->code,"%s%s%d = load  double* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
    asprintf(&$$->code,"%s%s%d = fsub double %s%d,1\n",$$->code,"%x",reg2,"%x", reg1);
    asprintf(&$$->code,"%s store double %s%d, double* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
  }
}
| unary_operator unary_expression
{ 
  //$$->code = $2->code;
  asprintf(&$$->code,"%s\n",$2->code);
  if ($2->t == ENTIER){ 
    
    $$ = create_expression_symbol_int(-($2->v.n));
    asprintf(&$$->code,"%s\n",$2->code);
    //$$->var = $2->var;
    if (!$2->is_var){
      $$->var = var_name();
      asprintf(&$$->code,"%s %s%d = mul i32 %s%d,-1\n",$$->code,"%x",$$->var,"%x",$2->var);
    }
    else {
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&$$->code,"%s%s%d = load i32, i32* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
      asprintf(&$$->code,"%s%s%d = sub i32 0,%s%d\n",$$->code,"%x",reg2,"%x", reg1);
      asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
      $$->is_var = 1;
    }
  }
  else{
    $$ = create_expression_symbol_float(-($2->v.f));
    asprintf(&$$->code,"%s\n",$2->code);
    //$$->var = $2->var;
    if (!$2->is_var){
      $$->var = var_name();
      asprintf(&$$->code,"%s %s%d = fmul double %s%d,%s\n",$$->code,"%x",$$->var,"%x",$2->var,double_to_hex_str(-1));
    }
    else{
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&$$->code,"%s%s%d = load double, double* %s%d\n",$$->code,"%x",reg1,"%x", $2->var);
      asprintf(&$$->code,"%s%s%d = fsub double 0.0,%s%d\n",$$->code,"%x",reg2,"%x", reg1);
      asprintf(&$$->code,"%s store double %s%d, double* %s%d\n",$$->code,"%x",reg2,"%x", $2->var);
      $$->var = $2->var;
      $$->is_var = 1;
    }
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
  
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  int reg3 = var_name();
  char *s = "";
  asprintf(&s,"%s%s",$1->code,$3->code);
  int i = 0;
    
  if ($1->is_var){
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = load  double* %s%d\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", $1->var);
    }
  }
  else{
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", $1->var);
    }
  }

  if ($3->is_var){
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", $3->var);
    }
  }
  else {
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", $3->var);
      printf("$3->var=%d\n",$3->var);
      printf("$3->code= %s\n",$3->code);
    }
  }

  switch(i){
  case 0:
    $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n) );
    asprintf(&s, "%s %s%d = mul i32 %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = add i32 %s%d,0", s, "%x", $$->var, "%x", reg3);
    printf("reg3=%d\n",$$->var);
    break;
  case 1:
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  case 2:
    $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  default: // case 3
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  }
  //$$->var = reg3;
  //gestion du type
  /*
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
  */
}
| multiplicative_expression '/' unary_expression
{
  if (($3->t == ENTIER && $3->v.n == 0) || ($3->t == DOUBL && $3->v.f == 0)){
    yyerror("Division par 0");
  }
  else{
    char *s = "";
    asprintf(&s,"%s%s",$1->code,$3->code);
    //gestion variable ou pas
    int reg1 = var_name();
    int reg2 = var_name();
    int i = 0;
    
    if ($1->is_var){
      if($1->t == DOUBL){
	asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", $1->var);
	i++;
      }
      else{
	asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", $1->var);
      }
    }
    else{
      if($1->t == DOUBL){
	asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", $1->var);
	i++;
      }
      else{
	asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", $1->var);
      }
    }

    if ($3->is_var){
      if($3->t == DOUBL){
	asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", $3->var);
	i += 2;
      }
      else{
	asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", $3->var);
      }
    }
    else {
      if($3->t == DOUBL){
	asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", $3->var);
	i += 2;
      }
      else{
	asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", $3->var);
      }
    }


    int reg = var_name();
    switch(i){
    case 0:
      $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n) );
      asprintf(&s, "%s %s%d = sdiv i32 %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&$$->code, "%s %s\n", $$->code, s);
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", s, "%x", $$->var, "%x", reg1);
      break;
    case 1:
      $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&$$->code, "%s %s\n", $$->code, s);
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg1);
      break;
    case 2:
      $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&$$->code, "%s %s\n", $$->code, s);
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg1);
      break;
    default: // case 3
      $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&$$->code, "%s %s\n", $$->code, s);
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg1);
      break;
    }
    $$->var = reg;
 
    /*if ($1->t == DOUBL)
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
    */
  }
}
| multiplicative_expression REM unary_expression
{ // REM = %
  if ($1->t == DOUBL || $3->t == DOUBL)
    yyerror("Erreur de type : modulo pas autorisé avec double");
  else{
    $$ = create_expression_symbol_int(($1->v.n) % ($3->v.n));
    asprintf(&$$->code,"%s%s \n",$1->code,$3->code);
    
    //gestion variable ou pas
    int reg1 = var_name();
    int reg2 = var_name();
    
    if ($1->is_var){
      asprintf(&$$->code,"%s %s%d = load i32, i32* %s%d\n", $$->code,"%x",reg1,"%x", $1->var);
    }
    else{
      asprintf(&$$->code,"%s %s%d = add i32 %s%d,0\n", $$->code,"%x",reg1,"%x", $1->var);
    }

    if ($3->is_var){
      asprintf(&$$->code,"%s %s%d = load i32, i32* %s%d\n", $$->code,"%x",reg2,"%x", $3->var);      
    }
    else {
      asprintf(&$$->code,"%s %s%d = add i32 %s%d,0\n", $$->code,"%x",reg2,"%x", $3->var);
    }

    int x1 = var_name();
    int x2 = var_name();
    int x3 = var_name();
    asprintf(&$$->code,"%s %s%d = sdiv i32 %s%d,%s%d\n", $$->code, "%x", x1, "%x", reg1,"%x", reg2);
    asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n", $$->code, "%x", x2, "%x", x1, "%x", reg2);
    asprintf(&$$->code,"%s %s%d = sub i32 %s%d,%s%d\n", $$->code, "%x", x3, "%x", reg1, "%x", x2);
    
    /*
      asprintf(&$$->code,"%s %s%d = sdiv i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n",$$->code,"%x",$3->var,"%x",$3->var,"%x",$$->var);
      asprintf(&$$->code,"%s %s%d = sub i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
    */
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
  
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  int reg3 = var_name();
  char *s = "";
  asprintf(&s,"%s%s",$1->code,$3->code);
  int i = 0;
    
  if ($1->is_var){
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", $1->var);
    }
  }
  else{
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", $1->var);
    }
  }

  if ($3->is_var){
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", $3->var);
    }
  }
  else {
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", $3->var);
    }
  }

  switch(i){
  case 0:
    $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n) );
    asprintf(&s, "%s %s%d = add i32 %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = add i32 %s%d,0",$$->code, "%x", $$->var, "%x", reg3);
    break;
  case 1:
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", $$->code, "%x", $$->var, "%x", reg3);
    break;
  case 2:
    $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", $$->code, "%x", $$->var, "%x", reg3);
    break;
  default: // case 3
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", $$->code, "%x", $$->var, "%x", reg3);
    break;
  }
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
}
| additive_expression '-' multiplicative_expression
{
  
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  int reg3 = var_name();
  char *s = "";
  asprintf(&s,"%s%s",$1->code,$3->code);
  int i = 0;
    
  if ($1->is_var){
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", $1->var);
    }
  }
  else{
    if($1->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", $1->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", $1->var);
    }
  }

  if ($3->is_var){
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", $3->var);
    }
  }
  else {
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", $3->var);
    }
  }

  switch(i){
  case 0:
    $$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n) );
    asprintf(&s, "%s %s%d = sub i32 %s%d,%s%d\n", s, "%x", reg3, "%x", reg3, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = add i32 %s%d,0", s, "%x", $$->var, "%x", reg3);
    break;
  case 1:
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n) );
    asprintf(&s, "%s %s%d = fsub double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  case 2:
    $$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fsub double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  default: // case 3
    $$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f) );
    asprintf(&s, "%s %s%d = fsub double %s%d,%s%d\n", s, "%x", reg3, "%x", reg1, "%x", reg2);
    asprintf(&$$->code, "%s %s\n", $$->code, s);
    asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", $$->var, "%x", reg3);
    break;
  }
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fsub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = fsub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fsub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = sub i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
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
  
  asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  
  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if($1->t == ENTIER && $3->t == ENTIER){
    asprintf(&$$->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if($1->t == ENTIER && $3->t == DOUBL){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if($1->t == DOUBL && $3->t == ENTIER){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&$$->code,"%s %s%d = zext i1 %s%d to i32\n",$$->code,"%x",reg_final,"%x",reg3);
  $$->var = reg_final;
  $$->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
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
  
  asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }



  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if($1->t == ENTIER && $3->t == ENTIER){
    asprintf(&$$->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if($1->t == ENTIER && $3->t == DOUBL){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if($1->t == DOUBL && $3->t == ENTIER){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&$$->code,"%s %s%d = zext i1 %s%d to i32\n",$$->code,"%x",reg_final,"%x",reg3);
  $$->var = reg_final;
  $$->is_var = 0;

    
  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
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

    asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }


  


  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if($1->t == ENTIER && $3->t == ENTIER){
    asprintf(&$$->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if($1->t == ENTIER && $3->t == DOUBL){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if($1->t == DOUBL && $3->t == ENTIER){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&$$->code,"%s %s%d = zext i1 %s%d to i32\n",$$->code,"%x",reg_final,"%x",reg3);
  $$->var = reg_final;
  $$->is_var = 0;

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
  
    asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  

  

  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if($1->t == ENTIER && $3->t == ENTIER){
    asprintf(&$$->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if($1->t == ENTIER && $3->t == DOUBL){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if($1->t == DOUBL && $3->t == ENTIER){
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg4,"%x",reg1);
    asprintf(&$$->code,"%s\n %s%d = fptosi double %s%d to i32",$$->code,"%x",reg5,"%x",reg2);
    asprintf(&$$->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&$$->code,"%s %s%d = zext i1 %s%d to i32\n",$$->code,"%x",reg_final,"%x",reg3);
  $$->var = reg_final;
  $$->is_var = 0;



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

    asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&$$->code, "%s %s%d = icmp eq %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  $$->var = reg3;
  $$->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
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
  
    asprintf(&$$->code, "%s%s", $1->code, $3->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if($1->is_var){
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  else{
    if($1->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg1, "%x", $1->var);
    }
  }
  
  if($3->is_var){
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = load i32, i32* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = load double, double* %s%d\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  else{
    if($3->t == ENTIER){
      asprintf(&$$->code, "%s %s%d = add i32 %s%d,0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
    else{
      asprintf(&$$->code, "%s %s%d = fadd double %s%d,0.0\n", $$->code, "%x", reg2, "%x", $3->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&$$->code, "%s %s%d = icmp ne %s%d,%s%d\n", $$->code, "%x", reg3, "%x", reg1, "%x", reg2);
  $$->var = reg3;
  $$->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
;
 
expression
: unary_expression assignment_operator conditional_expression
{
  //asprintf(&$$->code,"%s%s",$1->code,$3->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ($1->is_var){
    if($1->t == DOUBL){
      i++;
    }
  }
  else{
    if($1->t == DOUBL){
      i++;
    }
  }

  if ($3->is_var){
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", $3->var);
    }
  }
  else {
    if($3->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", $3->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", $3->var);
    }
  }

  // TODO : case 1, 2, default
  int reg_cast = var_name();
  switch(i){
  case 0: // int int
    $1->v.n = $3->v.n;
    $$ = $1;
    asprintf(&$$->code, "%s %s\n", $3->code, s);
    asprintf(&$$->code, "%s store i32 %s%d, i32* %s%d\n", $$->code, "%x", reg2, "%x", $1->var);
    break;
  case 1: // double int
    $1->v.f = $3->v.n;
    $$ = $1;
    asprintf(&$$->code, "%s %s\n", $3->code, s);
    asprintf(&$$->code, "%s %s%d = sitofp i32 %s%d to double\n",$$->code, "%x", reg_cast, "%x",reg2);
    asprintf(&$$->code, "%s store double %s%d, double* %s%d\n", $$->code, "%x", reg_cast, "%x", $1->var);
    break;
  case 2: // int double
    $1->v.n = $3->v.f;
    $$ = $1;
    asprintf(&$$->code, "%s %s\n", $3->code, s);
    asprintf(&$$->code, "%s %s%d = fptosi double %s%d to i32\n",$$->code,"%x",reg_cast,"%x",reg1);
    asprintf(&$$->code, "%s store i32 %s%d, i32* %s%d\n", $$->code, "%x", reg_cast, "%x", $1->var);
    break;
  default: // case 3 double double 
    $1->v.f = $3->v.f;
    $$ = $1;
    asprintf(&$$->code, "%s %s\n", $3->code, s);
    //printf("---------------%d-------------\n",reg_cast);
    asprintf(&$$->code, "%s store double %s%d, double* %s%d\n", $$->code, "%x", reg2, "%x", $1->var);
    break;
  }
  /*
  if ($2 == ASSIGN){
    if ($1->t == ENTIER && $3->t == ENTIER){
      $1->v.n = $3->v.n;
      asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1; 
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
      $1->v.n = $3->v.f;      
      asprintf(&$$->code,"%s %s%d = sitofp i32 %s%d to double\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
      printf("ATTENTION: affectation d'un DOUBLE à une variable de type ENTIER sans conversion\n");
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
      $1->v.f = $3->v.n;
      asprintf(&$$->code,"%s %s%d = fptosi double %s%d to i32\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
      $1->v.f = $3->v.f;
      asprintf(&$$->code,"%s %s%d = fadd double %s%d,0.0\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
  */
  
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
	
	if( ep != NULL){
	  yyerror("Erreur : la variable suivante est deja declaree ou porte le meme nom qu'une fonction : ");
	  printf("%s\n", e.key);
	} else {
	  // Si pas d'erreur, on l'ajoute, et on remplace l'ancienne variable si elle a ete declaree a un niveau superieur (cela veut dire qu'on est sorti de ce niveau, la variable n'est plus dans la pile)
	  
	  ep = hsearch(e, ENTER);
	}
	if (ep == NULL) {
	  fprintf(stderr, "hash table : entry failed\n");
	  exit(EXIT_FAILURE);
	} else {
	  if(v->t == ENTIER)
	    asprintf(&$$, "%s%d = alloca i32\n", "%x", v->var);
	  else if(v->t == DOUBL)
	    asprintf(&$$, "%s%d = alloca double\n", "%x", v->var);
	}
      }  
    } else { // FONCTION
      
      e.key = liste_declarators[i]->nom;
      e.data = (void *) liste_declarators[i];
      
      // On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table
      ep = hsearch(e, FIND);
      
      if( ep != NULL){
	yyerror("Erreur : la fonction suivante est deja declaree ou porte le meme nom qu'une variable: ");
	printf("%s\n", e.key);
      } else {
	// Si pas d'erreur, on l'ajoute
	
	ep = hsearch(e, ENTER);
      }
      if (ep == NULL) {
	fprintf(stderr, "hash table : entry failed\n");
	exit(EXIT_FAILURE);
      }
    }
  }  

  printf("\n");


  // Pour la correction, on affiche ce qu'on a rajouté dans la table
  // de hash...
  for (i = 0; i < nb_declarators; i++){
    e.key = liste_declarators[i]->nom;
    ep = hsearch(e, FIND);

    if(ep != NULL){

      struct expression_symbol *v = (struct expression_symbol *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_expression_symbol_type(v), v->lvl);
    }
  }

  // Declaration finie, on réinitialise le nombre de declarators et parametres.
  nb_declarators = 0;
  nb_parametres = 0;
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
  is_param = 0;
  $$ = create_declarator_fonction(FONCTION, $1->nom, VIDE, liste_parametres, nb_parametres); // VIDE en attendant de savoir son type de retour...
  int i;
  ENTRY e, *ep;
  for (i = 0; i < nb_parametres ; i++){
      
    // Pas de gestion d'erreurs pour les parametres, elles sont gérées lors de la règle parameter_declaration ou un truc du genre
    e.key = liste_declarators[i]->nom;
    struct expression_symbol *v = create_expression_symbol_general(liste_parametres[i], level+1);
    printf("\n\n\n%s  %d \n\n\n", e.key, v->var);
    e.data = (void *) v;
    
    // On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table avec un niveau inferieur
    ep = hsearch(e, FIND);
    
    if( ep != NULL){
      yyerror("Erreur : la variable suivante est deja declaree ou porte le meme nom qu'une fonction : ");
      printf("%s\n", e.key);
    } else {
      // Si pas d'erreur, on l'ajoute
	  
      ep = hsearch(e, ENTER);
    }
    if (ep == NULL) {
      fprintf(stderr, "hash table : entry failed\n");
      exit(EXIT_FAILURE);
    }
  }
  
  // Pour la correction, on affiche ce qu'on a rajouté dans la table
  // de hash...

  for (i = 0; i < nb_declarators; i++){
    e.key = liste_declarators[i]->nom;
    ep = hsearch(e, FIND);

    if(ep != NULL){

      struct expression_symbol *v = (struct expression_symbol *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_expression_symbol_type(v), v->lvl);
    }
  }

}
| declarator '(' ')'
{ 
  $$ = create_declarator_fonction(FONCTION, $1->nom, VIDE, NULL, 0); // VIDE en attendant de savoir son type de retour...
}
;

parameter_list
: parameter_declaration
{
  nb_parametres++;
  liste_parametres[nb_parametres-1] = $1;
  nb_declarators++;
}
| parameter_list ',' parameter_declaration
{
  nb_parametres++;
  liste_parametres[nb_parametres-1] = $3;
  nb_declarators++;
}
;

parameter_declaration
: type_name declarator
{
  // Erreur parametre : void arg;
  if( $1 == VIDE && $2->d == VAR){
    yyerror("Erreur : l'argument suivant est de type void :");
    printf("%s\n", $2->nom); 
  } else if( $2->d == FONCTION){
    yyerror("Erreur : la fonction suivante ne peut pas etre un paramètre :");
    printf("%s\n", $2->nom);
  } else {
    $$ = $1;
    liste_declarators[nb_declarators] = $2;
  }
  
}
;

statement
: compound_statement {$$ = $1;}
| expression_statement {$$ = $1;}
| selection_statement {$$ = $1;}
| iteration_statement {$$ = $1;}
| jump_statement {$$ = $1;}
;

compound_statement
: LB RB {$$ = "";}
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
  is_param = 1;
}
;

declaration_list
: declaration {$$ = $1;}
| declaration_list declaration {asprintf(&$$,"%s%s",$1,$2);}
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
{
  $$ = "";
  //printf("code:%s\nreg:%d\n",$3->code,$3->var);
  int cond = var_name();
  int label = var_name();
  if ($3->is_var){
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n","%x",$3->code,label,"%x",$3->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$3->code,"%x",cond,"%x",$3->var);
  } 
  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%then",label,"%endif",label);
  asprintf(&$$,"%s then%d:\n %s br label %s%d\n",$$,label,$5,"%endif",label);
  asprintf(&$$,"%s endif%d:\n",$$,label);
}
| IF '(' expression ')' statement ELSE statement
{
  $$ = "";
  int cond = var_name();
  int label = var_name();
  //  asprintf(&$$,"\n\n\n Objet du délit : \n %s\n\n\n\n",$3->code);
  if ($3->is_var){
  asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n","%x",$3->code,label,"%x",$3->var);
  asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$3->code,"%x",cond,"%x",$3->var);
  } 
  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%then",label,"%else",label);
  asprintf(&$$,"%s then%d:\n %s br label %s%d\n",$$,label,$5,"%endif",label);
  asprintf(&$$,"%s else%d:\n %s br label %s%d\n",$$,label,$7,"%endif",label);
  asprintf(&$$,"%s endif%d:\n",$$,label);
}
| FOR '(' expression ';' expression ';' expression ')' statement 
{
  // debugage
  int cond = var_name();
  int label = var_name();
  // initialisation
  $$ = $3->code;

  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$5->code); // code de la condition

  if ($5->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$5->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$5->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&$$,"%s bodyfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$9); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&$$,"%s incfor%d:\n",$$,label);// label
  asprintf(&$$,"%s%s",$$,$7->code); // code de l'expression
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
| FOR '(' expression ';' expression ';'            ')' statement 
{
  int cond = var_name();
  int label = var_name();
  // initialisation
  $$ = $3->code;

  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$5->code); // code de la condition

  if ($5->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$5->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$5->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&$$,"%s bodyfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$8); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&$$,"%s incfor%d:\n",$$,label);// label
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
| FOR '(' expression ';'            ';' expression ')' statement 
{

  int label = var_name();
  // initialisation
  $$ = $3->code;

  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$8);
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label

}
| FOR '(' expression ';'            ';'            ')' statement 
{
  int label = var_name();
  // initialisation
  $$ = $3->code;

  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$7);
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
| FOR '('            ';' expression ';' expression ')' statement 
{
  int cond = var_name();
  int label = var_name();
  // test condition
  $$ = "";
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$4->code); // code de la condition

  if ($4->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$4->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$4->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&$$,"%s bodyfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$8); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&$$,"%s incfor%d:\n",$$,label);// label
  asprintf(&$$,"%s%s",$$,$6->code); // code de l'expression
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
| FOR '('            ';' expression ';'            ')' statement 
{
  int cond = var_name();
  int label = var_name();
  $$ = "";
  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$4->code); // code de la condition

  if ($4->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$4->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$4->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&$$,"%s bodyfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$7); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); // jump -> expression

  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label

}
| FOR '('            ';'            ';' expression ')' statement 
{
  $$ = "";
  int label = var_name();
  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$7);
  asprintf(&$$,"%s%s",$$,$5->code);
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
| FOR '('            ';'            ';'            ')' statement 
{
  $$ = "";
  int label = var_name();
  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condfor%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$6);
  asprintf(&$$,"%s br label %s%d\n",$$,"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&$$,"%s endfor%d:\n\n",$$,label); // label
}
;

iteration_statement
: WHILE '(' expression ')' statement
{
  $$ = "";
  // debugage
  int cond = var_name();
  int label = var_name();

  // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condwhile",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condwhile%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$3->code); // code de la condition

  if ($3->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$3->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$3->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodywhile",label,"%endwhile",label); // test condition
  
  // contenu while
  asprintf(&$$,"%s bodywhile%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$5); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%condwhile",label); // jump -> condition
  
  // sortie de boucle
  asprintf(&$$,"%s endwhile%d:\n\n",$$,label); // label


}
| DO statement WHILE '(' expression ')' 
{

  $$ = "";
  // debugage
  int cond = var_name();
  int label = var_name();

 
  
  // contenu while
  asprintf(&$$,"%s br label %s%d\n",$$,"%bodywhile",label); //saut à la ligne en dessous
  asprintf(&$$,"%s bodywhile%d:\n",$$,label); // label
  asprintf(&$$,"%s%s",$$,$2); // code du corps du for
  asprintf(&$$,"%s br label %s%d\n",$$,"%condwhile",label); // jump -> condition
  

   // test condition
  asprintf(&$$,"%s br label %s%d\n",$$,"%condwhile",label); //saut à la ligne en dessous
  asprintf(&$$,"%s condwhile%d:\n",$$,label); // label

  asprintf(&$$,"%s%s",$$,$5->code); // code de la condition

  if ($5->is_var){ // si est variable il faut faire un load
    asprintf(&$$,"%s%s%d = load i32, i32* %s%d\n",$$,"%x",label,"%x",$5->var);
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&$$,"%s %s%d = icmp ne i32 %s%d,0\n",$$,"%x",cond,"%x",$5->var);
  } 

  asprintf(&$$,"%s br i1 %s%d, label %s%d, label %s%d\n",$$,"%x",cond,"%bodywhile",label,"%endwhile",label); // test condition


  // sortie de boucle
  asprintf(&$$,"%s endwhile%d:\n\n",$$,label); // label


}
;

jump_statement
: RETURN ';' {$$ = "ret void\n";}
| RETURN expression ';' 
{ if ($2->t == ENTIER){
    if($2->is_var){
      int reg = var_name();
      asprintf(&$$,"%s %s%d = load i32, i32* %s%d\n",$2->code,"%x",reg,"%x",$2->var);
      asprintf(&$$,"%s ret i32 %s%d\n",$$,"%x",reg);
    }
    else{
      asprintf(&$$,"ret i32 %d",$2->v.n);
    }
  }
  else if($2->t == DOUBL){
    if($2->is_var){
      int reg = var_name();
      asprintf(&$$,"%s %s%d = load double, double* %s%d\n",$2->code,"%x",reg,"%x",$2->var);
      asprintf(&$$,"%s ret double %s%d\n",$$,"%x",reg);
    }
    else{
    asprintf(&$$,"ret double %lf",$2->v.f);
    }
  }
  else if ($2->t == VIDE){
    $$ = "ret void\n";
  }
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
| declaration {$$ = $1;}
;

function_definition
: type_name declarator compound_statement 
{
  int i;

  asprintf(&$$, "define %s @%s(", simple_type_to_llvm($1), $2->nom);
  for(i = 0; i < nb_parametres-1; i++){
    asprintf(&$$, "%s%s %s%d, ",$$, simple_type_to_llvm($2->parametres[i]), "%x", recup_hash(liste_declarators[i]->nom)->var);
  }
  if(nb_parametres > 0)
    asprintf(&$$, "%s%s %s%d){",$$, simple_type_to_llvm($2->parametres[i]), "%x", recup_hash(liste_declarators[i]->nom)->var);
  else
    asprintf(&$$, "%s){", $$);

  asprintf(&$$, "%s\n %s\n}\n\n", $$, $3);

  int reg;
  for(i = 0; i < nb_parametres-1; i++){
    reg = var_name();
    asprintf(&$$, "%s %s%d = alloca %s",$$, "%x", reg, simple_type_to_llvm($2->parametres[i]));
    
  }  

  nb_declarators = 0;
  nb_parametres = 0;
  is_param = 0;
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
    hdestroy();
    free (file_name);
    return 0;
}
