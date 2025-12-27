#include <iostream>
#include "1Laboratornaya.h"


void SizeOfTypes() {
    std::cout << "Отведенный объем памяти под различные типы данных:\nТип int: " << sizeof(int) << " байт\nТип short int: " << sizeof(short int) << " байт\nТип long int: " << sizeof(long int) << " байт\nТип float: " << sizeof(float) << " байт\nТип double: " << sizeof(double) << " байт\nТип long double: " << sizeof(long double) << " байт\nТип char: " << sizeof(char) << " байт\nТип bool: " << sizeof(bool) << " байт\n";
    std::cout << "\n";
}

void IntType() {
    int IntNumber;
    int CountBits = 0;
    int IntCountBits = sizeof(int) * 8;

    std::cout << "Введите целое число: ";
    std::cin >> IntNumber;
    std::cout << ((IntNumber < 0) ? "1" : "0") << " ";

    for (int i = IntCountBits - 2; i >= 0; --i) {
        int CheckBit = (IntNumber >> i) & 1;
        if (CheckBit == 1) {
            std::cout << CheckBit;
        }
        else {
            std::cout << CheckBit;
        }
        if (CountBits % 8 == 6) {
            std::cout << " ";
        }
        ++CountBits;
    }
    std::cout << "\n";
    std::cout << "Вы хотите заменить бит в числе?\n";
    std::cout << "1 - да, заменить бит на 1\n";
    std::cout << "2 - да, заменить бит на 0\n";
    std::cout << "3 - нет\n";
    int ChoiseChangeBit;
    std::cin >> ChoiseChangeBit;
    int IntCountChangeBit;
    int IntMaskChangeBit;
    int NewIntNumber;
    int ChangeSymbol;
    switch (ChoiseChangeBit)
    {
    case 1:
        CountBits = 0;
        std::cout << "Какой по счёту бит вы хотите заменить?\n";
        std::cin >> IntCountChangeBit;
        IntMaskChangeBit = 1 << (IntCountChangeBit - 1);
        NewIntNumber = IntMaskChangeBit | IntNumber;
        std::cout << ((IntNumber < 0) ? "1" : "0") << " ";
        for (int i = IntCountBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewIntNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits % 8 == 6) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            CountBits = 0;
            std::cout << ((IntNumber < 0) ? "0" : "1") << " ";
            for (int i = IntCountBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewIntNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits % 8 == 6) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 2:
        CountBits = 0;
        std::cout << "Какой по счёту бит вы хотите заменить?\n";
        std::cin >> IntCountChangeBit;
        IntMaskChangeBit = 1 << (IntCountChangeBit - 1);
        NewIntNumber = ~IntMaskChangeBit & IntNumber;
        std::cout << ((IntNumber < 0) ? "1" : "0") << " ";
        for (int i = IntCountBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewIntNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits % 8 == 6) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            CountBits = 0;
            std::cout << ((IntNumber < 0) ? "0" : "1") << " ";
            for (int i = IntCountBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewIntNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits % 8 == 6) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 3:
        std::cout << "Работа выполнена\n";
        break;
    default: "Такого выбора нету";
    }
}

void FloatType() {
    float FloatNumber;
    int FloatBits = sizeof(float) * 8;
    int FloatExponentsBits = 8;
    int FloatMantissaBits = FloatBits - FloatExponentsBits - 1;

    std::cout << "Введите число типа float: ";
    std::cin >> FloatNumber;

    union {
        float FloatNumber;
        unsigned int FakeFloatNumber;
    } f;

    f.FloatNumber = FloatNumber;
    std::cout << ((FloatNumber < 0) ? "1" : "0") << " ";

    unsigned int FloatExponent = (f.FakeFloatNumber >> FloatMantissaBits) & ((1 << FloatExponentsBits) - 1);
    for (int i = FloatExponentsBits - 1; i >= 0; --i) {
        std::cout << ((FloatExponent >> i) & 1);
    }

    std::cout << " ";

    for (int i = FloatMantissaBits - 1; i >= 0; --i) {
        int CheckBit = (f.FakeFloatNumber >> i) & 1;
        if (CheckBit == 1) {
            std::cout << CheckBit;
        }
        else {
            std::cout << CheckBit;
        }
    }
    std::cout << "\n";
    std::cout << "Вы хотите заменить бит в числе?\n";
    std::cout << "1 - да, заменить бит на 1\n";
    std::cout << "2 - да, заменить бит на 0\n";
    std::cout << "3 - нет\n";
    int ChoiseChangeBit;
    std::cin >> ChoiseChangeBit;
    int FloatCountChangeBit;
    int FloatMaskChangeBit;
    int NewFloatNumber;
    int CountBits = 0;
    std::cout << "Какой по счёту бит вы хотите заменить?\n";
    std::cin >> FloatCountChangeBit;
    int ChangeSymbol;
    switch (ChoiseChangeBit)
    {
    case 1:
        FloatMaskChangeBit = 1 << (FloatCountChangeBit - 1);
        NewFloatNumber = FloatMaskChangeBit | f.FakeFloatNumber;
        std::cout << ((FloatNumber < 0) ? "1" : "0") << " ";
        for (int i = FloatBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewFloatNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits == 7) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            CountBits = 0;
            FloatMaskChangeBit = 1 << (FloatCountChangeBit - 1);
            NewFloatNumber = FloatMaskChangeBit | f.FakeFloatNumber;
            std::cout << ((FloatNumber < 0) ? "0" : "1") << " ";
            for (int i = FloatBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewFloatNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits == 7) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 2:
        CountBits = 0;
        FloatMaskChangeBit = 1 << (FloatCountChangeBit - 1);
        NewFloatNumber = ~FloatMaskChangeBit & f.FakeFloatNumber;
        std::cout << ((FloatNumber < 0) ? "1" : "0") << " ";
        for (int i = FloatBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewFloatNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits == 7) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            FloatMaskChangeBit = 1 << (FloatCountChangeBit - 1);
            NewFloatNumber = FloatMaskChangeBit | f.FakeFloatNumber;
            std::cout << ((FloatNumber < 0) ? "0" : "1") << " ";
            for (int i = FloatBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewFloatNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits == 7) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 3:
        std::cout << "Работа выполнена\n";
        break;
    default: "Такого выбора нету";
        std::cout << "\n";
    }
}

