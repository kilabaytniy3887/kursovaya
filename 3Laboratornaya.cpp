#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "3Laboratornaya.h"


void printMatrix(int* matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(4) << *(matrix + i * size + j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void printMatrixSpiral(int* matrix, int size) {
    int value = 1;
    int up = 0, down = size - 1;
    int left = 0, right = size - 1;

    system("cls");
    printMatrix(matrix, size);
    Sleep(200);

    while (up <= down && left <= right) {
        for (int j = left; j <= right; j++) {
            *(matrix + up * size + j) = value++;
            system("cls");
            printMatrix(matrix, size);
            Sleep(100);
        }
        up++;

        if (up <= down) {
            for (int i = up; i <= down; i++) {
                *(matrix + i * size + right) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
            right--;
        }

        if (up <= down) {
            for (int j = right; j >= left; j--) {
                *(matrix + down * size + j) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
            down--;
        }

        if (left <= right) {
            for (int i = down; i >= up; i--) {
                *(matrix + i * size + left) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
            left++;
        }
    }
}


void printMatrixSnake(int* matrix, int size)
{
    int value = 1;

    system("cls");
    printMatrix(matrix, size);
    Sleep(200);

    for (int col = 0; col < size; col++) {
        if (col % 2 == 0) {
            for (int row = 0; row < size; row++) {
                *(matrix + row * size + col) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
        }
        else { 
            for (int row = size - 1; row >= 0; row--) {
                *(matrix + row * size + col) = value++;
                system("cls");
                printMatrix(matrix, size);
                Sleep(100);
            }
        }
    }
}


void choiseSnakeOrSpiral(int* matrix, int size)
{
    int changeProgramm;
    std::cout << "Выберите способ вывода матрицы:\n";
    std::cout << "1 - Вывести спиралью\n";
    std::cout << "2 - Вывести змейкой\n";
    std::cin >> changeProgramm;
    switch (changeProgramm)
    {
    case 1:
        printMatrixSpiral(matrix, size);
        break;
    case 2:
        printMatrixSnake(matrix, size);
        break;
    }
}


void demonstrateFill(int* mat, int n, int pattern) {

    for (int i = 0; i < n * n; i++) {
        *(mat + i) = 0;
    }

    switch (pattern) {
    case 1:
        std::cout << "Заполнение спиралью\n";
        printMatrixSpiral(mat, n);
        break;
    case 2:
        std::cout << "Заполнение змейкой\n";
        printMatrixSnake(mat, n);
        break;
    }
}


void insertionSort(int* matrix, int size) {
    for (int* p = (matrix + 1); p < matrix + (size * size); p++) {
        int addNum = *p;
        int* j = p - 1;
        while (j >= matrix && *j > addNum) {
            std::swap(*j, *(j + 1));
            --j;
        }
    }
}


void swapElement(int matrix[], int size, int num, int num1) {
    int count = 0;
    bool f = true;
    for (int* t = matrix; t < matrix + (size * size) / 2; t++) {
        if (count < size / 2 && f) {
            std::swap(*t, *(t + num));
            count++;
        }
        else if (count > 0) {
            if (num1 != 0)
                std::swap(*t, *(t + num1));
            count--;
        }
        if (count == 0 && !f) {
            f = true;
        }
        if (count == size / 2 && f) {
            f = false;
        }
    }
}


void swapElementColumn(int* matrix, int size)
{
    int count = 0;
    for (int* t = matrix; t + size / 2 + count < matrix + (size * size); t++) {
        if ((t - matrix) % (size / 2) == 0 && (t - matrix) != 0) {
            count += size / 2;
        }
        std::swap(*(t + count), *(t + size / 2 + count));
    }
}


void rotate(int* matrix, int size)
{
    int choice;
    do
    {
        std::cout << "Желаете переместить элементы местами?\n";
        std::cout << "1 - Повернуть четверть на 90 градусов\n";
        std::cout << "2 - Отразить четверть по диагонали\n";
        std::cout << "3 - Отразить четверть по горизонтали\n";
        std::cout << "4 - Отразить четверть по вертикали\n";
        std::cout << "0 - Следующее действие\n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            swapElementColumn(matrix, size);
            swapElement(matrix, size, ((size * size + size) / 2));
            break;
        case 2:
            swapElement(matrix, size, ((size * size + size) / 2), ((size / 2 - 1) * size + (size / 2)));
            break;
        case 3:
            swapElementColumn(matrix, size);
            break;
        case 4:
            swapElement(matrix, size, (size * size) / 2, (size * size) / 2);
            break;
        }
        printMatrix(matrix, size);
    } while (choice != 0);
}


void mathMatrix(int* matrix, int size)
{
    int number, choiceSecond;
    do
    {
        std::cout << "Напишите скаляр: ";
        std::cin >> number;
        std::cout << "Какое действие хотите выполнить?\n";
        std::cout << "1 - Вычитание\n";
        std::cout << "2 - Сложение\n";
        std::cout << "3 - Умножение\n";
        std::cout << "4 - Деление\n";
        std::cout << "0 - Выход\n";
        std::cin >> choiceSecond;
        switch (choiceSecond) {
        case 1:
            for (int* q = matrix; q < matrix + (size * size); q++)
            {
                *q -= number;
            }
            printMatrix(matrix, size);
            break;

        case 2:
            for (int* q = matrix; q < matrix + (size * size); q++)
            {
                *q += number;
            }
            printMatrix(matrix, size);
            break;

        case 3:
            for (int* q = matrix; q < matrix + (size * size); q++)
            {
                *q *= number;
            }
            printMatrix(matrix, size);
            break;

        case 4:
            if (number == 0)
            {
                std::cout << "На ноль делить нельзя\n";
            }
            else
            {
                for (int* q = matrix; q < matrix + (size * size); q++)
                {
                    *q /= number;
                }
                printMatrix(matrix, size);
            }
            break;

        case 0:
            std::cout << "Выход из операций с матрицей\n";
            std::cout << "\n";
            break;

        default:
            std::cout << "Неверный выбор\n";
        }
    } while (choiceSecond != 0);
}


void sortMatrix(int* matrix, int size)
{
    int sortChoice;
    std::cout << "Желаете отсортировать матрицу?\n";
    std::cout << "1 - Да\n";
    std::cout << "2 - Нет\n";
    std::cin >> sortChoice;
    if (sortChoice == 1)
    {
        std::cout << "\nНе отсортированная матрица\n";
        printMatrix(matrix, size);
        std::cout << "Отсортированная матрица\n";
        insertionSort(matrix, size);
        printMatrix(matrix, size);
    }
    else
    {
        printMatrix(matrix, size);
    }
}


void mainMenuTri()
{
    int prog;
    int size, pattern, changeElements, choice, choiceSecond, number;
    std::cout << "Введите размер матрицы (6, 8 или 10): ";
    std::cin >> size;
    if (size != 6 && size != 8 && size != 10) {
        std::cout << "Некорректный размер! Используется размер 8.\n";
        size = 8;
    }
    std::cout << "Выберите схему заполнения (1 - Спиралью, 2 - Змейкой): \n";
    std::cout << "1 - Спиралью\n";
    std::cout << "2 - Змейкой\n";
    std::cin >> pattern;
    int* matrix = new int[size * size];
    demonstrateFill(matrix, size, pattern);
    rotate(matrix, size);
    sortMatrix(matrix, size);
    mathMatrix(matrix, size);
    std::cout << "Запустить программу ещё раз?\n";
    std::cout << "1 - Да\n";
    std::cout << "2 - Нет\n";
    std::cin >> prog;
    if (prog == 1)
    {
        mainMenuTri();
    }
}



