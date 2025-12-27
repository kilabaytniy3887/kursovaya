#include <iostream>
#include <fstream>
#include <vector>
#include "4Laboratornaya.h"


void fileInput(char text[], const int size)
{
    std::ifstream input("text.txt");
    if (!input.is_open())
    {
        std::cout << "Ошибка открытия файла\n";
    }
    input.getline(text, size);
    input.close();

}


void printText(char text[])
{
    int i = 0;
    while (text[i] != '\0')
    {
        std::cout << text[i];
        i++;
    }
}


void removeSpacebars(char text[])
{
    if (text == nullptr) return;

    int readPos = 0;
    int writePos = 0;
    bool previousWasSpace = false;

    while (text[readPos] != '\0') 
    {
        if (text[readPos] == ' ') 
        {
            if (!previousWasSpace && writePos > 0) 
            {
                text[writePos] = ' ';
                writePos++;
                previousWasSpace = true;
            }
        }
        else 
        {
            text[writePos] = text[readPos];
            writePos++;
            previousWasSpace = false;
        }
        readPos++;
    }
    if (writePos > 0 && text[writePos - 1] == ' ') 
    {
        writePos--;
    }
    text[writePos] = '\0';
}


bool isPunctuation(char text) 
{
    return (text == '.' || text == ',' || text == '!' || text == '?' || text == ';' || text == ':' || text == '-' || text == '(' || text == ')' || text == '\"' || text == '\'');
}


void removeMarks(char text[], int size) {
    int i = 0;
    int j = 0;
    bool lastPunctuation = false;
    char* copyText = new char[size + 1];
    for (int i = 0; i <= size; i++) 
    {
        copyText[i] = text[i];
    }
    while (text[i] != '\0') 
    {
        bool tripleDot = false;
        if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.') 
        {
            tripleDot = true;
        }

        if (tripleDot) 
        {
            copyText[j] = '.';
            copyText[j + 1] = '.';
            copyText[j + 2] = '.';
            j += 3;
            i += 3;
            lastPunctuation = true;
        }
        else if (isPunctuation(text[i])) 
        {
            if (!lastPunctuation) 
            {
                copyText[j] = text[i];
                j++;
            }
            i++;
            lastPunctuation = true;
        }
        else 
        {
            copyText[j] = text[i];
            j++;
            i++;
            lastPunctuation = false;
        }
    }
    copyText[j] = '\0';
    int x = 0;
    while (x < size - 1 && copyText[x] != '\0') 
    {
        text[x] = copyText[x];
        x++;
    }
}


void fixRegister(char text[])
{
    bool newSentence = true;
    int i = 0;

    while (text[i] != '\0') {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) 
        {
            if (newSentence) 
            {
                if (text[i] >= 'a' && text[i] <= 'z') 
                {
                    text[i] = text[i] - 'a' + 'A';
                }
                newSentence = false;
            }
            else 
            {
                if (text[i] >= 'A' && text[i] <= 'Z') 
                {
                    text[i] = text[i] - 'A' + 'a';
                }
            }
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') 
        {
            newSentence = true;
        }
        i++;
    }
}


void textReduct(char text[], int size)
{
    removeSpacebars(text);
    removeMarks(text, size);
    fixRegister(text);
    printText(text);
    std::cout << "\n";
}


void changePositions(char text[])
{
    int wordsEnd = 0;
    while (text[wordsEnd] != '\0') {
        wordsEnd++;
    }

    while (wordsEnd >= 0) {
        while (wordsEnd >= 0 && text[wordsEnd] == ' ') 
        {
            wordsEnd--;
        }
        if (wordsEnd < 0) break;


        int wordStart = wordsEnd;
        while (wordStart >= 0 && text[wordStart] != ' ') 
        {
            wordStart--;
        }

        for (int i = wordStart + 1; i <= wordsEnd; i++) 
        {
            std::cout << text[i];
        }


        if (wordStart > 0) 
        {
            std::cout << ' ';
        }
        wordsEnd = wordStart - 1;
    }
    std::cout << "\n";
}


void verticalWords(char text[], int size) {
    int maxLen = 0;
    int currentLen = 0;
    int wordCount = 0;

    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') 
        {
            currentLen++;
        }
        else if (currentLen > 0) 
        {
            if (currentLen > maxLen) maxLen = currentLen;
            wordCount++;
            currentLen = 0;
        }
    }
    if (currentLen > 0) 
    {
        if (currentLen > maxLen) maxLen = currentLen;
        wordCount++;
    }
    int* positions = new int[wordCount];
    for (int i = 0; i < wordCount; i++) positions[i] = 0;


    for (int row = 0; row < maxLen; row++) 
    {
        int wordIdx = 0;
        bool inWord = false;
        int charInWord = 0;

        for (int i = 0; text[i] != '\0' && wordIdx < wordCount; i++) 
        {
            if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') 
            {
                if (!inWord) 
                {
                    inWord = true;
                    charInWord = 0;
                }

                if (charInWord == row) 
                {
                    std::cout << text[i];
                }
                charInWord++;
            }
            else if (inWord) 
            {
                if (charInWord <= row) 
                {
                    std::cout << ' ';
                }
                inWord = false;
                wordIdx++;
                std::cout << ' ';
            }
        }
        if (inWord && charInWord <= row) 
        {
            std::cout << ' ';
        }

        std::cout << std::endl;
    }
}


