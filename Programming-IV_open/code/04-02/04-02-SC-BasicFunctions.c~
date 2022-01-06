// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.2. 簡易電卓・分割コンパイル版
// 加減乗除の基本４演算に対応する４つの関数

#include <stdio.h> // printf()が使われているので

float operation_plus(float v1, float v2) {
  return v1 + v2;
}

float operation_minus(float v1, float v2) {
  return v1 - v2;
}

float operation_mult(float v1, float v2) {
  return v1 * v2;
}

float operation_div(float v1, float v2) {
  if (v2 == 0.0) {
    printf("Error: Division by Zero.\n");
    return 0.0;
  }
  return v1 / v2;
}

