#ifndef __S21_MATRIX_OOP_H__
#define __S21_MATRIX_OOP_H__

#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>

const int kDefaultMatrixRows = 10;
const int kDefaultMatrixCols = 10;
const int kEPS = 7;

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

  void fill_matrix_by_zero();
  void eq_matrix_size(const S21Matrix &other);
  S21Matrix get_minor(int i, int j);

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();
  int get_rows() { return rows_; };
  int get_cols() { return cols_; };
  void set_rows(int rows);
  void set_cols(int cols);
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  bool operator==(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const double num);
  S21Matrix operator*(const S21Matrix &other);
  void operator=(const S21Matrix &other);
  void operator+=(const S21Matrix &other);
  void operator-=(const S21Matrix &other);
  void operator*=(const S21Matrix &other);
  void operator*=(const double num);
  double &operator()(int i, int j) const;
};

#endif
