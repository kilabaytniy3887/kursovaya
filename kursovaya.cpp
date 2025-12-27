#include <iostream>
#include <ctime>
#include "1Laboratornaya.h"
#include "2Laboratornaya.h"
#include "3Laboratornaya.h"
#include "4Laboratornaya.h"


int main()
{
    setlocale(LC_ALL, "RU");
    bool continueFlag = true;
    while (continueFlag)
    {
        std::cout << "Что хотите сделать?\n";
        std::cout << "1 - Открыть 1 лабораторную\n";
        std::cout << "2 - Открыть 2 лабораторную\n";
        std::cout << "3 - Открыть 3 лабораторную\n";
        std::cout << "4 - Открыть 4 лабораторную\n";
        std::cout << "0 - Завершить работу\n";
        int choise; 
        std::cin >> choise;

        switch (choise)
        {
        case 0:
            continueFlag = false;
            break;
        case 1:
        {
            std::cout << "1 Лабораторная работа:\n\n";
            SizeOfTypes();
            IntType();
            FloatType();
            DoubleType();
            break;
        }
        case 2:
        {
            std::cout << "2 Лабораторная работа:\n\n";
            srand(time(0));
            const int size = 100;
            int arr[size], arrCopy[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % 199 - 99;
                arrCopy[i] = arr[i];
            }
            for (int i = 0; i < size; i++)
            {
                std::cout << arr[i] << " ";
            }
            MainMenu(arr, arrCopy, size);
            break;
        }
        case 3:
        {
            std::cout << "3 Лабораторная работа:\n\n";
            mainMenuTri();
            break;
        }
        case 4:
        {
            std::cout << "4 Лабораторная работа:\n\n";
            mainMenuChetire();
            break;
        }
        default:
            break;
        }

    }
    std::cout << "\n\n" << "Программа завершила работу" << "\n\n";
    return 0;
}