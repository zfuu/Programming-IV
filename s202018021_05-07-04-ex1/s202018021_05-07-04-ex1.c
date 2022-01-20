// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/22a kameda[at]iit.tsukuba.ac.jp
// 02.2. ファイルの上品な開き方

#include <stdio.h>

int main(int argc, char *argv[]){
  FILE *filetoopen = NULL; // A pointer to FILE structure

  // Show number of options at command line
  printf("Number of Options : %d\n", argc);
  fflush(stdout);

  // We need at least one option for a file name to open
  if (argc <= 1) { // What happens if you put other figure here?
    printf("Error: You need to specify a file to open.\n");
    fflush(stdout);
    return 1;
  }

  // Try to open it
  printf("Let's open \"%s\"! \n", argv[1]);
  fflush(stdout);
  filetoopen = fopen(argv[1], "r");
  if (filetoopen == NULL) {
    printf("Error: Failed to open/read \"%s\".\n", argv[1]);
    fflush(stdout);
    return 2;
  }
  printf("Ready to read \"%s\"\n", argv[1]);
  fflush(stdout);

  // Do something to get data from the file ...

  // And close it
  if (fclose(filetoopen) != 0) {
    printf("Error: Failed to close \"%s\".\n", argv[1]);
    fflush(stdout);
    return 3;
  }
  printf("File %s is now closed.\n", argv[1]);
  fflush(stdout);

  // Do other things ...

  printf("All set. Bye!\n");
  fflush(stdout);
  return 0;
}

