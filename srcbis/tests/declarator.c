int test_declarator_ok(){
  int x;
  int a,b;
  double c,(d),e;
}

void test_declarator_erreur(){
  void f;
}

int test_parameter_ok(int argc, double f);

double test_parameter_erreur(void a);

int coucou(), yo();


void test_addition(){
  double a,b,c;
  a = 1;
  b = 2.0;
  c = a+b;
}


void test_postfix_expression(){
  int i;
  i = 0;
  i++;
  i--;
}

