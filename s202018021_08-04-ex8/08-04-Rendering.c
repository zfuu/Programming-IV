// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/09a kameda[at]iit.tsukuba.ac.jp
// 08.03. OpenGLでの行列操作の実際

#include "./ic2-CommonHeaders.h"


// *********************************************************************** 
// Rendering *************************************************************

// +++--------------------------------------------------
// スクリーンに描画する
// +++--------------------------------------------------

// +----------------------------------------------------
// １フレーム分の描画
// +----------------------------------------------------
void ic2_DrawFrame (void) {

  static int loopmax = 360; // loopmax回ごとに１回色を変える
  static int loopcounter = 0; // 何回目かを覚えておく変数

  if (loopcounter == loopmax) {
    loopcounter = 0;
  }
  // (1) 描画バッファの初期化
  // 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT);

  // (2) カメラの設定
  ic2_SetUpCamera_Ortho();

  // (3) 光源の設置

  // (4) 物体の描画

  ic2_ShowMATRIX ("Before");
  glMatrixMode(GL_MODELVIEW);
  //-- 【TR】実装ここから
  glLoadIdentity(); ic2_ShowMATRIX ("After I is loaded");  
  glRotatef(loopcounter, 0, 0, 1); ic2_ShowMATRIX ("After +45 degree rotation around Z axis");  
  glTranslatef(0.9, 0, 0); ic2_ShowMATRIX ("After +0.7 along X axis");

  //-- 【TR】実装ここまで
  ic2_OpenGLLogo(logoscale);

  // (5) 描画バッファの切替
  glutSwapBuffers();

  loopcounter++;

}

