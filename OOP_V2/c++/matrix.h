#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept> // Для обработки исключений

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    // Конструкторы
    Matrix(int rows, int cols);  // Создает матрицу rows x cols, заполненную нулями
    Matrix(const std::vector<std::vector<double>>& values); // Создает матрицу на основе двумерного вектора

    // Методы доступа
    int getRows() const;
    int getCols() const;
    double getElement(int row, int col) const;
    void setElement(int row, int col, double value);

    // Операторы
    Matrix operator+(const Matrix& other) const; // Сложение матриц
    Matrix operator-(const Matrix& other) const; // Вычитание матриц
    Matrix operator*(const Matrix& other) const; // Умножение матриц
    Matrix operator*(double scalar) const;       // Умножение на скаляр

    // Другие методы
    Matrix transpose() const;       // Транспонирование матрицы
    void print() const;             // Вывод матрицы на экран
};

#endif // MATRIX_H
