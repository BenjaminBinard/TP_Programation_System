#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float larg, lon, surface;
  larg=atoi(argv[1]);
  lon=atoi(argv[2]);
  surface=larg*lon;
  printf("La surface est de : %f mm2\n",surface);
  return 0;
}
