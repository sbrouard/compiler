int test_declarator_ok(){
  int x;
  int a,b;
  float c,(d),e;
}

void test_declarator_erreur(){
  void f;
}

int test_parameter_ok(int argc, float f);

float test_parameter_erreur(void a);

int coucou(), yo();

