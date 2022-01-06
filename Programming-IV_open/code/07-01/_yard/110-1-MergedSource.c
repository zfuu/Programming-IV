// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]

// 2011/11/07 kameda[at]iit.tsukuba.ac.jp
// 10.1 モデル読み込みとCG表示の統合

#include <stdio.h>
#include <stdlib.h> // exit(), calloc()
#include <GL/glut.h>

// *********************************************************************** 
// global variables ******************************************************

// +----------------------------------------------------
// Global Variables
// +----------------------------------------------------

// Windowサイズ
int window_w = 400;
int window_h = 400;

// 直交投影時のスケールファクタ [pixel / unit_of_imager]
// ここでは正規化カメラの撮像面での 1.0 単位を 200画素に相当させる
float ortho_unit = 200.0; 

// WindowのID（描画管理用）
int window_id = -1;

// *********************************************************************** 
// read model ************************************************************

// +----------------------------------------------------
// １つの点のための構造体
// +----------------------------------------------------
struct ic2POINT {
  float x;
  float y;
  float z;
};

// +----------------------------------------------------
// １つの色のための構造体
// +----------------------------------------------------
struct ic2COLOR {
  float r;
  float g;
  float b;
};

// +----------------------------------------------------
// １つの三角形パッチのための構造体
// 次の三角形パッチへのポインタを持つ。
// v(st) × v(su) [外積]がこの面の法線ベクトルを成す(右ネジ式)
// +----------------------------------------------------
struct ic2PATCH {
  struct ic2POINT s;     // 頂点s
  struct ic2POINT t;     // 頂点t
  struct ic2POINT u;     // 頂点u
  struct ic2COLOR c;     // 色の強度 (通常は0.0 - 1.0)
  struct ic2PATCH *next; // 次の三角形パッチへのポインタ
};

// +++--------------------------------------------------
// 新しい三角形パッチ構造体(ic2PATCH)のメモリ確保と初期化
// +++--------------------------------------------------
static struct ic2PATCH *ic2_NewPATCH (void) {
  struct ic2PATCH *newpatch = NULL;

  newpatch = (struct ic2PATCH *)calloc(1, sizeof(struct ic2PATCH));
  return (newpatch);
}

// +++--------------------------------------------------
// 三角形パッチ構造体(ic2PATCH)１つ分の読み込み
// +++--------------------------------------------------
static int ic2_InsertPATCH (struct ic2PATCH **firstpatchptr, char *onelinedata) {
  // (1) 文字列へのポインタは存在するか
  // (2) メモリ確保/下請け
  // (3) 値の読み込み
  // (4) ic2PATCHリスト構造への組み込み
  struct ic2PATCH *newpatch = NULL; // 三角形パッチ構造体ヘのポインタ
  int number_of_element = 0;        // 読み込めた項目数

  // (1) 文字列へのポインタは存在するか
  if (onelinedata == NULL) return 1;

  // (2) メモリ確保/下請け
  if ((newpatch = ic2_NewPATCH()) == NULL) {
    printf("ic2_InsertPATCH: Memory allocation failed.\n");
    return 2;
  }

  // (3) 値の読み込み
  number_of_element = 
    sscanf(onelinedata, "%f %f %f  %f %f %f  %f %f %f  %f %f %f", 
	   &newpatch->s.x, &newpatch->s.y, &newpatch->s.z,
	   &newpatch->t.x, &newpatch->t.y, &newpatch->t.z,
	   &newpatch->u.x, &newpatch->u.y, &newpatch->u.z,
	   &newpatch->c.r, &newpatch->c.g, &newpatch->c.b);
  if (number_of_element != 12) {
    printf("ic2_InsertPATCH: format error (%d elements found)\n", number_of_element);
    printf("ic2_InsertPATCH: \"%s\"\n", onelinedata);
    free(newpatch);
    return 3;
  }

  // (4) ic2PATCHリスト構造への組み込み
  // *newpatch を 三角形パッチ集合の先頭に挿入
  newpatch->next = *firstpatchptr;
  *firstpatchptr = newpatch;
  return 0;
}

