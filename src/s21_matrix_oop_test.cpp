#include "s21_matrix_oop.h"

#include <gtest/gtest.h>

using namespace std;

TEST(TestGroupName, test_1) {
  S21Matrix matrix;
  EXPECT_EQ(matrix.get_cols(), kDefaultMatrixCols);
  EXPECT_EQ(matrix.get_rows(), kDefaultMatrixRows);
  EXPECT_EQ(matrix(0, 0), 0);
}

TEST(TestGroupName, test_2) { EXPECT_ANY_THROW(S21Matrix matrix(0, 5)); }

TEST(TestGroupName, test_3) {
  int rows = 5;
  int cols = 9;
  S21Matrix matrix(rows, cols);
  EXPECT_EQ(matrix.get_cols(), cols);
  EXPECT_EQ(matrix.get_rows(), rows);
  EXPECT_EQ(matrix(3, 2), 0);
}

TEST(TestGroupName, test_4) {
  int rows = 5;
  int cols = 9;
  S21Matrix matrix(rows, cols);
  matrix.~S21Matrix();
  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(matrix.get_rows(), 0);
}

TEST(TestGroupName, test_5) {
  S21Matrix matrix(3, 3);
  double value_buf[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_clone(matrix);
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(matrix(i, j), matrix_clone(i, j));
    }
  }
}

TEST(TestGroupName, test_6) {
  S21Matrix matrix(3, 3);
  double value_buf[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_clone(matrix);
  EXPECT_EQ(matrix.get_cols(), matrix_clone.get_cols());
  EXPECT_EQ(matrix.get_rows(), matrix_clone.get_rows());
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(matrix(i, j), matrix_clone(i, j));
    }
  }
}

