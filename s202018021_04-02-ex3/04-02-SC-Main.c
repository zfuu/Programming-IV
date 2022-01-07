// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.2. 簡易電卓・分割コンパイル版
// main()関数

#include <stdio.h>
#include <string.h> // strcmp()
#include "./04-02-SC.h" // ユーザ定義の他の関数群

int main(int argc, char *argv[]){
  char oneline[80]; // １行分のバッファ,固定長にしておくとsizeof()が利用可能
  float value1 , value2; // 演算用の浮動小数点数２つ
  char operator[5] = ""; // ４文字から成る演算子まで許容
  int numelements; // 代入に成功した要素数
  float resultvalue; // 演算結果

  while (fgets(oneline, sizeof(oneline), stdin) != NULL) {
    value1 = 0;
    value2 = 0;
    numelements = sscanf(oneline, "%f %4s %f", &value1, operator, &value2);
    if (numelements == 3) {
      if (strcmp(operator, "+") == 0) {
        resultvalue = operation_plus(value1, value2);
      } else if (strcmp(operator, "-") == 0) {
        resultvalue = operation_minus(value1, value2);
      } else if (strcmp(operator, "*") == 0) {
        resultvalue = operation_mult(value1, value2);
      } else if (strcmp(operator, "/") == 0) {
        resultvalue = operation_div(value1, value2);
      } else if (strcmp(operator, "/") == 0) {
        resultvalue = operation_div(value1, value2);
      } else if (strcmp(operator, "abs") == 0) {
        resultvalue = operation_absdiff(value1, value2);
      } else if (strcmp(operator, "exp") == 0) {
        resultvalue = operation_exp(value1, value2);
      } else if (strcmp(operator, "log") == 0) {
        resultvalue = operation_log(value1, value2);
      }
      printf("%g %s %g = %g\n", value1, operator, value2, resultvalue);
    } else {
      printf("Missing some elements ... %g, \"%s\", %g\n", value1, operator, value2);
    }
  }

  return 0;
}

