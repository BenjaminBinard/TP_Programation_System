#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  pid_t monProcessus;

  monProcessus=fork();

  if(monProcessus==0){ //FILS
    execl("/home/benjamin/Documents/333_Prog_Sys/TP2_2/fils","fils",NULL);
  }else{
    execl("/home/benjamin/Documents/333_Prog_Sys/TP2_2/pere","pere",NULL);
  }
  return 0;
}
