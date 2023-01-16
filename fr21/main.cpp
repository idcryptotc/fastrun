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
    std::cout << "������ ���������" << std::endl;
    const std::vector<int> array{ 1, 1, 2, 4, 5, 9, 14, 22, 37, 54, 87, 90, 111, 243, 345 };

    do
    {
        std::cout << "1, 1, 2, 4, 5, 9, 14, 22, 37, 54, 87, 90, 111, 243, 345\n";
        std::cout << "����� �����: ";
        int n;
        std::cin >> n;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "�����..." << std::endl;
            std::cout << "��� ������ ��� 0" << std::endl;
            continue;
        }

        int i = 0;

        for (const auto &item : array)
        {
            if (item < n)
            {
                std::cout << item << " ";
                ++i;
            }
            else
            {
                std::cout << "\n������� " << i << " ���������\n";
                break;
            }
        }

        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}

void part2()
{
    std::cout << "������, �������, ������" << std::endl;

    enum Items
    {
        STONE = 1,
        SCISSORS,
        PAPER
    };

    std::map<Items, std::string> itemsString
    {
        { Items::STONE, "������" },
        { Items::SCISSORS, "�������" },
        { Items::PAPER, "������" }
    };

    do
    {
        system("cls");
        std::cout << "�������, ������� ��������������� �����:\n";
        std::cout << "1. ������\n";
        std::cout << "2. �������\n";
        std::cout << "3. ������\n";
        bool isGood = false;
        Items userItem;
        Items item = (Items)(rand() % 3 + 1);
        int codeWin = 0;

        do
        {
            switch (userItem = (Items)(_getch() - '0'))
            {
            case Items::STONE:
                std::cout << "������ : " << itemsString[item] << "\n";
                break;
            case Items::SCISSORS:
                std::cout << "������� : " << itemsString[item] << "\n";
                break;
            case Items::PAPER:
                std::cout << "������ : " << itemsString[item] << "\n";
                break;
            default:
                continue;
            }

            std::cout << "�������";

            if (userItem == item)
            {
                std::cout << "� ������!\n";
            }
            else
            {
                if (userItem + 1 == item || userItem - 2 == item)
                {
                    std::cout << " �����!\n";
                }
                else
                {
                    std::cout << " ���������!\n";
                }
            }
            
            isGood = true;
        }
        while (!isGood);

        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}

void part3()
{
    std::cout << "��������� ������" << std::endl;

    do
    {
        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}
