#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
int tubpf[2];
int tubfp[2];

/*void pere( ){
  //char* chaineLue = (char*)malloc(80);
  char* chaine="Salut oh toi fils !!!";
  char * lecture = (char*)malloc(80);
  read(tubfp[0], lecture, 1 );
  printf("(du fils) : %d\n", lecture);
  write(tubpf[1], chaine, strlen(chaine));
  close(tubfp[0]);
  close(tubpf[1]);
}

void fils( ){
  char* chaineLue= (char*)malloc(80);
  srand(time(NULL));
  char * nbr = rand();
  printf("%d\n",nbr);
  write(tubfp[1], nbr, strlen(nbr));
  read(tubpf[0], chaineLue, 21 );
  printf("(du père) : %s\n", chaineLue);
  close(tubpf[0]);
  close(tubfp[1]);
  exit(0);
}*/

void pere( ) {
  char*chaineLue= (char*)malloc(80);
  char*chaine= (char*)malloc(80);
  read(tubfp[0],chaineLue, 14 );
  printf("(dufils) : %s\n",chaineLue);
  if(isPair(chaineLue)){// Impair
    chaine = "Nombre recu impair !";
  }else{ // Pair
    chaine = "Nombre recu pair !";
  }
  write(tubpf[1],chaine,strlen(chaine) );
  close(tubfp[0] );
  close(tubpf[1] );
}

int isPair(char *texte){
  int nbr = atoi(texte);
  return nbr%2;
}

void fils( ) {
  char*chaineLue= (char*)malloc(80);
  char*chaine=(char*)malloc(80);
  sprintf(chaine, "%d", rand());
  write(tubfp[1],chaine,strlen(chaine) );
  read(tubpf[0],chaineLue, 21 );
  printf("(dupère) : %s\n",chaineLue);
  close(tubpf[0] );
  close(tubfp[1] );
  exit(0);
}

int main(int argc, char const *argv[]) {
  pid_t pid;
  pipe(tubpf);
  pipe(tubfp);
  srand(time(NULL));
  pid=fork();
  if(pid == 0)
    fils();
  else
    pere();
  return 0;
}
