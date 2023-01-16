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
        Items userItem{};
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
    
    enum Items
    {
        EASY = 1,
        NORMAL,
        HARD
    };

    do
    {
        system("cls");
        std::cout << "�������, ������� ��������������� �����:\n";
        std::cout << "1. ˸����\n";
        std::cout << "2. �������\n";
        std::cout << "3. �������\n";
        bool isGood = false;
        Items userItem{};
        std::string password{};
        std::string passwordCollection{};
        int passwordLength{};
        std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

        do
        {
            switch (userItem = (Items)(_getch() - '0'))
            {
            case Items::HARD:
                passwordCollection += "!@#$%^&*()_+=-\"�;?'\\|/<>.,";
                passwordLength += 32;
            case Items::NORMAL:
                passwordCollection += "qwertyuiopasdfghjklzxcvbnm";
                passwordLength += 10;
            case Items::EASY:
                passwordCollection += "QWERTYUIOPASDFGHJKLZXCVBNM0123456789";
                passwordLength += 8;
                break;
            default:
                continue;
            }

            std::uniform_int_distribution<int> distrib(0, passwordCollection.size() - 1);

            for (ptrdiff_t i = 0; i < passwordLength; ++i)
            {
                password += passwordCollection[distrib(rnd)];
            }

            std::cout << "������: " << password << "\n";
            isGood = true;
        }
        while (!isGood);

        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}
