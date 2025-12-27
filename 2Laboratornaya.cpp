#include <iostream>
#include <chrono>
#include "2Laboratornaya.h"


void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}


void ShakerSort(int arr[], int size)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		for (int i = left; i < right; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
			}
		}
		--right;
		for (int i = right; i > left; --i)
		{
			if (arr[i] < arr[i - 1])
			{
				std::swap(arr[i], arr[i - 1]);
			}
		}
		++left;
	}
}


void GnomeSort(int arr[], int size)
{
	int i = 0;
	while (i < size)
	{
		if (i == 0 || arr[i - 1] <= arr[i])
		{
			++i;
		}
		else;
		{
			std::swap(arr[i], arr[i - 1]);
			--i;
		}
	}
}


void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		std::swap(arr[i], arr[minIdx]);
	}
}


void QuickSort(int arr[], int begin, int end)
{
	if (begin >= end) return;

	int left = begin;
	int right = end;
	int mid = arr[(left + right) / 2];

	while (left <= right) {
		while (arr[left] < mid) left++;
		while (arr[right] > mid) right--;

		if (left <= right) {
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	if (begin < right) QuickSort(arr, begin, right);
	if (left < end) QuickSort(arr, left, end);
}


void QuickSortWrapper(int arr[], int n) {
	QuickSort(arr, 0, n - 1);
}


void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}


void MinAndMax(int arr[], int arrCopy[], int size)
{
	int choose, minNumber = 1000, maxNumber = -1000;
	std::cout << "Поиск в отсортированном массиве?";
	std::cout << "\n";
	std::cout << "1 - Да";
	std::cout << "\n";
	std::cout << "2 - Нет";
	std::cout << "\n";
	std::cin >> choose;
	if (choose == 1)
	{
		auto startBubble = std::chrono::high_resolution_clock::now();
		std::cout << "Наименьший эллемент: " << arr[0];
		std::cout << "\n";
		std::cout << "Наибольший эллемент: " << arr[size - 1];
		auto endBubble = std::chrono::high_resolution_clock::now();
		auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
		std::cout << "\n";
		std::cout << "Время поиска минимального и максимального элементов составило: " << timeBubble.count() << " мс";
		std::cout << "\n";
	}
	else
	{
		auto startBubble = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < size; ++i)
		{
			if (minNumber > arrCopy[i])
			{
				minNumber = arrCopy[i];
			}
			if (maxNumber < arrCopy[i])
			{
				maxNumber = arrCopy[i];
			}
		}
		std::cout << "Наименьший эллемент: " << minNumber;
		std::cout << "\n";
		std::cout << "Наибольший эллемент: " << maxNumber;
		auto endBubble = std::chrono::high_resolution_clock::now();
		auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
		std::cout << "\n";
		std::cout << "Время поиска минимального и максимального элементов составило: " << timeBubble.count() << " мс";
		std::cout << "\n";
	}
}


void PrintLessThan(int arr[], int size)
{
	int usersNumber, count = 0;
	std::cout << "Введите число:";
	std::cin >> usersNumber;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < usersNumber)
		{
			++count;
		}
	}
	std::cout << count;
}


void PrintMoreThan(int arr[], int size)
{
	int usersNumber, count = 0;
	std::cout << "Введите число:";
	std::cin >> usersNumber;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > usersNumber)
		{
			++count;
		}
	}
	std::cout << count;
}


void PrintFindNumber(int arr[], int size)
{
	int usersNumber, usersNumberTwo, count = 0, left = 0, right = size - 1, position = -1;
	std::cout << "Введите число:\n";
	std::cin >> usersNumber;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Выберите способ реализации поиска:\n";
	std::cout << "1 - Бинарный поиск\n";
	std::cout << "2 - Обычный перебор\n";
	std::cin >> usersNumberTwo;
	switch (usersNumberTwo)
	{
	case 1:
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			if (arr[middle] == usersNumberTwo) {
				position = middle;
				break;
			}
			else if (arr[middle] < usersNumberTwo) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		if (position != -1) {
			std::cout << "Такое число есть в отсортированном массиве. Оно находится на " << position << " месте в массиве." << "\n";
		}
		else {
			std::cout << "Такого числа нет в массиве" << "\n";
		}
		break;
	case 2:
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] == usersNumber)
			{
				std::cout << "Такое число есть в отсортированном массиве. Оно находится на " << i + 1 << " месте в массиве.";
				count += 1;
				break;
			}
		}
		if (count == 0)
		{
			std::cout << "Такого числа нет в массиве.";
		}
		break;
	}
}


