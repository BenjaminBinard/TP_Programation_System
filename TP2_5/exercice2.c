#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

void *func1(){
  int i;
  for(i=0;i<100;i++){
    if(i%2==0){
      printf("pair : %d\n",i);
    }
    usleep(300000);
  }
  pthread_exit(NULL);
}
void *func2(){
  int i;
  for(i=0;i<100;i++){
    if(i%2!=0){
      printf("impair : %d\n",i);
    }
    usleep(300000);
  }
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
  pthread_t  th1, th2;
  pthread_create(&th1,NULL,func1,NULL);
  pthread_create(&th2,NULL,func2,NULL);
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);
  return  0;
}
