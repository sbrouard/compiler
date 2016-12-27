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
