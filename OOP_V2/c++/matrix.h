#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept> // ��� ��������� ����������

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // ������������
    Matrix(int rows, int cols);  // ������� ������� rows x cols, ����������� ������
    Matrix(const std::vector<std::vector<double>>& values); // ������� ������� �� ������ ���������� �������

    // ������ �������
    int getRows() const;
    int getCols() const;
    double getElement(int row, int col) const;
    void setElement(int row, int col, double value);

    // ���������
    Matrix operator+(const Matrix& other) const; // �������� ������
    Matrix operator-(const Matrix& other) const; // ��������� ������
    Matrix operator*(const Matrix& other) const; // ��������� ������
    Matrix operator*(double scalar) const;       // ��������� �� ������

    // ������ ������
    Matrix transpose() const;       // ���������������� �������
    void print() const;             // ����� ������� �� �����
};

#endif // MATRIX_H
