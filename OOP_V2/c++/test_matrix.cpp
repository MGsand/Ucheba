#include "matrix.h"
#include <cassert>
#include <iostream>

void testMatrixCreation() {
    // ���� 1: �������� ������� � ��������� ��������
    Matrix matrix1(2, 3);
    assert(matrix1.getRows() == 2);
    assert(matrix1.getCols() == 3);
    assert(matrix1.getElement(0, 0) == 0.0); // ���������, ��� �������� ���������������� ������

    // ���� 2: �������� ������� �� ������ ���������� �������
    std::vector<std::vector<double>> values = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix matrix2(values);
    assert(matrix2.getRows() == 2);
    assert(matrix2.getCols() == 2);
    assert(matrix2.getElement(0, 0) == 1.0);
    assert(matrix2.getElement(1, 1) == 4.0);

    std::cout << "����� �������� ������� ��������." << std::endl;
}

void testMatrixAccess() {
    Matrix matrix(2, 2);
    matrix.setElement(0, 0, 5.0);
    matrix.setElement(1, 1, 10.0);
    assert(matrix.getElement(0, 0) == 5.0);
    assert(matrix.getElement(1, 1) == 10.0);

    // �������� ���������� ��� ������ �� �������
    bool exceptionThrown = false;
    try {
        matrix.getElement(2, 0); // ����� �� �������
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        matrix.setElement(0, -1, 1.0); // ����� �� �������
    } catch (const std::out_of_range& e) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    std::cout << "����� ������� � ��������� ������� ��������." << std::endl;
}

void testMatrixAddition() {
    std::vector<std::vector<double>> values1 = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<double>> values2 = {{5.0, 6.0}, {7.0, 8.0}};
    Matrix matrix1(values1);
    Matrix matrix2(values2);

    Matrix result = matrix1 + matrix2;
    assert(result.getElement(0, 0) == 6.0);
    assert(result.getElement(0, 1) == 8.0);
    assert(result.getElement(1, 0) == 10.0);
    assert(result.getElement(1, 1) == 12.0);

    std::cout << "����� �������� ������ ��������." << std::endl;
}

void testMatrixSubtraction() {
    std::vector<std::vector<double>> values1 = {{5.0, 6.0}, {7.0, 8.0}};
    std::vector<std::vector<double>> values2 = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix matrix1(values1);
    Matrix matrix2(values2);

    Matrix result = matrix1 - matrix2;
    assert(result.getElement(0, 0) == 4.0);
    assert(result.getElement(0, 1) == 4.0);
    assert(result.getElement(1, 0) == 4.0);
    assert(result.getElement(1, 1) == 4.0);

    std::cout << "����� ��������� ������ ��������." << std::endl;
}

void testMatrixMultiplication() {
    std::vector<std::vector<double>> values1 = {{1.0, 2.0}, {3.0, 4.0}};
    std::vector<std::vector<double>> values2 = {{5.0, 6.0}, {7.0, 8.0}};
    Matrix matrix1(values1);
    Matrix matrix2(values2);

    Matrix result = matrix1 * matrix2;
    assert(result.getElement(0, 0) == 19.0);
    assert(result.getElement(0, 1) == 22.0);
    assert(result.getElement(1, 0) == 43.0);
    assert(result.getElement(1, 1) == 50.0);

    std::cout << "����� ��������� ������ ��������." << std::endl;
}

void testScalarMultiplication() {
    std::vector<std::vector<double>> values = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix matrix(values);

    Matrix result = matrix * 2.0;
    assert(result.getElement(0, 0) == 2.0);
    assert(result.getElement(0, 1) == 4.0);
    assert(result.getElement(1, 0) == 6.0);
    assert(result.getElement(1, 1) == 8.0);

    std::cout << "����� ��������� ������� �� ������ ��������." << std::endl;
}

void testMatrixTranspose() {
    std::vector<std::vector<double>> values = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    Matrix matrix(values);

    Matrix result = matrix.transpose();
    assert(result.getRows() == 2);
    assert(result.getCols() == 3);
    assert(result.getElement(0, 0) == 1.0);
    assert(result.getElement(0, 1) == 3.0);
    assert(result.getElement(0, 2) == 5.0);
    assert(result.getElement(1, 0) == 2.0);
    assert(result.getElement(1, 1) == 4.0);
    assert(result.getElement(1, 2) == 6.0);

    std::cout << "����� ���������������� ������� ��������." << std::endl;
}

int main() {
    testMatrixCreation();
    testMatrixAccess();
    testMatrixAddition();
    testMatrixSubtraction();
    testMatrixMultiplication();
    testScalarMultiplication();
    testMatrixTranspose();

    std::cout << "��� ����� ��������!" << std::endl;

    return 0;
}