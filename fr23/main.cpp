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
    part1();
    part2();
    part3();
    return 0;
}

void part1()
{
    std::cout << "Кривое инвертирование строки" << std::endl;
    char ch = ' ';

    do
    {
        std::cout << "Введи строку:\n";
        std::string str;
        std::getline(std::cin, str);

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "Почти..." << std::endl;
            std::cout << "Для выхода жми 0" << std::endl;
            continue;
        }
        
        std::vector<ptrdiff_t> spaceIndexes;

        for (auto it = str.begin(); it != str.end(); ++it)
        {
            if (*it == ch)
            {
                spaceIndexes.push_back(it - str.begin());
            }
        }

        int strSize = str.size();
        auto startIter = str.begin();
        std::locale loc("ru");
        ptrdiff_t it = 0;

        while (true)
        {
            it += std::find_if(startIter, str.end(), [&](char c)
            {
                return (bool)std::ispunct(c, loc);
            }) - startIter;

            if (it >= str.size())
            {
                break;
            }
            startIter = str.begin();
            std::advance(startIter, it);
            str.insert(startIter, ch);
            startIter = str.begin();
            it += 2;
            std::advance(startIter, it);
            str.insert(startIter, ch);
            startIter = str.begin();
            it += 1;
            std::advance(startIter, it);
        }

        const std::regex whitespaceRegex("\\s+");
        auto str1 = std::sregex_token_iterator(str.begin(), str.end(), whitespaceRegex, -1);
        auto str2 = std::sregex_token_iterator();
        std::vector<std::string> result;
        std::copy(str1, str2, std::back_inserter(result));
        std::reverse(result.begin(), result.end());
        std::string stringResult{ "" };

        for (auto &item : result)
        {
            ptrdiff_t size = stringResult.size();

            if (spaceIndexes.size() > 0 && size + 1 == strSize - *(spaceIndexes.rbegin()))
            {
                stringResult += " ";
                spaceIndexes.pop_back();
            }

            stringResult += item;
        }

        std::cout << "Результат:\n" << stringResult << "\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}

std::vector<int> findDuplicates(std::vector<int> array)
{
    std::set<int> duplicates;
    std::sort(array.begin(), array.end());
    std::set<int> distinct(array.begin(), array.end());
    std::set_difference(array.begin(), array.end()
        , distinct.begin(), distinct.end()
        , std::inserter(duplicates, duplicates.end()));
    return std::vector<int>(duplicates.begin(), duplicates.end());
}

void part2()
{
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribSize(10, 20);
    std::uniform_int_distribution<int> distribNum(0, 9);
    std::cout << "Массивная задача" << std::endl;

    do
    {
        ptrdiff_t size1 = distribSize(rnd);
        ptrdiff_t size2 = distribSize(rnd);
        std::vector<int> array1;
        
        for (ptrdiff_t i = 0; i < size1; ++i)
        {
            int num = distribNum(rnd);
            array1.push_back(num);
            std::cout << num << ' ';
        }

        std::vector<int> array1D{ findDuplicates(array1) };
        std::cout << "\n";
        std::vector<int> array2;

        for (ptrdiff_t i = 0; i < size2; ++i)
        {
            int num = distribNum(rnd);
            array2.push_back(num);
            std::cout << num << ' ';
        }

        std::vector<int> array2D{ findDuplicates(array2) };
        std::cout << "\n";
        std::vector<int> array;
        array.reserve(array1D.size() + array2D.size());
        array.insert(array.end(), array1D.begin(), array1D.end());
        array.insert(array.end(), array2D.begin(), array2D.end());
        array = findDuplicates(array);
        std::sort(array.begin(), array.end());
        auto last = std::unique(array.begin(), array.end());
        array.erase(last, array.end());

        for (const auto &i : array)
        {
            std::cout << i << ' ';
        }

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

        std::cout << "УРА!!! ПОБЕДА!!!\nДля выхода жми 0" << std::endl;
    }
    while ('0' != _getch());
}
