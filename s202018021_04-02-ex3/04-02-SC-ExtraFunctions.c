// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.2. 簡易電卓・分割コンパイル版
// 新しい演算に対応する関数

#include <stdio.h>
#include <math.h>

float operation_absdiff(float v1, float v2) {
  if (v1 > v2)
    return v1 - v2;
  return v2 - v1;
}

float operation_log(float v1, float v2) {
  if ((v1 > 0) && (v1 != 1) && (v2 >= 0)){ //It also doesn't make sense to have log base 1
    return log(v2)/log(v1);
  }else{
    printf("Invalid input! Logarithm result undefined.\n");
    return 0;
  }
}

float operation_exp(float v1, float v2) {
  return pow(v1, v2);
}


