// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 03.2. fgets()の試運転

#include <stdio.h>

int main(int argc, char *argv[]){
  char oneline[8]; // １行分のバッファ,固定長にしておくとsizeof()が利用可能
  int i; // バッファ精査ループ用

  while (fgets(oneline, sizeof(oneline), stdin) != NULL) {
    for (i = 0; oneline[i] != '\0'; i++) {
      printf("oneline[%3d] = '%c' (%d)\n", i, oneline[i], oneline[i]);
    }
    printf("Total: %d chars ==========\n", i);
  }

  return 0;
}

