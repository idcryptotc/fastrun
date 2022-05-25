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
	std::cout << "���������" << std::endl;

	do
	{
		std::cout << "������� ����� ��� ����� ������������: ";
		unsigned long long n = 1;
		unsigned minutes;
		std::cin >> minutes;

		if (std::cin.fail() || minutes > 60)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "���������� �������� " << (n << minutes) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� � �������" << std::endl;

	do
	{
		int h, m, s;
		std::cout << "����� �����:" << std::endl;
		std::cout << "���� [0-23]: ";
		std::cin >> h;
		std::cout << "������ [0-59]: ";
		std::cin >> m;
		std::cout << "������� [0-59]: ";
		std::cin >> s;

		if (std::cin.fail() || h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0 )
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "������ ������: " << f(h, m, s) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

int f(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}

void part3()
{
	std::cout << "�����" << std::endl;

	do
	{
		std::ofstream ofile("stars.txt");

		if (!ofile.is_open())
		{
			std::cout << "���� � ���� �� ������" << std::endl;
			ofile.close();
			break;
		}

		int count = rand() % 9 + 1;

		for (int i = 0; i < count; ++i)
		{
			ofile << (rand() % 72 + 1) << " ";
		}

		ofile << std::endl;
		ofile.close();
		std::ifstream ifile("stars.txt");
		std::vector<int> v;
		int n;
		std::cout << "����� � �����: ";
		
		while (ifile >> n)
		{
			v.push_back(n);
			std::cout << n << " ";
		}

		std::cout << std::endl;
		ifile.close();
		std::cout << "�� ����� �����:" << std::endl;

		for (const auto &s : v)
		{
			std::cout << s << "\t";
			std::cout 
				<< std::setw(static_cast<long long>(s) + static_cast<long long>(1)) 
				<< std::setfill('*') << " " << std::endl;
		}

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
