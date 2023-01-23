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
#include <regex>

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
    //part1();
    part2();
    part3();
    return 0;
}

void part1()
{
    std::cout << "Чётные в массиве" << std::endl;
    std::vector<int> array{ 1, 6, 9, 18, 27, 36, 51, 68, 82, 101 };
    std::vector<int> result{};

    do
    {
        std::cout << "Массив: 1 6 9 18 27 36 51 68 82 101\nЧётные: ";

        for (const auto &i : array)
        {
            if (!(i & 1))
            {
                result.push_back(i);
                std::cout << i << " ";
            }
        }

        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

void part2()
{
    std::cout << "Дубли в файлах" << std::endl;
    std::ifstream fin1("prime_numbers.txt");
    std::ifstream fin2("happy_numbers.txt");

    if (!fin1.is_open())
    {
        std::cout << "Жопа... файл не открылся..." << std::endl;
        return;
    }

    if (!fin2.is_open())
    {
        std::cout << "Жопа... файл не открылся..." << std::endl;
        return;
    }

    std::vector<int> f1{};
    std::vector<int> f2{};
    std::string tmp{};

    while (std::getline(fin1, tmp))
    {
        f1.push_back(stoi(tmp));
    }

    while (std::getline(fin2, tmp))
    {
        f2.push_back(stoi(tmp));
    }

    fin1.close();
    fin2.close();

    do
    {
        
        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

void part3()
{

    do
    {
        std::cout << "Я угадаю число от 0 до 100, загаданное тобой" << std::endl;
        Sleep(500);
        std::cout << "Нет, писать его в меня не надо" << std::endl;
        Sleep(500);
        std::cout << "Да, чтоб я не подсмотрел" << std::endl;
        Sleep(500);
        std::cout << "Ну, как? Загадал?" << std::endl;
        Sleep(500);
        std::cout << "Если загадал, жмякни чё-нить" << std::endl;
        _getch();
        int number{};
        std::pair<int, int>limits{ 0, 101 };
        char userAnswer{};
        bool isStop = false;
        bool isCheater = false;

        while (!isStop)
        {
            number = (limits.first + limits.second) / 2;

            if (isCheater = (limits.first == number && number != 0)
                || (number == limits.second && number != 100))
            {
                break;
            }

            std::cout << "Ваше число: " << number << " ?\n";
            std::cout << "1. Да!\n";
            std::cout << "2. Нет! Загаданное число больше\n";
            std::cout << "3. Нет! Загаданное число меньше\n";

            while (true)
            {
                userAnswer = _getch();

                if ('0' < userAnswer && '4' > userAnswer)
                {
                    break;
                }
            }

            switch (userAnswer)
            {
            case '1':
                isStop = true;
                break;
            case '2':
                limits.first = number;
                break;
            case '3':
                limits.second = number;
                break;
            }
        }

        std::cout << (isCheater ? "Ты обманщик!" : "УРА!!! ПОБЕДА!!!") << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}
