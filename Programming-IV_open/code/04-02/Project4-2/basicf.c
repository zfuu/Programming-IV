/*
 * basicf.c
 *
 *  Created on: 2021/02/04
 *      Author: s1918021
 */
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