// +----------------------------------------------------
// モデルのファイルからの読込
// +----------------------------------------------------
// 返値：負 ... エラー
// 返値：０ないし正値 ... 読み込みに成功したパッチ数
int ic2_ReadModel(char *filename, struct ic2PATCH **firstpatchptr) {
  FILE *filetoopen = NULL; // A pointer to FILE structure
  char oneline[256]; // １行分のバッファ,固定長にしておくとsizeof()が利用可能
  char firstword[256]; // コメント行かどうかの判定用
  int  linenumber = 0; // ファイル中の行番号
  int  patchnumber = 0; // パッチ数

  // We need at least one option to indicate a file to open
  if (filename == NULL) { 
    printf("Error: You need to specify a one file to open.\n");
    return -1;
  }

  // Try to open it
  filetoopen = fopen(filename, "r");
  if (filetoopen == NULL) {
    printf("Error: Failed to open/read \"%s\".\n", filename);
    return -2;
  }
  printf("Reading model from \"%s\"\n", filename);

  // １行ずつ読込
  while (fgets(oneline, sizeof(oneline), filetoopen) != NULL) {
    linenumber++;

    // もし行内に１文字もなければ（１単語もなければ）次行へ
    if (sscanf(oneline, "%256s", firstword) < 1)
      continue;
    // もし先頭が#で始まっていれば次行へ
    if (firstword[0] == '#') 
      continue;
    // 他のエラートラップ
    if (0) {
      printf("Skip(line=%d): %s\n", linenumber, oneline);
      continue;
    }

    if (ic2_InsertPATCH(firstpatchptr, oneline)) {
      printf("Model reading is interrupted.\n");
      break;
    }
    patchnumber++;
  }

  // And close it
  if (fclose(filetoopen) != 0) {
    printf("Error: Failed to close \"%s\".\n", filename);
    // error, but we get data anyway...
  }

  printf("Finish reading the model (%d patches).\n", patchnumber);
  return patchnumber;
}

// -----------------------------------------------------
// 三角形パッチ構造体(ic2PATCH)リストの表示
// -----------------------------------------------------
int ic2_PrintPATCHList (struct ic2PATCH *firstpatchptr) {
  struct ic2PATCH *p;
  int np = 0;

  for (p = firstpatchptr; p != NULL; p = p->next) {
    np++;
    printf("PATCH: (%g, %g, %g), (%g, %g, %g), (%g, %g, %g), rgb=[%g, %g, %g]\n",
	   p->s.x, p->s.y, p->s.z,
	   p->t.x, p->t.y, p->t.z,
	   p->u.x, p->u.y, p->u.z,
	   p->c.r, p->c.g, p->c.b);
  }

  return np;
}

// *********************************************************************** 
// gl utilitiess *********************************************************

// +----------------------------------------------------
// MODELVIEW Matrix と PROJECTION を表示する
// +----------------------------------------------------
void ic2_ShowMATRIX (char *str) {
  GLfloat m[16]; // GL_MODELVIEW matrix
  GLfloat p[16]; // GL_PROJECTION matrix

  glGetFloatv(GL_MODELVIEW_MATRIX , m);  // MODELVIEWのスタックトップmatrixをmにコピー
  glGetFloatv(GL_PROJECTION_MATRIX, p); // PROJECTIONのスタックトップmatrixをpにコピー
  if (str != NULL) printf("<< %s >>\n", str);
  printf("MODELVIEW Matrix                        PROJECTION Matrix\n");
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n",
          m[ 0], m[ 4], m[ 8], m[12],     p[ 0], p[ 4], p[ 8], p[12]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 1], m[ 5], m[ 9], m[13],     p[ 1], p[ 5], p[ 9], p[13]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 2], m[ 6], m[10], m[14],     p[ 2], p[ 6], p[10], p[14]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 3], m[ 7], m[11], m[15],     p[ 3], p[ 7], p[11], p[15]);
}

// *********************************************************************** 
// objects_embeded *******************************************************

// +----------------------------------------------------
// 正方形を描く
// +----------------------------------------------------
void ic2_FigSquare (float s) {
  glDisable(GL_LIGHTING);   // 光源によるシェーディングを一旦切る

  // 正方形（Z=0の平面内、+/- 0.9)
  glBegin(GL_LINE_LOOP); {
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(s * -1, s * -1, 0.0);
    glVertex3f(s * +1, s * -1, 0.0);
    glVertex3f(s * +1, s * +1, 0.0);
    glVertex3f(s * -1, s * +1, 0.0);
  } glEnd();

  // ３軸
  glBegin(GL_LINES); {
    glColor3f(1.0, 0.5, 0.5); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.85, 0.0,  0.0); // X (red)
    glColor3f(0.5, 1.0, 0.5); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.0,  0.70, 0.0); // Y (green)
    glColor3f(0.5, 0.5, 1.0); glVertex3f(0.0, 0.0, 0.0); glVertex3f(0.0,  0.0,  1.0); // Z (blue)
  } glEnd();

  glEnable(GL_LIGHTING);   // 光源によるシェーディングを開始する
}

// +----------------------------------------------------
// ティーポットを描く (glutの作り付け関数の１つ)
// +----------------------------------------------------
void ic2_FigSolidTeapot (float s) {
  GLfloat obj_ref[] = {1.0, 1.0, 0.3, 1.0}; // teapotの色情報 (DIFFUSE用)
  GLfloat obj_shn[] = {10.0};               // teapotの色情報 (SHININESS用)

  // 色の設定
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, obj_ref);
  glMaterialfv(GL_FRONT, GL_SHININESS, obj_shn);

  glutSolidTeapot(s);
}

