#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char * repCour = getenv("PWD");
  printf("le repertoire courant est : %s\n",repCour);
  return 0;
}
