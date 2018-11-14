#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  pid_t pidCourant;
  pidCourant=getpid();
  printf("Mon pid est : %d\n",pidCourant);
  sleep(5);
  printf("Travail du père terminé !\n");
  return 0;
}
