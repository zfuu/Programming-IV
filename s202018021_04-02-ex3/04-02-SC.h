// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.2. 簡易電卓・分割コンパイル版
// 共通ヘッダファイル

// 多重インクルードの阻止
// 万一このヘッダが複数回ソースに記述されてしまったときの対策(fool-proof)
#ifndef _04_2_SC_H    // もし _04_2_SC_H が未定義ならファイル末端の#endifまで展開
#define _04_2_SC_H 1  // ここで定義

float operation_plus(float v1, float v2) ;
float operation_minus(float v1, float v2) ;
float operation_mult(float v1, float v2) ;
float operation_div(float v1, float v2) ;


float operation_absdiff(float v1, float v2) ;

//These are the extra commands added for log and exp.
float operation_log(float v1, float v2) ;
float operation_exp(float v1, float v2) ;
// float operation_max(float v1, float v2) ;
// float operation_min(float v1, float v2) ;

#endif // _04_2_SC_H
