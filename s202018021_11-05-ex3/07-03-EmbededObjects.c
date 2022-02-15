// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.03. ファイル分割に伴う修正

#include "./ic2-CommonHeaders.h"


// *********************************************************************** 
// EmbededObjects ********************************************************

// +++--------------------------------------------------
// ソース内部でのCG物体の直接描画
// +++--------------------------------------------------

// +----------------------------------------------------
// OpenGL Logoを描く
// +----------------------------------------------------
// s はスケーリングファクタ（s=1.0 で 概ね -1.0 〜 1.0 の大きさ）
void ic2_OpenGLLogo (float s) {
// 光源によるシェーディング効果を切る（と色の指定が直接色になる）
  glDisable(GL_LIGHTING);   

  // 線の幅（画素単位）
  glLineWidth(1.0);

  // (R, G, B) 値域は 0.0 - 1.0
  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_LINES); 
  glVertex3f(s * -0.8, s * 0.8 , 0.0); glVertex3f(s * 0.8, s * 0.8, 0.0); // O
  glVertex3f(s * 0.8, s * 0.8 , 0.0); glVertex3f(s * -0.8, s * -0.8, 0.0); // O
  glVertex3f(s * -0.8, s * -0.8 , 0.0); glVertex3f(s * 0.8, s * -0.8, 0.0); // O
  glEnd();

  // glBegin(GL_LINE_LOOP); から glEnd(); までの間は、
  // 全ての頂点を使った閉じた線分が描画される

}

