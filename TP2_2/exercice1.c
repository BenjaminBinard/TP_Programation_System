#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  pid_t monProcessus;
  int i;
  monProcessus=fork();
  if(monProcessus==0){
    for(i=0;i<100;i++){
      if(i%2==0){
        printf("FILS impair : %d\n", i);
      }
    }
  }else{
    for(i=0;i<100;i++){
      if(i%2!=0){
        printf("PÈRE pair : %d\n", i);
      }
    }
  }
  return 0;
}
