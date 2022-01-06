/*
 * main.c
 *
 *  Created on: 2021/02/04
 *      Author: s1918021
 */
#include <stdio.h>
#include <string.h> // strcmp()
#include "headerfile.h" // ユーザ定義の他の関数群

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
      } else if (strcmp(operator, "log")==0){
    	resultvalue=operation_log(value1, value2);
      } else if (strcmp(operator,"exp"))==0{
    	resultvalue=operation_power(value1,value2);
      }
      printf("%g %s %g = %g\n", value1, operator, value2, resultvalue);
    }
    else if(operation_log(value1,value2==0)||operation_div(value1,value2)==0)
    {
    	printf("Invalid data");
    }
    else
    {
      printf("Missing some elements ... %g, \"%s\", %g\n", value1, operator, value2);
    }
  }

  return 0;
}


