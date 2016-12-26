// Tests de declarations de variables sans erreur
int test_declarator_ok(){
  int x;
  int a,b;
  float c,(d),e;
}

// Test pour voir si on peut définir une variable deja declaree dans une autre fonction. Ne doit pas donner d'erreur.
void test_var_autre_fonction(){
  int x;
}

// Tests de declarations devant renvoyer des erreurs.
void test_declarator_erreur(){
  void f;
  int g, g;
}

// Tests de declaration de fonction ne devant pas renvoyer d'erreur. 
int test_parameter_ok(int argc, float f);

// Declaration de fonction devant renvoyer une erreur de parametre
float test_parameter_erreur(void a);

// Declarations de fonctions successives. Doit renvoyer des erreurs.
int coucou(), yo();

