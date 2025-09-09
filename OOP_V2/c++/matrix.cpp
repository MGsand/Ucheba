#include "matrix.h"
#include <iostream>
#include <vector>

// Конструктор: Создает матрицу rows x cols, заполненную нулями
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

// Конструктор: Создает матрицу на основе двумерного вектора
Matrix::Matrix(const std::vector<std::vector<double>>& values) : rows(values.size()), cols(values[0].size()), data(values) {
    // Проверка на согласованность размеров столбцов
    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i].size() != cols) {
            throw std::invalid_argument("Размеры столбцов не совпадают.");
        }
    }
}

// Методы доступа
int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

double Matrix::getElement(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Недопустимый индекс элемента.");
    }
    return data[row][col];
}

void Matrix::setElement(int row, int col, double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Недопустимый индекс элемента.");
    }
    data[row][col] = value;
}

// Оператор: Сложение матриц
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны иметь одинаковые размеры для сложения.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Оператор: Вычитание матриц
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Матрицы должны иметь одинаковые размеры для вычитания.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Оператор: Умножение матриц
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы для умножения.");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

// Оператор: Умножение на скаляр
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

// Метод: Транспонирование матрицы
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// Метод: Вывод матрицы на экран
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
