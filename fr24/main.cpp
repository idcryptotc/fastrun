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
    //part2();
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
        size_t f1size = f1.size();
        size_t f2size = f2.size();
        int if1{}, jf2{};
        bool isChangef1 = true;
        bool isChangef2 = true;
        bool isStopf1 = false;
        bool isStopf2 = false;

        for (size_t i = 0, j = 0; !isStopf1 || !isStopf2;)
        {
            if (f1size > i)
            {
                if (isChangef1)
                {
                    if1 = f1[i];
                    isChangef1 = false;
                }
            }
            else
            {
                isStopf1 = true;
            }

            if (f2size > j)
            {
                if (isChangef2)
                {
                    jf2 = f2[j];
                    isChangef2 = false;
                }
            }
            else
            {
                isStopf2 = true;
            }

            if (if1 == jf2)
            {
                f1[i] = -1;
                ++i;
                f2[j] = -1;
                ++j;
                isChangef1 = true;
                isChangef2 = true;
                continue;
            }
            else
            {
                if (if1 > jf2 && !isStopf2)
                {
                    ++j;
                    isChangef2 = true;
                    continue;
                }
                else
                {
                    if (if1 < jf2 && !isStopf1)
                    {
                        ++i;
                        isChangef1 = true;
                        continue;
                    }
                }
            }

            break;
        }

        f1.erase(std::remove(f1.begin(), f1.end(), -1), f1.end());
        f2.erase(std::remove(f2.begin(), f2.end(), -1), f2.end());
        std::ofstream fout1("prime_numbers_out.txt");
        std::ofstream fout2("happy_numbers_out.txt");

        if (!fout1.is_open())
        {
            std::cout << "Жопа... файл не открылся..." << std::endl;
            return;
        }

        if (!fout2.is_open())
        {
            std::cout << "Жопа... файл не открылся..." << std::endl;
            return;
        }

        for (const auto &i : f1)
        {
            fout1 << i << "\n";
        }

        for (const auto &j : f2)
        {
            fout2 << j << "\n";
        }

        fout1.close();
        fout2.close();

        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

float x;
HDC hDC = GetDC(GetConsoleWindow());
HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

void draw(int wrongsCount)
{
    SelectObject(hDC, Pen);

    switch (wrongsCount)
    {
        case 7:		// Правая нога
        {
            MoveToEx(hDC, 425, 125, NULL);
            LineTo(hDC, 440, 140);
        }
        case 6:		// Левая нога
        {
            MoveToEx(hDC, 425, 125, NULL);
            LineTo(hDC, 410, 140);
        }
        case 5:		// Правая рука
        {
            MoveToEx(hDC, 425, 95, NULL);
            LineTo(hDC, 440, 110);
        }
        case 4:		// Левая рука
        {
            MoveToEx(hDC, 425, 95, NULL);
            LineTo(hDC, 410, 110);
        }
        case 3:		// Туловище
        {
            MoveToEx(hDC, 425, 95, NULL);
            LineTo(hDC, 425, 125);
        }
        case 2:		// Петля
        {
            MoveToEx(hDC, 425, 50, NULL);
            LineTo(hDC, 425, 75);

            for (x = -10.0f; x <= 10.0f; x += 0.01f)
            {
                MoveToEx(hDC, static_cast<int>(x + 425), static_cast<int>(sqrt(100 - x * x) + 85), NULL);
                LineTo(hDC, static_cast<int>(x + 425), static_cast<int>(sqrt(100 - x * x) + 85));
            }

            for (x = -10.0f; x <= 10.0f; x += 0.01f)
            {
                MoveToEx(hDC, static_cast<int>(x + 425), static_cast<int>(-sqrt(100 - x * x) + 85), NULL);
                LineTo(hDC, static_cast<int>(x + 425), static_cast<int>(-sqrt(100 - x * x) + 85));
            }
        }
        case 1:		// Балка
        {
            MoveToEx(hDC, 335, 50, NULL);
            LineTo(hDC, 428, 50);
            MoveToEx(hDC, 350, 75, NULL);
            LineTo(hDC, 375, 50);
        }
        case 0:		// Столб
        {
            MoveToEx(hDC, 300, 200, NULL);
            LineTo(hDC, 490, 200);
            MoveToEx(hDC, 350, 200, NULL);
            LineTo(hDC, 350, 50);
            MoveToEx(hDC, 335, 200, NULL);
            LineTo(hDC, 350, 185);
            MoveToEx(hDC, 365, 200, NULL);
            LineTo(hDC, 350, 185);
        }
    }
}

void part3()
{
    std::cout << "ВисилиЦЦа" << std::endl;
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    const int MAX_WRONG = 7;  // Максимум ошибок
    std::string fileName{ "RussianWords1000.txt" };
    std::string inputLine{};
    std::ifstream fin(fileName);

    if (!fin.is_open())
    {
        std::cout << "Файл " << fileName << " не может быть открыт.";
        _getch();
        return;
    }

    std::vector<std::string> words;  // Коллекция слов

    while (std::getline(fin, inputLine))
    {
        words.push_back(inputLine);
    }

    std::uniform_int_distribution<int> distrib(0, words.size() - 1);
    std::locale loc("ru");

    do
    {
        system("cls");
        const std::string THE_WORD = words[distrib(rnd)];
        int wrongsCount = -1;
        std::string hiddenWord(THE_WORD.size(), '-');
        std::string usedLetters = "";

        while ((wrongsCount < MAX_WRONG) && (hiddenWord != THE_WORD))
        {
            std::cout << "Готов повеситься? Удачи!\n";
            std::cout << "Ты называл буквы:\n" << usedLetters << std::endl;
            std::cout << "\nЭто то, что ты знаешь:\n" << hiddenWord << std::endl;
            std::cout << "\n\nПробуй: ";
            draw(wrongsCount);
            char guess;

            while (true)
            {
                guess = _getch();

                if (std::isupper(guess, loc))
                {
                    std::cout << "\nПиши маленькими буквами!\nПробуй: ";
                    continue;
                }

                if (std::islower(guess, loc)
                    && usedLetters.find(guess) == std::string::npos)
                {
                    std::cout << guess;
                    break;
                }
            }

            usedLetters += guess;
            system("cls");
            Sleep(20);

            if (THE_WORD.find(guess) != std::string::npos)
            {
                for (size_t i = 0; i < THE_WORD.length(); ++i)
                {
                    if (THE_WORD[i] == guess)
                    {
                        hiddenWord[i] = guess;
                    }
                }
            }
            else
            {
                ++wrongsCount;
            }
        }

        system("cls");
        Sleep(20);
        draw(wrongsCount);

        if (wrongsCount == MAX_WRONG)
        {
            std::cout << "\nТы удачно повесился!";
        }
        else
        {
            std::cout << "\nМожешь уходить!";
        }

        std::cout << "\nЗагаданное слово: " << THE_WORD << std::endl;
        std::cout << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}
