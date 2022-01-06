// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.1. C言語プログラムのソースファイル分割
// ヘッダ使用しての分割後 (04-1-SplitHead-Main.c) 

#include <stdio.h>
#include "04-1-SplitHead.h"

int main(int argc, char *argv[]){
  float val1=14.2;
  float val2=3.4;
  printf("result = %f\n", operation_add(val1, val2));
  return 0;
}
