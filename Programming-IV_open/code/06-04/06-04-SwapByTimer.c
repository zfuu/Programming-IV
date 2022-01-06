// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/12/02a kameda[at]iit.tsukuba.ac.jp
// 06.04. はじめてのOpenGL - バッファを時間で切り替え -

#include <stdio.h> // printf()
#include <GL/glut.h> // gl*(), glut*()

// +----------------------------------------------------
// １フレーム分の描画
// +----------------------------------------------------
void ic2_DrawFrame (void) {
  static int loopmax = 4; // loopmax回ごとに１回色を変える
  static int loopcounter = 0; // 何回目かを覚えておく変数

  // (0) 指定色の変更
  loopcounter++;
  if (loopcounter == loopmax) {
    glClearColor(0.0, 1.0, 0.0, 0.0); // ４回に１回は緑
    loopcounter = 0;
  } else {
    glClearColor(0.0, 0.0, 0.0, 0.0); // ４回に３回は黒
  }

  // (1) 描画バッファの初期化
  // 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT);

  // (2) カメラの設定
  // (3) 光源の設置
  // (4) 物体の描画

  // (5) 描画バッファの切替
  glutSwapBuffers();
}

// +----------------------------------------------------
// タイマーで呼出し（繰り返すことで「一定間隔呼出し」化）
// +----------------------------------------------------
void ic2_timerhandler(int keynumber){
  glutPostRedisplay(); // OpenGLのmainloopに戻ったら再描画を頼む
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後にまた呼び出す
}

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

  // Callback関数を設定 (イベント処理)
  glutDisplayFunc(ic2_DrawFrame); // フレームを（再）描画するために呼び出す関数
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後に呼び出す関数

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
