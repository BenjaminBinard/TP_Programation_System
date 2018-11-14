#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int primeTest(int n) {
  int i = 0;
  int s = ceil(sqrt((float)n));

  if (n<=1) return(0); // gestion de l'exception pour 1 et 0
  else if (n==2) return(1); // gestion de l'exception pour 2
  else {
    for(i=2; i<=s; i++) {
      if ((n%i)==0) return(0); // test si i divise n
    }
    return(1);
  }
}

int main(int argc, char const *argv[]) {
  int resultat;
  int i;
  pid_t monProcessus;

  monProcessus=fork();

  if(monProcessus==0){
    for(i=0;i<49;i++){
      resultat = primeTest(i);
      if(resultat==1){
        printf("FILS : %d\n", i);
      }
    }
  }else{
    for(i=50;i<100;i++){
      resultat = primeTest(i);
      if(resultat==1){
        printf("PERE : %d\n", i);
      }
    }
  }
  return 0;
}
