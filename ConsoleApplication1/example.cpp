#include <iostream>
#include "Complex.h"

Complex readComplex() {
    try
    {
        double re;
        double im;
        std::cout << "Введите действительную часть re: ";
        std::cin >> re;
        if (std::cin.fail()) {
            throw "error";
        }
        std::cout << "Введите мнимую часть im: ";
        std::cin >> im;
        if (std::cin.fail()) {
            throw "error";
        }
        return Complex(re, im);
    }
    catch(...)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Попробуйте ещё раз" << std::endl;
        return readComplex();
    }
}


Complex readComplexString() {
    try
    {
        std::string complexString;
        std::cout << "Введите число: ";
        std::cin >> complexString;
        if (std::cin.fail()) {
            throw "error";
        }
        std::cout << complexString;
        return Complex(complexString);
    }
    catch (...)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Попробуйте ещё раз" << std::endl;
        return readComplexString();
    }
}

void test()
{
    int swt = 0;

    std::cout << "Выберите тип действия" << std::endl
        << "1. Сложение" << std::endl
        << "2. Вычитаение" << std::endl
        << "3. Умножение" << std::endl
        << "4. Деление" << std::endl
        << "5. <" << std::endl
        << "6. >" << std::endl
        << "7. <=" << std::endl
        << "8. >=" << std::endl
        << "9. ^" << std::endl;

    std::cin >> swt;

    std::cout << "Введите первое число: " << std::endl;
    Complex a = readComplex();
    std::cout << "Введено число:" << a.ToString() << std::endl;


    Complex b;
    int c;
    std::cout << "Введите второе число: " << std::endl;
    if (swt < 9)
    {
        b = readComplex();
        std::cout << "Введено число:" << b.ToString() << std::endl;
    }
    else
    {
        std::cin >> c;
        std::cout << "Введено число:" << c << std::endl;
    }

    Complex res;
    bool resBool;
    std::cout << "В ответе получилось: ";
    switch (swt)
    {
    case 1: 
        res = a + b;
        std::cout << res.ToString() << std::endl;
        break;
    case 2:
        res = a - b;
        std::cout << res.ToString() << std::endl;
        break;
    case 3:
        res = a * b;
        std::cout << res.ToString() << std::endl;
        break;
    case 4:
        try
        {
            res = a / b;
            std::cout << res.ToString() << std::endl;
        }
        catch (int e)
        {
            if (e == 0)
            {
                std::cout << "Деление на 0 невозможно" << std::endl;
            }
        }
        catch (...)
        {
            std::cout << "Unknown error" << std::endl;
        }
        break;
    case 5:
        resBool = a < b;
        std::cout << resBool << std::endl;
        break;
    case 6:
        resBool = a > b;
        std::cout << resBool << std::endl;
        break;
    case 7:
        resBool = a <= b;
        std::cout << resBool << std::endl;
        break;
    case 8:
        resBool = a >= b;
        std::cout << resBool << std::endl;
        break;
    case 9:
        res = a ^ c;
        std::cout << res.ToString() << std::endl;
        break;
    default: 
        std::cout << "Произошла ошибка, попробуйте ещё раз." << std::endl;
        return;
    }
}

void testWhile()
{
    int active = 1;
    while (active > 0)
    {
        test();
        std::cout << "Выполнить ещё одну операцию?" << std::endl
            << "0 - завершить" << std::endl
            << "1 - продолжить" << std::endl;
        std::cin >> active;
    }
}

int main()
{
    setlocale(0, "");
    testWhile();
}