// *********************************************************************** 
// lighting ************************************************************** 

// +----------------------------------------------------
// 光源を用意
// +----------------------------------------------------
//  X     Y     Z     Diff(R,G,B)   Spec(R,G,B)
//  1.0   2.0   3.0   0.2 0.2 0.2   0.4 0.4 0.4
// -1.0   2.0   3.0   0.4 0.4 0.4   0.4 0.4 0.4
//  0.0   4.0   0.0   1.0 1.0 1.0   1.0 1.0 1.0
void ic2_LightSetA (void) {
  static int initflag = 0;

  if (initflag == 0) {
    glEnable(GL_DEPTH_TEST); // デプスバッファによる描画を行う
    glEnable(GL_NORMALIZE);  // 法線ベクトルを常に正規化して解釈させる
    glEnable(GL_LIGHTING);   // 光源によるシェーディングを開始する
    glEnable(GL_LIGHT0);     // LIGHT0 を利用
    glEnable(GL_LIGHT1);     // LIGHT1 を利用
    glEnable(GL_LIGHT2);     // LIGHT2 を利用
    initflag = 1;
  }
  
  GLfloat val[4];

  val[0] =  1.0; val[1] =  2.0; val[2] =  3.0; val[3] = 1.0; glLightfv(GL_LIGHT0, GL_POSITION, val);
  val[0] =  0.2; val[1] =  0.2; val[2] =  0.2; val[3] = 1.0; glLightfv(GL_LIGHT0, GL_DIFFUSE,  val);
  val[0] =  0.4; val[1] =  0.4; val[2] =  0.4; val[3] = 1.0; glLightfv(GL_LIGHT0, GL_SPECULAR, val);

  val[0] = -1.0; val[1] =  2.0; val[2] =  3.0; val[3] = 1.0; glLightfv(GL_LIGHT1, GL_POSITION, val);
  val[0] =  0.4; val[1] =  0.4; val[2] =  0.4; val[3] = 1.0; glLightfv(GL_LIGHT1, GL_DIFFUSE,  val);
  val[0] =  0.4; val[1] =  0.4; val[2] =  0.4; val[3] = 1.0; glLightfv(GL_LIGHT1, GL_SPECULAR, val);

  val[0] =  0.0; val[1] =  4.0; val[2] =  0.0; val[3] = 1.0; glLightfv(GL_LIGHT2, GL_POSITION, val);
  val[0] =  1.0; val[1] =  1.0; val[2] =  1.0; val[3] = 1.0; glLightfv(GL_LIGHT2, GL_DIFFUSE,  val);
  val[0] =  1.0; val[1] =  1.0; val[2] =  1.0; val[3] = 1.0; glLightfv(GL_LIGHT2, GL_SPECULAR, val);
}

// *********************************************************************** 
// camera work ***********************************************************

