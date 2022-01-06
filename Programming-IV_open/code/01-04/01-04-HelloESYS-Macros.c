// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/22a kameda[at]iit.tsukuba.ac.jp
// 01.4 使うと便利なマクロ

#include <stdio.h>

int main(int argc, char *(argv[])){
  printf("Hello, ESYS folks.\n");
  printf("Here are some C predefined MACROs you may like.\n");
  printf("Hello, ESYS folks (at \"%s\").\n", __FILE__);
  printf("This code is at Line %d\n", __LINE__);
  printf("This program is compiled at %s, %s.\n", __DATE__, __TIME__);
  return 0;
}

