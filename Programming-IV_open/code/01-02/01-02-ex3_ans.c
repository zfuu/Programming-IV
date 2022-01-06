#include <stdio.h>

int main(int argc, char *argv[]){
  float k;

  k = 15.2;
  printf(">>>%.2f%%<<<\n", k);
  k = 15.2;
  printf(">>>%9.2f%%<<<\n", k);
  k = 2.334;
  printf(">>>%9.2f%%<<<\n", k);
  return 0;
}
