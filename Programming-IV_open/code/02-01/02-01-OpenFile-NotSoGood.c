// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/22a kameda[at]iit.tsukuba.ac.jp
// 02.1. ファイルのぞんざいな開き方

#include <stdio.h>

int main(int argc, char *argv[]){
  FILE *filetoopen;

  // Show number of options at command line
  printf("Number of Options : %d\n", argc);

  // Try to open it
  printf("Let's open \"%s\"! \n", argv[1]);
  filetoopen = fopen(argv[1], "r");
  printf("Ready to read \"%s\"\n", argv[1]);

  // Do something to get data from the file ...

  // And close it
  fclose(filetoopen);
  printf("File %s is now closed.\n", argv[1]);

  // Do other things ...

  printf("All set. Bye!\n");
  return 0;
}

