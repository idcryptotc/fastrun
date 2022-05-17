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

#pragma warning(push)
#pragma warning(disable: 6031)

void part1();
void part2();
void part3();

int main()
{
	setlocale(LC_ALL, "Russian");
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "����������" << std::endl;
	const int _2K = 2000;

	do
	{
		std::cout << "����� ��� � �������� [-2000;0)+(0;2000]: ";
		int n;
		std::cin >> n;

		if (std::cin.fail() || n == 0 || n < -_2K || n > _2K)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << (n % 4 == 0 ? "����������" : "���������� ���") << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� �� �������" << std::endl;
	const int LIMIT = 100;

	do
	{
		std::cout << "����� ����� �������: ";
		int n;
		std::cin >> n;

		if (std::cin.fail() || n <= 0 || n > LIMIT)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "������� ������" << std::endl;
		std::vector<int> v(n);

		for (auto &x : v)
		{
			std::cin >> x;
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		system("cls");

		do
		{
			std::cout << "������ ����� �����: ";
			std::cin >> n;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				std::cout << "�����..." << std::endl;
				continue;
			}

			auto it = std::find(v.begin(), v.end(), n);

			if (it == v.end())
			{
				std::cout << "������ ����� ���" << std::endl;
			}
			else
			{
				std::cout << "� ������� ���������� ��������� �����" << std::endl;
			}

			break;
		}
		while (true);

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "���� \"5 �� 3\"" << std::endl;
	std::vector<std::vector<int> > v
	{
		{6,7,8},
		{7,8,9},
		{6,9,10},
		{6,9,8},
		{7,6,10}
	};
	std::vector<int> v1(3);
	srand(static_cast<unsigned>(time(NULL)));

	do
	{
		std::cout << "������ �����: " << std::endl;

		for (const auto &s : v)
		{
			static std::size_t i = 1;
			i = i > v.size() ? 1 : i;
			std::cout << "����� �" << i++ << ": ";

			for (const auto &e : s)
			{
				std::cout << e << "\t";
			}

			std::cout << std::endl;
		}

		do
		{
			std::cout << "����� ����� �� ������: ";

			for (auto &x : v1)
			{
				std::cin >> x;
			}

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				std::cout << "�����..." << std::endl;
				continue;
			}

			auto it = std::find(v.begin(), v.end(), v1);

			if (it == v.end())
			{
				std::cout << "������ ������ ���" << std::endl;
				continue;
			}

			int comp_n = rand() % 5;
			int sum1 = 0;
			std::cout << "��������� ������ �����: ";
			
			for (const auto &a : v[comp_n])
			{
				std::cout << a << " ";
				sum1 += a;
			}

			std::cout << "����� " << sum1 << std::endl;
			int sum2 = 0;
			std::cout << "�� ������ �����: ";

			for (const auto &a : v1)
			{
				std::cout << a << " ";
				sum2 += a;
			}

			std::cout << "����� " << sum2 << std::endl;

			std::cout << (sum1 > sum2 ? "�� ��������" : sum1 < sum2 ? "�� �������" : "�����") << std::endl;
			break;
		}
		while (true);

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