TEST(TestGroupName, test_7) {
  S21Matrix matrix(3, 3);
  double value_buf[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = value_buf[z];
      z++;
    }
  }
  z = 0;
  S21Matrix matrix_clone = move(matrix);
  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(matrix.get_rows(), 0);
  for (int i = 0; i < matrix_clone.get_rows(); i++) {
    for (int j = 0; j < matrix_clone.get_cols(); j++) {
      EXPECT_EQ(value_buf[z], matrix_clone(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_8) {
  S21Matrix matrix_1(3, 3);
  double value_buf[9] = {1.1561316196, 2.984136416, 3.98136516,
                         4.06319,      5.491605165, 6.0655,
                         7.029002,     8.9813,      9.6134965187};
  int z = 0;
  for (int i = 0; i < matrix_1.get_rows(); i++) {
    for (int j = 0; j < matrix_1.get_cols(); j++) {
      matrix_1(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_2(matrix_1);
  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), true);
}

TEST(TestGroupName, test_9) {
  S21Matrix matrix_1(3, 3);
  double value_buf[9] = {1.1561316196, 2.984136416, 3.98136516,
                         4.06319,      5.491605165, 6.0655,
                         7.029002,     8.9813,      9.6134965187};
  int z = 0;
  for (int i = 0; i < matrix_1.get_rows(); i++) {
    for (int j = 0; j < matrix_1.get_cols(); j++) {
      matrix_1(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_2(matrix_1);
  matrix_2(2, 2) = 1;
  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), false);
}

TEST(TestGroupName, test_10) {
  S21Matrix matrix_1(3, 3);
  double value_buf[9] = {1.1561316196, 2.984136416, 3.98136516,
                         4.06319,      5.491605165, 6.0655,
                         7.029002,     8.9813,      9.6134965187};
  int z = 0;
  for (int i = 0; i < matrix_1.get_rows(); i++) {
    for (int j = 0; j < matrix_1.get_cols(); j++) {
      matrix_1(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_2(matrix_1);
  matrix_2(0, 0) = 1.15613168;
  EXPECT_EQ(matrix_1.EqMatrix(matrix_2), true);
}

TEST(TestGroupName, test_11) {
  S21Matrix matrix_1(3, 3);
  double value_buf[9] = {1.1561316196, 2.984136416, 3.98136516,
                         4.06319,      5.491605165, 6.0655,
                         7.029002,     8.9813,      9.6134965187};
  int z = 0;
  for (int i = 0; i < matrix_1.get_rows(); i++) {
    for (int j = 0; j < matrix_1.get_cols(); j++) {
      matrix_1(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_2(matrix_1);
  matrix_2(0, 0) = 1.15613168;
  EXPECT_EQ(matrix_1 == matrix_2, true);
}

TEST(TestGroupName, test_12) {
  S21Matrix matrix_1(3, 3);
  double value_buf[9] = {1.1561316196, 2.984136416, 3.98136516,
                         4.06319,      5.491605165, 6.0655,
                         7.029002,     8.9813,      9.6134965187};
  int z = 0;
  for (int i = 0; i < matrix_1.get_rows(); i++) {
    for (int j = 0; j < matrix_1.get_cols(); j++) {
      matrix_1(i, j) = value_buf[z];
      z++;
    }
  }
  S21Matrix matrix_2;
  EXPECT_EQ(matrix_1 == matrix_2, false);
}

TEST(TestGroupName, test_13) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix res(3, 3);

  double A_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                           5.25, 6.25, 7.25, 8.25};
  double B_value_buf[9] = {9.25, 8.25, 7.25, 6.25, 5.25,
                           4.25, 3.25, 2.25, 1.25};
  double res_value_buf[9] = {17.4375, 13.6875,  9.9375,   73.6875, 60.9375,
                             48.1875, 129.9375, 108.1875, 86.4375};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      B(i, j) = B_value_buf[n];
      res(i, j) = res_value_buf[n];
      n++;
    }
  }
  A.MulMatrix(B);
  EXPECT_EQ(A == res, true);
}

TEST(TestGroupName, test_14) {
  S21Matrix A(4, 5);
  S21Matrix B(3, 3);
  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(TestGroupName, test_15) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix res(3, 3);
  double A_value_buf[9] = {0, 1, 3, 4, 6, 7};
  double B_value_buf[9] = {9, 8, 7, 6, 5, 4};
  double res_value_buf[9] = {6, 5, 4, 51, 44, 37, 96, 83, 70};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  n = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      B(i, j) = B_value_buf[n];
      n++;
    }
  }
  n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res(i, j) = res_value_buf[n];
      n++;
    }
  }
  A *= B;
  EXPECT_EQ(A == res, true);
}

TEST(TestGroupName, test_16) {
  S21Matrix A(3, 2);
  S21Matrix B(4, 5);
  EXPECT_ANY_THROW(A *= B);
}

TEST(TestGroupName, test_17) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix res(3, 3);
  double A_value_buf[9] = {0, 1, 3, 4, 6, 7};
  double B_value_buf[9] = {9, 8, 7, 6, 5, 4};
  double res_value_buf[9] = {6, 5, 4, 51, 44, 37, 96, 83, 70};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  n = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      B(i, j) = B_value_buf[n];
      n++;
    }
  }
  n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      res(i, j) = res_value_buf[n];
      n++;
    }
  }
  S21Matrix C = A * B;
  EXPECT_EQ(C == res, true);
}

TEST(TestGroupName, test_18) {
  S21Matrix A(3, 2);
  S21Matrix B(4, 5);
  EXPECT_ANY_THROW(S21Matrix C = A * B);
}

TEST(TestGroupName, test_19) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double A_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                           5.25, 6.25, 7.25, 8.25};
  double res_value_buf[9] = {0.25, 3.25, 6.25, 1.25, 4.25,
                             7.25, 2.25, 5.25, 8.25};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      res(i, j) = res_value_buf[n];
      n++;
    }
  }
  A = A.Transpose();
  EXPECT_EQ(A == res, true);
}

TEST(TestGroupName, test_20) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double value_buf[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double res_buf[9] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = value_buf[z];
      matrix2(i, j) = value_buf[z];
      z++;
    }
  }
  matrix.SumMatrix(matrix2);
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_21) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double matrix1_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                 5.25, 6.25, 7.25, 8.25};
  double matrix2_value_buf[9] = {9.65, 8.65, 7.65, 6.65, 5.65,
                                 4.65, 3.65, 2.65, 1.65};
  double res_buf[9] = {9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix1_value_buf[z];
      matrix2(i, j) = matrix2_value_buf[z];
      z++;
    }
  }
  S21Matrix res = matrix2 + matrix;
  z = 0;
  for (int i = 0; i < res.get_rows(); i++) {
    for (int j = 0; j < res.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], res(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_22) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double matrix1_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                 5.25, 6.25, 7.25, 8.25};
  double matrix2_value_buf[9] = {9.65, 8.65, 7.65, 6.65, 5.65,
                                 4.65, 3.65, 2.65, 1.65};
  double res_buf[9] = {9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9, 9.9};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix1_value_buf[z];
      matrix2(i, j) = matrix2_value_buf[z];
      z++;
    }
  }
  matrix += matrix2;
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_23) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix2(3, 9);
  EXPECT_ANY_THROW(matrix += matrix2);
}