void DoubleType() {
    double DoubleNumber;
    std::cout << "Введите число типа double: ";
    std::cin >> DoubleNumber;

    union {
        double DoubleNumber;
        unsigned long long FakeDoubleNumber;
    } d;
    d.DoubleNumber = DoubleNumber;

    int DoubleBits = sizeof(double) * 8;
    int DoubleExponentsBits = 11;
    int DoubleMantissaBits = DoubleBits - 1 - DoubleExponentsBits;

    int sign_bit = (d.FakeDoubleNumber >> (DoubleBits - 1)) & 1;
    std::cout << sign_bit << " ";

    unsigned long long ExponentBits = (d.FakeDoubleNumber >> DoubleMantissaBits) & ((1ULL << DoubleExponentsBits) - 1);
    for (int i = DoubleExponentsBits - 1; i >= 0; --i) {
        std::cout << ((ExponentBits >> i) & 1);
    }

    std::cout << " ";
    for (int i = DoubleMantissaBits - 1; i >= 0; --i) {
        int CheckBit = (d.FakeDoubleNumber >> i) & 1;
        if (CheckBit == 1) {
            std::cout << CheckBit;
        }
        else {
            std::cout << CheckBit;
        }
    }
    std::cout << "\n";
    std::cout << "Вы хотите заменить бит в числе?\n";
    std::cout << "1 - да, заменить бит на 1\n";
    std::cout << "2 - да, заменить бит на 0\n";
    std::cout << "3 - нет\n";
    int ChoiseChangeBit;
    std::cin >> ChoiseChangeBit;
    int DoubleCountChangeBit;
    int DoubleMaskChangeBit;
    int NewDoubleNumber;
    int CountBits = 0;
    std::cout << "Какой по счёту бит вы хотите заменить?\n";
    std::cin >> DoubleCountChangeBit;
    int ChangeSymbol;
    switch (ChoiseChangeBit)
    {
    case 1:
        DoubleMaskChangeBit = 1 << (DoubleCountChangeBit - 1);
        NewDoubleNumber = DoubleMaskChangeBit | d.FakeDoubleNumber;
        std::cout << ((DoubleNumber < 0) ? "1" : "0") << " ";
        for (int i = DoubleBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewDoubleNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits == 7) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            CountBits = 0;
            DoubleMaskChangeBit = 1 << (DoubleCountChangeBit - 1);
            NewDoubleNumber = DoubleMaskChangeBit | d.FakeDoubleNumber;
            std::cout << ((DoubleNumber < 0) ? "0" : "1") << " ";
            for (int i = DoubleBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewDoubleNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits == 7) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 2:
        DoubleMaskChangeBit = 1 << (DoubleCountChangeBit - 1);
        NewDoubleNumber = ~DoubleMaskChangeBit & d.FakeDoubleNumber;
        std::cout << ((DoubleNumber < 0) ? "1" : "0") << " ";
        for (int i = DoubleBits - 2; i >= 0; --i)
        {
            int CheckBit = (NewDoubleNumber >> i) & 1;
            if (CheckBit == 1) {
                std::cout << CheckBit;
            }
            else {
                std::cout << CheckBit;
            }
            if (CountBits == 7) {
                std::cout << " ";
            }
            ++CountBits;
        }
        std::cout << "\n";
        std::cout << "Хотите заменить знаковый бит?\n";
        std::cout << "1 - да\n";
        std::cout << "2 - нет\n";
        std::cin >> ChangeSymbol;
        if (ChangeSymbol == 1) {
            CountBits = 0;
            DoubleMaskChangeBit = 1 << (DoubleCountChangeBit - 1);
            NewDoubleNumber = DoubleMaskChangeBit | d.FakeDoubleNumber;
            std::cout << ((DoubleNumber < 0) ? "0" : "1") << " ";
            for (int i = DoubleBits - 2; i >= 0; --i)
            {
                int CheckBit = (~NewDoubleNumber >> i) & 1;
                if (CheckBit == 1) {
                    std::cout << CheckBit;
                }
                else {
                    std::cout << CheckBit;
                }
                if (CountBits == 7) {
                    std::cout << " ";
                }
                ++CountBits;
            }
        }
        else {
            std::cout << "Работа выполнена\n";
        }
        break;
    case 3:
        std::cout << "Работа выполнена\n";
        break;
    default: "Такого выбора нету";
        std::cout << "\n";
    }
    std::cout << "\n";
}