// +----------------------------------------------------
// カメラの投影行列を設定
// +----------------------------------------------------
// 利用する大域変数： window_w, window_h
// window_w/window_hの変化に対して、物体の見かけの大きさが変わらないように描画
// → ortho_unit が重要！
//
void ic2_SetUpCamera_Ortho (void) {
  float wlimit, hlimit;
  wlimit = (window_w/2) / ortho_unit; 
  hlimit = (window_h/2) / ortho_unit; 

  // glOrtho(左端, 右端, 下端, 上端, 近接側クリッピング面,  遠方側クリッピング面)
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); // 毎フレーム再設定するのでPROJECTION行列スタックトップの初期化が必要に
  glOrtho(-wlimit, wlimit, -hlimit, hlimit, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

// *********************************************************************** 
// rendering *************************************************************

// +----------------------------------------------------
// スクリーンに描画する
// +----------------------------------------------------
void ic2_DrawFrame (void) {

  // (前処理) 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  // (前処理) 今回CGを描画する範囲
  glViewport(0, 0, window_w, window_h);

  // (1) カメラの設置
  ic2_SetUpCamera_Ortho();

  // (2) 光源の設置
  ic2_LightSetA();

  // (3) 物体の設置
  // 物体描画:正方形
  ic2_FigSquare(0.9);
  // 物体描画:ティーポット
  ic2_FigSolidTeapot(0.5);

  // (後処理) スクリーンの切り替え
  glutSwapBuffers();

}

// *********************************************************************** 
// callbacks ************************************************************* 

// +----------------------------------------------------
// キーが何か押されたときの対策用関数 
// +----------------------------------------------------
// glutKeyboardFunc()にて登録予定
// 引数 : key ... 入力文字 
// 引数 : x   ... 文字が押されたときのマウスカーソルのＸ位置 
// 引数 : y   ... 文字が押されたときのマウスカーソルのＹ位置 
void ic2_NormalKeyInput (unsigned char key, int x, int y) {
  float delta_t = 0.1; // [unit]
  float delta_r = 1.0; // [degree]

  switch (key) {
  case 'q' :
  case 'Q' :
  case 27 : // ESCキーのこと
    exit (0);
    break;

  // Translation -_+ : [X]h_l [Y]n_u [Z]j_k
  case 'h': glTranslatef(delta_t * -1, 0, 0); break;
  case 'l': glTranslatef(delta_t * +1, 0, 0); break;
  case 'n': glTranslatef(0, delta_t * -1, 0); break;
  case 'u': glTranslatef(0, delta_t * +1, 0); break;
  case 'j': glTranslatef(0, 0, delta_t * -1); break;
  case 'k': glTranslatef(0, 0, delta_t * +1); break;

  // Rotation -_+ : [Y]a_f [Z]s_d [X]x_w
  case 'x': glRotatef(delta_r * -1, 1, 0, 0); break;
  case 'w': glRotatef(delta_r * +1, 1, 0, 0); break;
  case 'a': glRotatef(delta_r * -1, 0, 1, 0); break;
  case 'f': glRotatef(delta_r * +1, 0, 1, 0); break;
  case 's': glRotatef(delta_r * -1, 0, 0, 1); break;
  case 'd': glRotatef(delta_r * +1, 0, 0, 1); break;

  // [Scale] v_b
  case 'v': glScalef(0.95, 0.95, 0.95); break;
  case 'b': glScalef(1.05, 1.05, 1.05); break;

  // [Reset] 
  case 'R': 
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix(); // 保護されてた第１階層に降りる
    glPushMatrix(); // 保護されてた第１階層からコピーしてスタックトップを１つ上げる
    break;

  // [Show Stacktop MODELVIEW Matrix]
  case 'p':
    ic2_ShowMATRIX("Current status");
    break;

  }

  // 次のメインループ(glutMainLoop)での繰り返し時に描画を要求
  glutPostWindowRedisplay(window_id);
}

// +----------------------------------------------------
// ウィンドウサイズの変更が生じたときの対策用関数
// +----------------------------------------------------
// glutReshapeFunc()にて登録
void ic2_ReshapeWindow (int w, int h) {

  // 新しいウィンドウサイズを大域変数にセット
  window_w = w; window_h = h;

  // 次のメインループ(glutMainLoop)での繰り返し時に描画を要求
  glutPostWindowRedisplay(window_id);
}

// +----------------------------------------------------
// OpenGLとしてのWindowの初期化
// +----------------------------------------------------
void ic2_BootWindow (char winname[]) {

  // ダブルバッファ,RGB表色モード,デプスバッファ を利用
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 

  // ウィンドウの大きさ
  glutInitWindowSize(window_w, window_h);

  // ウィンドウを開く
  window_id = glutCreateWindow(winname);

  // レンダリングにはSmooth Shadingを採用
  glShadeModel(GL_SMOOTH);

  // ウィンドウ全体を書き直すときの色(ここでは黒)
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // 初期MODELVIEW matrixの保護
  glMatrixMode(GL_MODELVIEW); 
  glPushMatrix(); // 以後本プログラムでは GL_MODELVIEW スタックの２層目以上で作業

  // Callback関数を設定 (イベント処理)
  glutIdleFunc(ic2_DrawFrame); // 暇だったらフレームを描く(よい実装ではない)
  glutKeyboardFunc(ic2_NormalKeyInput); // キーが押されたときの対策
  glutReshapeFunc(ic2_ReshapeWindow); // ウィンドウサイズ変更が検知されたときの対策
}

// *********************************************************************** 
// main  *****************************************************************
// +----------------------------------------------------
// Main Function
// +----------------------------------------------------
int main (int argc, char *argv[]) {
  struct ic2PATCH *firstpatchptr = NULL;
  int numberpatches = 0;

  // model ファイルの読み込み
  if (argc <= 1) {
    printf("Error: no model file is specified.\n");
    return 1;
  }
  numberpatches = ic2_ReadModel(argv[1], &firstpatchptr);
  if (numberpatches < 0) {
    printf("Error: invalid model \"%s\", reading failed.\n", argv[1]);
    return 1;
  }
  printf("Number of Patches in the model = %d \n", numberpatches);

  // glutライブラリによる引数の解釈
  glutInit(&argc, argv);

  // OpenGL Window の初期化
  ic2_BootWindow(argv[0]);

  // 無限ループの開始
  glutMainLoop();
  
  return 0;
}
