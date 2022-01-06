// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/22a kameda[at]iit.tsukuba.ac.jp
// 01.3 至極丁寧なHello ESYS

#include <stdio.h>

int main(int argc, char *(argv[])){
  int returnstatus = 0;

  returnstatus = printf("Hello, ESYS folks.\n");
  printf("Return Status = %d. (What's this? See \"man 3 printf\" or ask google...)\n", returnstatus);
  return 0;
}

