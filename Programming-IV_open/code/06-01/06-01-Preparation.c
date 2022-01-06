// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/12/02a kameda[at]iit.tsukuba.ac.jp
// 06.01. はじめてのOpenGL - プログラムの枠だけ -

#include <stdio.h> // printf()
#include <GL/glut.h> // gl*(), glut*()

// +----------------------------------------------------
// OpenGLとしてのWindowの初期化
// +----------------------------------------------------
void ic2_BootWindow (char winname[]) {

  // DisplayModeの設定(それぞれを|で繋ぐ)
  //   GLUT_DOUBLE ... ダブルバッファ
  //   GLUT_RGB    ... RGB表色モード
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 

  // 準備(Initialization)が済んだらウィンドウを開く
  glutCreateWindow(winname);

  // ウィンドウ全体を書き直すときの色(R,G,B,0) ここでは黒
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// +----------------------------------------------------
// Main Function
// +----------------------------------------------------
int main (int argc, char *argv[]) {

  // glutライブラリによる引数の解釈
  glutInit(&argc, argv);

  // OpenGL Window の初期化
  ic2_BootWindow(argv[0]);

  // 無限ループの開始
  glutMainLoop();
  
  return 0;
}
