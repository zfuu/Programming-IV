// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/22a kameda[at]iit.tsukuba.ac.jp
// 02.2. ファイルの上品な開き方

#include <stdio.h>

void print_with_flush(char p[]){
  printf(p);
  fflush(stdout);
}

void print_with_flush_int(char p[], int num){
  printf(p, num);
  fflush(stdout);
}

void print_with_flush_string(char p[], char s[]){
  printf(p, s);
  fflush(stdout);
}



int main(int argc, char *argv[]){
  FILE *filetoopen = NULL; // A pointer to FILE structure

  // Show number of options at command line
  print_with_flush_int("Number of Options : %d\n", argc);

  // We need at least one option for a file name to open
  if (argc <= 1) { // What happens if you put other figure here?
    print_with_flush("Error: You need to specify a file to open.\n");
    return 1;
  }

  // Try to open it
  print_with_flush_string("Let's open \"%s\"! \n", argv[1]);
  filetoopen = fopen(argv[1], "r");
  if (filetoopen == NULL) {
    print_with_flush_string("Error: Failed to open/read \"%s\".\n", argv[1]);
    return 2;
  }
  print_with_flush_string("Ready to read \"%s\"\n", argv[1]);

  // Do something to get data from the file ...

  // And close it
  if (fclose(filetoopen) != 0) {
    print_with_flush_string("Error: Failed to close \"%s\".\n", argv[1]);
    return 3;
  }
  print_with_flush_string("File %s is now closed.\n", argv[1]);

  // Do other things ...

  print_with_flush("All set. Bye!\n");
  return 0;
}