TEST(TestGroupName, test_24) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix2(3, 9);
  EXPECT_ANY_THROW(S21Matrix res = matrix + matrix2);
}

TEST(TestGroupName, test_25) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double matrix1_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                 5.25, 6.25, 7.25, 8.25};
  double matrix2_value_buf[9] = {9.25, 8.25, 7.25, 6.25, 5.25,
                                 4.25, 3.25, 2.25, 1.25};
  double res_buf[9] = {-9, -7, -5, -3, -1, 1, 3, 5, 7};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix1_value_buf[z];
      matrix2(i, j) = matrix2_value_buf[z];
      z++;
    }
  }
  matrix -= matrix2;
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_26) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double matrix1_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                 5.25, 6.25, 7.25, 8.25};
  double matrix2_value_buf[9] = {9.25, 8.25, 7.25, 6.25, 5.25,
                                 4.25, 3.25, 2.25, 1.25};
  double res_buf[9] = {-9, -7, -5, -3, -1, 1, 3, 5, 7};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix1_value_buf[z];
      matrix2(i, j) = matrix2_value_buf[z];
      z++;
    }
  }
  S21Matrix res = matrix - matrix2;
  z = 0;
  for (int i = 0; i < res.get_rows(); i++) {
    for (int j = 0; j < res.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], res(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_27) {
  S21Matrix matrix(3, 3);
  S21Matrix matrix2(3, 3);
  double matrix1_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                 5.25, 6.25, 7.25, 8.25};
  double matrix2_value_buf[9] = {9.25, 8.25, 7.25, 6.25, 5.25,
                                 4.25, 3.25, 2.25, 1.25};
  double res_buf[9] = {-9, -7, -5, -3, -1, 1, 3, 5, 7};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix1_value_buf[z];
      matrix2(i, j) = matrix2_value_buf[z];
      z++;
    }
  }
  matrix.SubMatrix(matrix2);
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_28) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix2(3, 9);
  EXPECT_ANY_THROW(S21Matrix res = matrix - matrix2);
}

TEST(TestGroupName, test_29) {
  S21Matrix matrix(4, 3);
  S21Matrix matrix2(3, 9);
  EXPECT_ANY_THROW(matrix -= matrix2);
}

TEST(TestGroupName, test_30) {
  S21Matrix matrix(3, 3);
  double matrix_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                5.25, 6.25, 7.25, 8.25};
  double res_buf[9] = {1, 5, 9, 13, 17, 21, 25, 29, 33};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix_value_buf[z];
      z++;
    }
  }
  S21Matrix res = matrix * 4;
  z = 0;
  for (int i = 0; i < res.get_rows(); i++) {
    for (int j = 0; j < res.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], res(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_31) {
  S21Matrix matrix(3, 3);
  double matrix_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                5.25, 6.25, 7.25, 8.25};
  double res_buf[9] = {1, 5, 9, 13, 17, 21, 25, 29, 33};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix_value_buf[z];
      z++;
    }
  }
  matrix.MulNumber(4);
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_32) {
  S21Matrix matrix(3, 3);
  double matrix_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                                5.25, 6.25, 7.25, 8.25};
  double res_buf[9] = {1, 5, 9, 13, 17, 21, 25, 29, 33};
  int z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      matrix(i, j) = matrix_value_buf[z];
      z++;
    }
  }
  matrix *= 4;
  z = 0;
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      EXPECT_EQ(res_buf[z], matrix(i, j));
      z++;
    }
  }
}

TEST(TestGroupName, test_33) {
  S21Matrix A(3, 3);
  S21Matrix res(3, 3);
  double A_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 4.25,
                           5.25, 6.25, 7.25, 8.25};
  double res_value_buf[9] = {0.25, 3.25, 6.25, 1.25, 4.25,
                             7.25, 2.25, 5.25, 8.25};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      res(i, j) = res_value_buf[n];
      n++;
    }
  }
  A = A.Transpose();
  EXPECT_EQ(A == res, true);
}

