#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char const *argv[]) {
  int fichier;
  char *texte="oui oui";
  int taille=strlen(texte);

  fichier = creat("DATA",0777);
  fichier = open("DATA",O_RDWR);
  write(fichier,texte,taille);

  //printf("Les \"o\" vont être remplacés par \"l\".\nAppuyez sur une touche puis sur entrée pour continuer\n> ");
  //scanf(" ");

  int i;
  int pos;
  char *carCourant;

  for(i=0;i<taille;i++){
    pos = lseek(fichier,i,0);
    read(fichier,carCourant,1);
    printf("%s",carCourant);
    write(fichier,"T",1);
  }

  return 0;
}
