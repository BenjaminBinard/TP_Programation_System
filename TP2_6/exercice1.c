#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t monSema;
sem_t monSema1;

void *func1(){
  int i;
  for(i=0;i<20;i++){
    sem_wait(&monSema1);
    if(i%2 == 0){
      printf("A = %d\n",i);
    }
    sem_post(&monSema);
  }
  pthread_exit(NULL);
}

void *func2(){
  int i;
  for(i=0;i<20;i++){
    sem_wait(&monSema);
    if(i%2 != 0){
      printf("B = %d\n",i);
    }
    sem_post(&monSema1);
  }
  pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
  pthread_t  th1, th2;
  int num0=0,num1=1;
  sem_init(&monSema, 0, 1);
  sem_init(&monSema1, 0, 1);
  pthread_create(&th1,NULL,func1,NULL);
  pthread_create(&th2,NULL,func2,NULL);
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);
  return  0;
}