TEST(TestGroupName, test_34) {
  S21Matrix A(1, 1);
  double res = 1.25;
  A(0, 0) = 1.25;
  double my_res = A.Determinant();
  EXPECT_EQ(my_res, res);
}

TEST(TestGroupName, test_35) {
  S21Matrix A(3, 3);
  double res = -69;
  double A_value_buf[9] = {0.25, 1.25, 2.25, 3.25, 10, 5.25, 6.25, 7.25, 8.25};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  double my_res = A.Determinant();
  EXPECT_EQ(my_res, res);
}

TEST(TestGroupName, test_36) {
  S21Matrix A(3, 4);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(TestGroupName, test_37) {
  S21Matrix A(3, 3);
  S21Matrix Res(3, 3);
  double A_value_buf[9] = {5, -1, 1, 2, 3, 4, 1, 0, 3};
  double Res_value_buf[9] = {9, -2, -3, 3, 14, -1, -7, -18, 17};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      Res(i, j) = Res_value_buf[n];
      n++;
    }
  }
  S21Matrix MyRes = A.CalcComplements();
  EXPECT_EQ(MyRes == Res, true);
}

TEST(TestGroupName, test_38) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);
  A(0, 0) = 5;
  B(0, 0) = 1;
  A = A.CalcComplements();
  EXPECT_EQ(A == B, true);
}

TEST(TestGroupName, test_39) {
  S21Matrix A(1, 8);
  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(TestGroupName, test_40) {
  S21Matrix A(3, 3);
  S21Matrix Res(3, 3);
  double A_value_buf[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double Res_value_buf[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      Res(i, j) = Res_value_buf[n];
      n++;
    }
  }
  S21Matrix MyRes = A.InverseMatrix();
  EXPECT_EQ(MyRes == Res, true);
}

TEST(TestGroupName, test_41) {
  S21Matrix A(3, 1);
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(TestGroupName, test_42) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A(8, 2) = 9);
}

TEST(TestGroupName, test_43) {
  S21Matrix A(3, 3);
  double A_value_buf[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double res_buf[6] = {2, 5, 6, 3, 5, -2};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  A.set_cols(2);
  n = 0;
  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      EXPECT_EQ(A(i, j), res_buf[n]);
      n++;
    }
  }
}

TEST(TestGroupName, test_44) {
  S21Matrix A(3, 3);
  double A_value_buf[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double res_buf[15] = {2, 5, 7, 0, 0, 6, 3, 4, 0, 0, 5, -2, -3, 0, 0};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  A.set_cols(5);
  n = 0;
  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      EXPECT_EQ(A(i, j), res_buf[n]);
      n++;
    }
  }
}

TEST(TestGroupName, test_45) {
  S21Matrix A(3, 3);
  double A_value_buf[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double res_buf[15] = {2, 5, 7, 6, 3, 4, 5, -2, -3, 0, 0, 0, 0, 0, 0};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  A.set_rows(5);
  n = 0;
  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      EXPECT_EQ(A(i, j), res_buf[n]);
      n++;
    }
  }
}

TEST(TestGroupName, test_46) {
  S21Matrix A(3, 3);
  double A_value_buf[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double res_buf[6] = {2, 5, 7, 6, 3, 4};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  A.set_rows(2);
  n = 0;
  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      EXPECT_EQ(A(i, j), res_buf[n]);
      n++;
    }
  }
}

TEST(TestGroupName, test_47) {
  S21Matrix A(3, 3);
  S21Matrix Res(3, 3);
  double A_value_buf[9] = {2, 5, 7, 2, 5, 7, 5, -2, -3};
  int n = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A(i, j) = A_value_buf[n];
      n++;
    }
  }
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(TestGroupName, test_48) {
  S21Matrix A(3, 3);
  EXPECT_EQ(A.get_cols(), 3);
}

TEST(TestGroupName, test_49) {
  S21Matrix A(3, 3);
  EXPECT_EQ(A.get_rows(), 3);
}

TEST(TestGroupName, test_50) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A.set_rows(-1));
}

TEST(TestGroupName, test_51) {
  S21Matrix A(3, 3);
  EXPECT_ANY_THROW(A.set_cols(0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}