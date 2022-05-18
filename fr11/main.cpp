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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "�����" << std::endl;
	const double K = 0.453;

	do
	{
		std::cout << "�����, ������� ������: ";
		double n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "���������� " << n * K << " �����������" << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� ��������" << std::endl;

	do
	{
		std::cout << "����� ����� ���������: ";
		double A;
		std::cin >> A;

		if (std::cin.fail() || A < 0)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			continue;
		}

		std::cout << "����� ����� ��������: ";
		double B;
		std::cin >> B;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			continue;
		}

		if (B <= A)
		{
			std::cout << "����� ����� ��������, ������� � ���� ���� ������" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}
		double a = 10 * A;
		double b = -B * (1 - pow(1.03, 10)) / 0.03;
		std::cout << "���� ������, ���� ����� ����� ��� " << std::fixed 
			<< std::setprecision(2) << -(a - b) << " �����" 
			<< std::setprecision(6) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "����" << std::endl;
	srand(static_cast<unsigned>(time(NULL)));

	do
	{
		int code = rand() % 1000;
		std::cout << "��� ������� ������� ������ ��� ������" << std::endl;
		_getch();

		for (int i = 0; i < 1000; ++i)
		{
			if (i == code)
			{
				std::cout << "���: " << (i < 10 ? "00" : i < 100 ? "0" : "") << i << std::endl;
				std::cout << "�������: " << i << std::endl;
			}
		}

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
