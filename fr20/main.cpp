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
    std::cout << "����� ���! ����... ������" << std::endl;

    do
    {
        std::cout << "������� ������� ���� (����� ����� ���): ";
        int day, month, year;
        bool is366 = false, isMonth30 = false, isMonth31 = false;
        int dayCount = 0;
        std::cin >> day >> month >> year;

        if (std::cin.fail() || [&]()
            {
                is366 = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
                bool isMonth = month > 0 && month < 13;
                std::vector<int> month30{ 4, 6, 9, 11 };
                isMonth30 = std::any_of(month30.begin(), month30.end(), [&](const int &a) { return month == a; });
                isMonth31 = !isMonth30 && month != 2;
                dayCount = isMonth30 ? 30 : isMonth31 ? 31 : is366 ? 29 : 28;
                bool isDay = day > 0 && day <= dayCount;
                return !(isDay && isMonth && year > 0);
            }())
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "�����..." << std::endl;
            std::cout << "��� ������ ��� 0" << std::endl;
            continue;
        }

        std::string timeInterval = "";
        ++day;
        day %= dayCount + 1;
        month += day == 0 ? (std::cout << "��������� ���� ", timeInterval = "������! ", day = 1, 1) : 0;
        month %= 13;
        year += month == 0 ? (timeInterval = "����! ", month = 1, 1) : 0;
        std::cout << timeInterval << "������ "
            << std::setw(2) << std::setfill('0') << day << "."
            << std::setw(2) << std::setfill('0') << month << "."
            << std::setw(4) << std::setfill('0') << year;
        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}

void part2()
{
    std::cout << "�� ����" << std::endl;

    do
    {
        std::cout << "����� ����� �����" << std::endl;
        int n;
        std::cin >> n;

        if (std::cin.fail() || n < 0)
        {
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            std::cout << "�����..." << std::endl;
            std::cout << "��� ������ ��� 0" << std::endl;
            continue;
        }

        std::cout << "Hex: 0x" << std::hex << n << std::dec;
        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}

void part3()
{
    std::cout << "������, 100 ��." << std::endl;
    std::pair<std::string, std::string> gamers ("�����", "���������");
    const int COUNT = 100;
    std::cout << "�������: �� �����, ������������� ���������� 100 ������, ����\n"
        << "�������� ���������� ����� �� ��������� ������: �� ����� �����\n"
        << "� �� ����� ������. ����������� ���, ��� ���� ��������� ������.\n";

    do
    {
        std::cout << "��������� ��� ������ ���. ��� ��-����\n";
        _getch();
        bool isPlayer = rand() % 2;
        int count = COUNT;
        int round = 1;
        int step;
        bool isFnish = false;

        while (count > 0)
        {
            system("cls");
            std::cout << "����� " << round++ << ". �������� ������: " << count << std::endl;

            for (ptrdiff_t i = 0; i < 2; ++i)
            {
                std::cout << "�����: " << (isPlayer ? gamers.first : gamers.second) << std::endl;

                if (isPlayer)
                {
                    while (true)
                    {
                        std::cout << gamers.first << " ����: ";
                        std::cin >> step;

                        if (std::cin.fail() || step < 1 || step > 10)
                        {
                            std::cin.clear();
                            std::cin.ignore(INT32_MAX, '\n');
                            std::cout << "�� �� �������� ����" << std::endl;
                            continue;
                        }

                        if (count - step < 0)
                        {
                            std::cout << "��� �������" << std::endl;
                            continue;
                        }

                        count -= step;

                        if (count == 0)
                        {
                            std::cout << gamers.first << " ��������" << std::endl;
                            std::cout << gamers.second << " �������" << std::endl;
                            isFnish = true;
                        }

                        break;
                    }
                }
                else
                {
                    if (count > 11)
                    {
                        step = rand() % 10 + 1;
                    }
                    else
                    {
                        if (count == 1)
                        {
                            step = 1;
                        }
                        else
                        {
                            step = count - 1;
                        }
                    }

                    std::cout << gamers.second << " ����: " << step << std::endl;
                    count -= step;

                    if (count == 0)
                    {
                        std::cout << gamers.second << " ��������" << std::endl;
                        std::cout << gamers.first << " �������" << std::endl;
                        isFnish = true;
                    }
                }

                if (isFnish)
                {
                    break;
                }

                std::cout << "�������� ������: " << count << std::endl;
                isPlayer = !isPlayer;
            }

            if (isFnish)
            {
                break;
            }

            std::cout << "����� ������\n";
            _getch();
        }

        std::cout << "����� ����\n";
        std::cout << "\n��� ������ ��� 0" << std::endl;
    }
    while ('0' != _getch());
}
