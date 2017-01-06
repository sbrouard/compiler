// Décomenter la boucle à tester, elle doit compiler et produire une boucle infinie


int main(){
  int i;
  i = 0;
  for(;;) i++;

  for(i = 72;;){i--;}

  for(;;i++){i = -i;}

  for(i = -i;;i = -i) i = 2 * i;

  return 67;
}
