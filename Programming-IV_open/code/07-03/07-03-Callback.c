// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.03. ファイル分割に伴う修正

#include "ic2-CommonHeaders.h"


// *********************************************************************** 
// Callback ************************************************************** 

// +++--------------------------------------------------
// GLUTでのイベント駆動型プログラミング
// +++--------------------------------------------------

// +----------------------------------------------------
// 「タイマー」で呼出し（繰り返すことで「一定間隔呼出し」化）
// +----------------------------------------------------
void ic2_timerhandler(int keynumber){
  glutPostRedisplay(); // OpenGLのmainloopに戻ったら再描画を頼む
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後にまた呼び出す
}

