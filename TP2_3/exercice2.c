#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  FILE * file;
  char lieu[80] = "ls ";
  strcat(lieu,argv[1]);
  file = popen(lieu,"r");
  int c;
  if(file){
    while ((c = getc(file)) != EOF)
          putchar(c);
    pclose(file);
  }
  return 0;
}
