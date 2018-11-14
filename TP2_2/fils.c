#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  pid_t pidCourant;
  int i;

  pidCourant=getpid();
  printf("Mon pid de fils est : %d\n",pidCourant);
  for(i=0;i<5;i++){
    printf("Fils au travail !\n");
  }
  return 0;
}
