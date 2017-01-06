// Tests de declarations de variables sans erreur
int test_declarator_ok(){
  int x;
  int a,b;
  double c,(d),e;
}

// Tests de declarations devant renvoyer des erreurs.
void test_declarator_erreur(){
  void f;
  int g;
}

// Tests de declaration de fonction ne devant pas renvoyer d'erreur. 
//int test_parameter_ok(int argc, double h);

// Declaration de fonction devant renvoyer une erreur de parametre
//double test_parameter_erreur(void i);

// Declarations de fonctions successives. Doit renvoyer des erreurs.
//int coucou(), yo();
