// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.03. ファイル分割に伴う修正

#include "ic2-CommonHeaders.h"

// *********************************************************************** 
// Initialization ******************************************************** 

// +++--------------------------------------------------
// 初期化（主にGLUT）
// +++--------------------------------------------------

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

