// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2011/11/25a kameda[at]iit.tsukuba.ac.jp
// 04.2. 簡易電卓・分割コンパイル版
// 新しい演算に対応する関数

float operation_absdiff(float v1, float v2) {
  if (v1 > v2)
    return v1 - v2;
  return v2 - v1;
}

