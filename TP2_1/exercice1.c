#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *texte="exercice 1 accompli !\n";
  int taille=strlen(texte);
  int w = write(STDOUT_FILENO,texte,taille);
  return 0;
}
