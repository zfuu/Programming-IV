// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/10/29a kameda[at]iit.tsukuba.ac.jp
// 06.08. はじめてのOpenGL - マイクロ秒オーダーの計測 -

#include <stdio.h> // printf()
#include <sys/time.h> // gettimeofday()

// +----------------------------------------------------
// meature time in micro seconds
// +----------------------------------------------------
int ic2_CountTime (void) {
  static struct timeval t0 = {0, 0}; // start of one period
  static struct timeval t1; // end of one period

  // measure and error check
  if (gettimeofday(&t1, NULL) != 0) {
    return -1;
  }

  if (t0.tv_sec != 0) {
    double d; // [ms]
    d = ((t1.tv_sec - t0.tv_sec) + ((t1.tv_usec - t0.tv_usec) / 1000000.0)) * 1000.0;
    printf("  %9.3f ms\n", d);
  }
  t0 = t1;

  return 0;
}

// +----------------------------------------------------
// Main Function
// +----------------------------------------------------
int main (int argc, char *argv[]) {
  int i;

  // 計測１箇所目
  ic2_CountTime();

  // Do something to measure ...
  for (i = 0; i < 30; i++) 
    printf("+");
  printf("\n");

  // 計測２箇所目
  ic2_CountTime();

  // Do something to measure ...
  for (i = 0; i < 60; i++) 
    printf("+");
  printf("\n");

  // 計測３箇所目
  ic2_CountTime();

  return 0;
}