void ChangePositions(int arr[], int size)
{
	int firstNumber, secondNumber, memoryNumber;
	std::cout << "Введите индекс числа, которое хотите заменить: \n";
	std::cin >> firstNumber;
	std::cout << "Введите индекс, на которое хотите поставить: \n";
	std::cin >> secondNumber;
	if ((firstNumber <= size - 1 && firstNumber >= 0) && (secondNumber <= size - 1 && secondNumber >= 0))
	{
		auto startBubble = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < size; ++i)
		{
			if (i == firstNumber)
			{
				memoryNumber = arr[i];
				arr[i] = arr[firstNumber + secondNumber - i];
				arr[firstNumber + secondNumber - i] = memoryNumber;
			}
		}
		auto endBubble = std::chrono::high_resolution_clock::now();
		auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
		std::cout << "Время перестановки элементов массива составило: " << timeBubble.count() << " мс";
	}
	else
	{
		std::cout << "Вы ввели индекс, которого нет в массиве.\n";
	}
	std::cout << "\n";

	PrintArray(arr, size);
	std::cout << "\n";
}


void IDZ(int arr[], int size)
{
	int maxSize = 1, checkNumber = 0, mmaxSize = 1, startOut = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			++maxSize;
			if (maxSize > mmaxSize)
			{
				mmaxSize = maxSize;
				checkNumber = i;
			}
		}
		else
		{
			maxSize = 1;
		}
	}
	std::cout << "Максимальная длина последовательности: " << mmaxSize;
	std::cout << "\n";
	std::cout << "Последовательность: ";
	std::cout << "\n";
	startOut = checkNumber - mmaxSize + 1;
	for (int i = startOut; i <= checkNumber; ++i)
	{
		std::cout << arr[i] << " ";
	}
}


