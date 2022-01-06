// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 03.3. sscanf()の試運転

#include <stdio.h>

int main(int argc, char *argv[]){
  char oneline[80]; // １行分のバッファ,固定長にしておくとsizeof()が利用可能
  float value1 , value2; // 演算用の浮動小数点数２つ
  char operator[5] = ""; // ４文字から成る演算子まで許容
  int numelements; // 代入に成功した要素数

  while (fgets(oneline, sizeof(oneline), stdin) != NULL) {
    value1 = 0;
    value2 = 0;
    numelements = sscanf(oneline, "%f %4s %f", &value1, operator, &value2);
    if (numelements == 3) {
      printf("Success: Value1   = %g\n", value1);
      printf("Success: Operator = \"%s\"\n", operator);
      printf("Success: Value2   = %g\n", value2);
    } else {
      printf("Missing some elements [got only %d item(s)]... %g, \"%s\", %g\n", numelements, value1, operator, value2);
    }
  }

  return 0;
}

