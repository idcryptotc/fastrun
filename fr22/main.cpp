#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <numeric>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <time.h>
#include <fstream>
#include <set>
#include <map>
#include <random>
#include <locale>
#include <chrono>

#pragma warning(push)
#pragma warning(disable: 6031)
#pragma warning(push)
#pragma warning(disable: 26495)

void part1();
void part2();
void part3();

int f(int, int, int);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    part1();
    part2();
    part3();
    return 0;
}

void part1()
{
    std::cout << "Делители" << std::endl;

    do
    {
        std::cout << "Введи число: ";
        int n;
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "Почти..." << std::endl;
            std::cout << "Для выхода жми 0" << std::endl;
            continue;
        }

        std::cout << (n == 0 ? "0" : "1 ");
        int half_n = n / 2;

        for (ptrdiff_t i = 2; i <= half_n; ++i)
        {
            if (n % i == 0)
            {
                std::cout << i << " ";
            }
        }

        if (n > 1)
        {
            std::cout << n << "\n";
        }

        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

void part2()
{
    std::cout << "Фибоначчя" << std::endl;
    const unsigned long long A = 0;
    const unsigned long long B = 1;

    do
    {
        std::cout << "Введи сколько надо чисел: ";
        unsigned long long a = A;
        unsigned long long b = B;
        int n;
        std::cin >> n;

        if (std::cin.fail() || 0 > n || 501 < n)
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "Почти..." << std::endl;
            std::cout << "Для выхода жми 0" << std::endl;
            continue;
        }

        switch (n)
        {
        case 0:
            std::cout << "Хм... и чё пришёл?\n";
            break;
        case 1:
            std::cout << "0\n";
            break;
        case 2:
            std::cout << "0 1\n";
            break;
        default:
            std::cout << "0 1 ";
            bool isA = true;

            for (ptrdiff_t i = 2; i < n; ++i)
            {
                isA
                    ? std::cout << (a += b) << " "
                    : std::cout << (b += a) << " ";
                isA = !isA;
            }
        }

        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

void part3()
{
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distrib(1000, 9999);

    do
    {
        system("cls");
        std::cout << "Село Коровобычье" << std::endl;
        std::cout << "Корова - угадана цифра и её место" << std::endl;
        std::cout << "Бык - угадана цифра, но не её место" << std::endl;
        std::string number = std::to_string(distrib(rnd));
        std::string result;
        int step;

        do
        {
            do
            {
                std::cout << "Введи число (4 знака):\n";
                std::cin >> step;

                if (std::cin.fail() || 9999 < step || 1000 > step)
                {
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    std::cout << "Почти..." << std::endl;
                    continue;
                }

                break;
            }
            while (true);

            bool checks[4]{};
            std::string checker = number;
            result = std::to_string(step);
            int cows = 0;
            int bulls = 0;

            for (ptrdiff_t i = 0; i < 4; ++i)
            {
                if (result[i] == checker[i])
                {
                    ++cows;
                    checker[i] = 'c';
                    checks[i] = true;
                    continue;
                }
            }

            for (ptrdiff_t i = 0; i < 4; ++i)
            {
                if (checks[i])
                {
                    continue;
                }

                auto iter = std::find(checker.begin(), checker.end(), result[i]);

                if (iter == checker.end())
                {
                    continue;
                }

                if (!(iter - checker.begin() == i || checks[i]))
                {
                    ++bulls;
                    *iter = 'b';
                    checks[i] = true;
                    continue;
                }
            }

            std::cout << "Коров: " << cows << " Быков: " << bulls << "\n";
        }
        while (result != number);

        std::cout << "УРА!!! ПОБЕДА!!!\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}