void ChangeProcess(int changeTask, int arr[], int arrCopy[], int size)
{
	int changeTaskTwo;
	switch (changeTask)
	{
	case 1:
		do
		{
			std::cout << "Выберите из предложенного:\n";
			std::cout << "1 - Вывести массив\n";
			std::cout << "2 - Вывести наименьший и наибольший элементы массива\n";
			std::cout << "3 - Вывести количество чисел, которые меньше числа\n";
			std::cout << "4 - Вывести количество чисел, которые больше числа\n";
			std::cout << "5 - Найти позицию элемента в массиве\n";
			std::cout << "6 - Переставить числа местами в отсортированном массиве\n";
			std::cout << "7 - ИДЗ (16 вариант), Поиск наиболее длиннной неприрывной возрастающей последовательности в массиве\n";
			std::cout << "8 - Вывести время сортировки массива\n";
			std::cout << "0 - Вернуться в основное меню\n";
			std::cin >> changeTaskTwo;

			switch (changeTaskTwo)
			{

			case 1:
				std::cout << "\n";
				BubbleSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				break;
			case 2:
				std::cout << "\n";
				BubbleSort(arr, size);
				MinAndMax(arr, arrCopy, size);
				std::cout << "\n";
				break;
			case 3:
				std::cout << "\n";
				PrintLessThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 4:
				std::cout << "\n";
				PrintMoreThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 5:
				std::cout << "\n";
				BubbleSort(arr, size);
				PrintFindNumber(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 6:
				std::cout << "\n";
				BubbleSort(arr, size);
				ChangePositions(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 7:
				std::cout << "\n";
				IDZ(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 8:
				std::cout << "\n";
				std::cout << "Bubble Sort:\n";
				auto startBubble = std::chrono::high_resolution_clock::now();
				BubbleSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				auto endBubble = std::chrono::high_resolution_clock::now();
				auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
				std::cout << "Время сортировки массива методом Bubble sort составило: " << timeBubble.count() << " мс";
				std::cout << "\n";
				std::cout << "\n";
				break;
			}
		} while (changeTaskTwo != 0);
		break;
	case 2:
		do
		{
			std::cout << "Выберите из предложенного:\n";
			std::cout << "1 - Вывести массив\n";
			std::cout << "2 - Вывести наименьший и наибольший элементы массива\n";
			std::cout << "3 - Вывести количество чисел, которые меньше числа\n";
			std::cout << "4 - Вывести количество чисел, которые больше числа\n";
			std::cout << "5 - Найти позицию элемента в массиве\n";
			std::cout << "6 - Переставить числа местами в отсортированном массиве\n";
			std::cout << "7 - ИДЗ (16 вариант), Поиск наиболее длиннной неприрывной возрастающей последовательности в массиве\n";
			std::cout << "8 - Вывести время сортировки массива\n";
			std::cout << "0 - Вернуться в основное меню\n";
			std::cin >> changeTaskTwo;

			switch (changeTaskTwo)
			{

			case 1:
				std::cout << "\n";
				ShakerSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				break;
			case 2:
				std::cout << "\n";
				ShakerSort(arr, size);
				MinAndMax(arr, arrCopy, size);
				std::cout << "\n";
				break;
			case 3:
				std::cout << "\n";
				PrintLessThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 4:
				std::cout << "\n";
				PrintMoreThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 5:
				std::cout << "\n";
				ShakerSort(arr, size);
				PrintFindNumber(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 6:
				std::cout << "\n";
				ShakerSort(arr, size);
				ChangePositions(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 7:
				std::cout << "\n";
				IDZ(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 8:
				std::cout << "\n";
				std::cout << "Shaker Sort:\n";
				auto startBubble = std::chrono::high_resolution_clock::now();
				ShakerSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				auto endBubble = std::chrono::high_resolution_clock::now();
				auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
				std::cout << "Время сортировки массива методом Shaker sort составило: " << timeBubble.count() << " мс";
				std::cout << "\n";
				std::cout << "\n";
				break;
			}
		} while (changeTaskTwo != 0);
		break;
	case 3:
		do
		{
			std::cout << "Выберите из предложенного:\n";
			std::cout << "1 - Вывести массив\n";
			std::cout << "2 - Вывести наименьший и наибольший элементы массива\n";
			std::cout << "3 - Вывести количество чисел, которые меньше числа\n";
			std::cout << "4 - Вывести количество чисел, которые больше числа\n";
			std::cout << "5 - Найти позицию элемента в массиве\n";
			std::cout << "6 - Переставить числа местами в отсортированном массиве\n";
			std::cout << "7 - ИДЗ (16 вариант), Поиск наиболее длиннной неприрывной возрастающей последовательности в массиве\n";
			std::cout << "8 - Вывести время сортировки массива\n";
			std::cout << "0 - Вернуться в основное меню\n";
			std::cin >> changeTaskTwo;

			switch (changeTaskTwo)
			{

			case 1:
				std::cout << "\n";
				GnomeSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				break;
			case 2:
				std::cout << "\n";
				GnomeSort(arr, size);
				MinAndMax(arr, arrCopy, size);
				std::cout << "\n";
				break;
			case 3:
				std::cout << "\n";
				PrintLessThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 4:
				std::cout << "\n";
				PrintMoreThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 5:
				std::cout << "\n";
				GnomeSort(arr, size);
				PrintFindNumber(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 6:
				std::cout << "\n";
				GnomeSort(arr, size);
				ChangePositions(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 7:
				std::cout << "\n";
				IDZ(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 8:
				std::cout << "\n";
				std::cout << "Gnome Sort:\n";
				auto startBubble = std::chrono::high_resolution_clock::now();
				GnomeSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				auto endBubble = std::chrono::high_resolution_clock::now();
				auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
				std::cout << "Время сортировки массива методом Gnome sort составило: " << timeBubble.count() << " мс";
				std::cout << "\n";
				std::cout << "\n";
				break;
			}
		} while (changeTaskTwo != 0);
		break;
	case 4:
		do
		{
			std::cout << "Выберите из предложенного:\n";
			std::cout << "1 - Вывести массив\n";
			std::cout << "2 - Вывести наименьший и наибольший элементы массива\n";
			std::cout << "3 - Вывести количество чисел, которые меньше числа\n";
			std::cout << "4 - Вывести количество чисел, которые больше числа\n";
			std::cout << "5 - Найти позицию элемента в массиве\n";
			std::cout << "6 - Переставить числа местами в отсортированном массиве\n";
			std::cout << "7 - ИДЗ (16 вариант), Поиск наиболее длиннной неприрывной возрастающей последовательности в массиве\n";
			std::cout << "8 - Вывести время сортировки массива\n";
			std::cout << "0 - Вернуться в основное меню\n";
			std::cin >> changeTaskTwo;

			switch (changeTaskTwo)
			{

			case 1:
				std::cout << "\n";
				SelectionSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				break;
			case 2:
				std::cout << "\n";
				SelectionSort(arr, size);
				MinAndMax(arr, arrCopy, size);
				std::cout << "\n";
				break;
			case 3:
				std::cout << "\n";
				PrintLessThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 4:
				std::cout << "\n";
				PrintMoreThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 5:
				std::cout << "\n";
				SelectionSort(arr, size);
				PrintFindNumber(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 6:
				std::cout << "\n";
				SelectionSort(arr, size);
				ChangePositions(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 7:
				std::cout << "\n";
				IDZ(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 8:
				std::cout << "\n";
				std::cout << "Selection Sort:\n";
				auto startBubble = std::chrono::high_resolution_clock::now();
				SelectionSort(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				auto endBubble = std::chrono::high_resolution_clock::now();
				auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
				std::cout << "Время сортировки массива методом Selection sort составило: " << timeBubble.count() << " мс";
				std::cout << "\n";
				std::cout << "\n";
				break;
			}
		} while (changeTaskTwo != 0);
		break;
	case 5:
		do
		{
			std::cout << "Выберите из предложенного:\n";
			std::cout << "1 - Вывести массив\n";
			std::cout << "2 - Вывести наименьший и наибольший элементы массива\n";
			std::cout << "3 - Вывести количество чисел, которые меньше числа\n";
			std::cout << "4 - Вывести количество чисел, которые больше числа\n";
			std::cout << "5 - Найти позицию элемента в массиве\n";
			std::cout << "6 - Переставить числа местами в отсортированном массиве\n";
			std::cout << "7 - ИДЗ (16 вариант), Поиск наиболее длиннной неприрывной возрастающей последовательности в массиве\n";
			std::cout << "8 - Вывести время сортировки массива\n";
			std::cout << "0 - Вернуться в основное меню\n";
			std::cin >> changeTaskTwo;

			switch (changeTaskTwo)
			{

			case 1:
				std::cout << "\n";
				QuickSortWrapper(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				break;
			case 2:
				std::cout << "\n";
				QuickSortWrapper(arr, size);
				MinAndMax(arr, arrCopy, size);
				std::cout << "\n";
				break;
			case 3:
				std::cout << "\n";
				PrintLessThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 4:
				std::cout << "\n";
				PrintMoreThan(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 5:
				std::cout << "\n";
				QuickSortWrapper(arr, size);
				PrintFindNumber(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 6:
				std::cout << "\n";
				QuickSortWrapper(arr, size);
				ChangePositions(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 7:
				std::cout << "\n";
				IDZ(arr, size);
				std::cout << "\n";
				std::cout << "\n";
				break;
			case 8:
				std::cout << "\n";
				std::cout << "Quick Sort:\n";
				auto startBubble = std::chrono::high_resolution_clock::now();
				QuickSortWrapper(arr, size);
				PrintArray(arr, size);
				std::cout << "\n";
				auto endBubble = std::chrono::high_resolution_clock::now();
				auto timeBubble = std::chrono::duration_cast<std::chrono::milliseconds>(endBubble - startBubble);
				std::cout << "Время сортировки массива методом Quick sort составило: " << timeBubble.count() << " мс";
				std::cout << "\n";
				std::cout << "\n";
				break;
			}
		} while (changeTaskTwo != 0);
		break;
	case 0:
		std::cout << "Выход из программы...";
		break;
	default:
		std::cout << "Введено неверное значение.";
		break;
	}
}


void MainMenu(int arr[], int arrCopy[], int size)
{
	unsigned int changeTask;
	do
	{
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "Выберите тип сортировки из предложенных\n";
		std::cout << "1 - Bubble sort\n";
		std::cout << "2 - Shaker sort\n";
		std::cout << "3 - Gnome sort\n";
		std::cout << "4 - Cycle Sort\n";
		std::cout << "5 - Quick sort\n";
		std::cout << "0 - Окончание работы программы\n";
		std::cout << "\n";
		std::cin >> changeTask;
		std::cout << "\n";
		ChangeProcess(changeTask, arr, arrCopy, size);
	} while (changeTask != 0);
}

