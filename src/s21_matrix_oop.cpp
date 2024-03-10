#include "s21_matrix_oop.h"

using namespace std;

S21Matrix::S21Matrix() {
  rows_ = kDefaultMatrixRows;
  cols_ = kDefaultMatrixCols;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  S21Matrix::fill_matrix_by_zero();
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw "Number of rows and columns must be positive";
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  S21Matrix::fill_matrix_by_zero();
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    memcpy(matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
  }
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    memcpy(matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
  }
  other.~S21Matrix();
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  try {
    bool exit_code = true;
    this->eq_matrix_size(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) >
            pow(10, (-1) * kEPS)) {
          exit_code = false;
          break;
        }
      }
      if (exit_code == false) {
        break;
      }
    }
    return exit_code;
  } catch (...) {
    return false;
  }
}

bool S21Matrix::operator==(const S21Matrix &other) {
  bool res = this->EqMatrix(other);
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  try {
    this->eq_matrix_size(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
      }
    }
  } catch (...) {
    throw "Matrixes size is different";
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  try {
    S21Matrix res(*this);
    res.SumMatrix(other);
    return res;
  } catch (...) {
    throw "Matrixes size is different";
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  try {
    this->eq_matrix_size(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
      }
    }
  } catch (...) {
    throw "Matrixes size is different";
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  try {
    S21Matrix res(*this);
    res.SubMatrix(other);
    return res;
  } catch (...) {
    throw "Matrixes size is different";
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] * num;
    }
  }
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

void S21Matrix::operator=(const S21Matrix &other) {
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double *[rows_];
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[this->cols_];
    memcpy(this->matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->cols_ != other.rows_) {
    throw "The number of columns of the first matrix is not equal to the "
          "number of rows of the second matrix";
  }
  S21Matrix buf_res_matrix(this->rows_, other.cols_);
  for (int i = 0; i < buf_res_matrix.rows_; i++) {
    for (int j = 0; j < buf_res_matrix.cols_; j++) {
      buf_res_matrix.matrix_[i][j] = 0;
      for (int k = 0; k < this->cols_; k++) {
        buf_res_matrix.matrix_[i][j] +=
            this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = buf_res_matrix;
  buf_res_matrix.~S21Matrix();
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  if (this->cols_ != other.rows_) {
    throw "The number of columns of the first matrix is not equal to the "
          "number of rows of the second matrix";
  }
  S21Matrix res(this->rows_, other.cols_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      res.matrix_[i][j] = 0;
      for (int k = 0; k < this->cols_; k++) {
        res.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  return res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(this->cols_, this->rows_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      res.matrix_[i][j] = this->matrix_[j][i];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw "The matrix is not square";
  }
  S21Matrix res(this->rows_, this->cols_);
  if (this->rows_ == 1) {
    res.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        S21Matrix minor = this->get_minor(i, j);
        double buf = minor.Determinant();
        minor.~S21Matrix();
        res.matrix_[i][j] = buf * pow(-1.0, (i + j));
      }
    }
  }
  return res;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) {
    throw "The matrix is not square";
  }
  double res;

  if (this->rows_ == 1) {
    res = this->matrix_[0][0];
  } else if (this->rows_ == 2) {
    res = this->matrix_[0][0] * this->matrix_[1][1] -
          this->matrix_[1][0] * this->matrix_[0][1];
  } else {
    int sign = 1;
    double buf = 0.0;
    for (int i = 0; i < this->rows_; i++) {
      S21Matrix minor = this->get_minor(0, i);
      buf = minor.Determinant();
      res += this->matrix_[0][i] * sign * buf;
      sign = sign * (-1);
      minor.~S21Matrix();
    }
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->rows_ != this->cols_) {
    throw "The matrix is not square";
  }
  double determinant = this->Determinant();
  if (determinant == 0) {
    throw "Determinant is 0";
  }
  S21Matrix res = this->CalcComplements();
  res = res.Transpose();
  res.MulNumber(1.0 / determinant);
  return res;
}

void S21Matrix::operator+=(const S21Matrix &other) {
  try {
    this->SumMatrix(other);
  } catch (...) {
    throw "Matrixes size is different";
  }
}

void S21Matrix::operator-=(const S21Matrix &other) {
  try {
    this->SubMatrix(other);
  } catch (...) {
    throw "Matrixes size is different";
  }
}

void S21Matrix::operator*=(const S21Matrix &other) {
  try {
    this->MulMatrix(other);
  } catch (...) {
    throw "The number of columns of the first matrix is not equal to the "
          "number of rows of the second matrix";
  }
}

void S21Matrix::operator*=(const double num) { this->MulNumber(num); }

double &S21Matrix::operator()(int i, int j) const {
  if (i > this->rows_ || j > this->cols_) {
    throw "Index is out of matrix";
  }
  return this->matrix_[i][j];
}

void S21Matrix::set_rows(int rows) {
  if (rows < 1) {
    throw "Argument must be bigger than 0";
  }
  S21Matrix res_buf(rows, this->cols_);
  int rows_for_cpy;
  rows > this->rows_ ? rows_for_cpy = this->rows_ : rows_for_cpy = rows;
  for (int i = 0; i < rows_for_cpy; i++) {
    for (int j = 0; j < res_buf.cols_; j++) {
      res_buf.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = res_buf;
  res_buf.~S21Matrix();
}

void S21Matrix::set_cols(int cols) {
  if (cols < 1) {
    throw "Argument must be bigger than 0";
  }
  S21Matrix res_buf(this->rows_, cols);
  int cols_for_cpy;
  cols > this->cols_ ? cols_for_cpy = this->cols_ : cols_for_cpy = cols;
  for (int i = 0; i < res_buf.rows_; i++) {
    for (int j = 0; j < cols_for_cpy; j++) {
      res_buf.matrix_[i][j] = this->matrix_[i][j];
    }
  }
  *this = res_buf;
  res_buf.~S21Matrix();
}

void S21Matrix::fill_matrix_by_zero() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::eq_matrix_size(const S21Matrix &other) {
  if ((this->cols_ != other.cols_) || (this->rows_ != other.rows_)) {
    throw "Matrixes size is not equal";
  }
}

S21Matrix S21Matrix::get_minor(int i, int j) {
  S21Matrix res(this->rows_ - 1, this->cols_ - 1);
  int x1 = 0;
  int y1 = 0;
  for (int x = 0; x < this->rows_; x++) {
    if (x == i) {
      continue;
    }
    for (int y = 0; y < this->cols_; y++) {
      if (y == j) {
        continue;
      }
      res.matrix_[x1][y1] = this->matrix_[x][y];
      y1++;
    }
    x1++;
    y1 = 0;
  }
  return res;
}