int searchLinneum(char text[], char pattern[]) 
{
    int textLength = 0, patternLength = 0;
    while (text[textLength] != '\0')
    {
        textLength++;
    }
    while (pattern[patternLength] != '\0')
    {
        patternLength++;
    }
    for (int i = 0; i <= textLength - patternLength; i++)
    {
        int j;
        for (j = 0; j < patternLength; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == patternLength)
        {
            return i;
        }
    }
    return -1;
}


void computePrefixFunction(char text[], char pattern[], int* pi) {
    int patternLength = 0;
    while (pattern[patternLength] != '\0') 
    {
        patternLength++;
    }

    if (patternLength == 0) return;

    pi[0] = 0;

    for (int i = 1; i < patternLength; i++) 
    {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) 
        {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) 
        {
            j++;
        }
        pi[i] = j;
    }
}


int kmpSearch(char text[], char pattern[]) {
    int patternLength = 0;
    while (pattern[patternLength] != '\0')
    {
        patternLength++;
    }
    int textLength = 0;
    while (text[textLength] != '\0')
    {
        textLength++;
    }
    if (patternLength == 0) 
    {
        return 0;
    }
    int* pi = new int[patternLength];
    computePrefixFunction(text, pattern, pi);
    int j = 0;

    for (int i = 0; i < textLength; i++) 
    {
        while (j > 0 && text[i] != pattern[j]) 
        {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) 
        {
            j++;
        }
        if (j == patternLength) 
        {
            return i - patternLength + 1;
        }
    }
    return -1;
}


void findRows(char text[], const int size)
{
    char choiceAlgorythm;
    char pattern[4096];
    int result;
    int i = 0;
    std::cout << "Какую последовательность?\n";
    std::cin.ignore();
    std::cin.getline(pattern, size);
    std::cout << "Каким способом?\n";
    std::cout << "1 - Алгоритм линейного поиска\n";
    std::cout << "2 - Алгоритм Кнутта-Мориса-Пратта\n";
    std::cin >> choiceAlgorythm;
    switch (choiceAlgorythm)
    {
    case '1':
        result = searchLinneum(text, pattern);
        if (result == -1)
            std::cout << "Подстрока не найдена" << "\n";
        else
            std::cout << "Подстрока найдена в позиции: " << result << "\n";
        break;
    case '2':
        result = kmpSearch(text, pattern);
        if (result != -1) {
            std::cout << "Подстрока найдена в позиции: " << result << "\n";
        }
        else {
            std::cout << "Подстрока не найдена" << "\n";
        }
        break;
    default:
        std::cout << "Неверный ввод!\n";
    }
}


void mainMenuChetire()
{
    const int size = 4096;
    char choiceTask, choiceText;
    char text[size], outText[size];
    std::cout << "Откуда взять текст?\n";
    std::cout << "1 - Из файла\n";
    std::cout << "2 - С клавиатуры\n";
    std::cin >> choiceText;
    switch (choiceText)
    {
    case '1':
        fileInput(text, size);
        printText(text);
        break;
    case '2':
        std::cout << "Введите текст...\n";
        std::cin.ignore();
        std::cin.getline(text, size);
        break;
    default:
        std::cout << "Неверный ввод!";
        break;
    }
    do
    {
        std::cout << "Выберите задачу для программы\n";
        std::cout << "1 - Отредактировать текст\n";
        std::cout << "2 - Вывести на экран слова последовательности в обратном порядке. (1 задание)\n";
        std::cout << "3 - Вывести все слова исходной последовательности на экран вертикально.(6 задание)\n";
        std::cout << "4 - Поиск подстрок\n";
        std::cout << "0 - Выход из программы\n";
        std::cin >> choiceTask;
        switch (choiceTask)
        {
        case '1':
            textReduct(text, size);
            break;
        case '2':
            changePositions(text);
            break;
        case '3':
            verticalWords(text, size);
            break;
        case '4':
            findRows(text, size);
            break;
        case '0':
            std::cout << "Выход из программы\n";
            std::cout << "\n";
            break;
        default:
            std::cout << "Неверный ввод!\n";
        }
    } while (choiceTask != 0);
}
