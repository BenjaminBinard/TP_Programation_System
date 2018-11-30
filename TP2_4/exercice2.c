#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

/*int pere_actif = 0;
int fils_actif = 1;*/

int traitement (char *identite, char operation, char *correspondant) {
  int val1,val2;
  printf("%s=>Entrez 2 valeurs > 0 pour une ",identite);
  if (operation == '+') printf("addition;\n");
  else printf("multiplication;\n");
  printf("%s=>Entrez 0 pour passer a la session %s;\n",identite,correspondant);
  printf("%s=>Entrez une valeur negative pour terminer.\n",identite);
  scanf("%d",&val1);
    if (val1 == 0) return (0);
  if (val1 < 0) return (-1);
  scanf("%d",&val2);
  if (operation == '+')
     printf("%s=>Resultat : %d\n",identite,val1+val2);
  else
     printf("%s=>Resultat : %d\n",identite,val1*val2);
  return(val1);
 }

 void pere( ) {
    printf("PÈRE\n");
    int val=traitement("PERE",'+',"FILS");
    printf("Valeur : %d\n",val);
 }

 void fils( ) {
    printf("FILS\n");
    int val=traitement("FILS",'*',"PERE");
    printf("Valeur : %d\n",val);
 }

 void mainPere(){
   printf("Retour Pere\n");
   //pere_actif=1;
 }

 void mainFils(){
   printf("Retour Fils\n");
   //fils_actif=1;
 }

int main(int argc, char const *argv[]) {
  pid_t pid = fork();
  pid_t monPid;

  signal(SIGUSR1, mainPere);
  signal(SIGUSR2, mainFils);

  if(pid == 0){
    monPid = getpid();
    printf("Chez Fils : %d et %d\n",monPid,pid);
    fils();
    kill(getpid(),SIGUSR1);
  }
  else{
    monPid = getpid();
    printf("Chez Pere : %d et %d\n",monPid,pid);
    kill(0,SIGUSR2);
    pere();
  }
  return 0;
}
