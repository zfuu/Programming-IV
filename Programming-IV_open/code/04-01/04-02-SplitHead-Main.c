// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.1. 分割前

#include <stdio.h>
float operation_add(float v1, float v2) {
  return v1 + v2;
}

int main(int argc, char argv[]){
  float val1=14.2;
  float val2=3.4;
  printf("result = %f\n", operation_add(val1, val2));
  return 0;
}
