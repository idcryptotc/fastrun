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
	std::cout << "Фунты" << std::endl;
	const double K = 0.453;

	do
	{
		std::cout << "Введи, сколько фунтов: ";
		double n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "Получилось " << n * K << " килограммов" << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Жизнь студента" << std::endl;

	do
	{
		std::cout << "Введи сумму стипендии: ";
		double A;
		std::cin >> A;

		if (std::cin.fail() || A < 0)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			continue;
		}

		std::cout << "Введи сумму расходов: ";
		double B;
		std::cin >> B;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			continue;
		}

		if (B <= A)
		{
			std::cout << "Давай будем честными, расходы у тебя явно больше" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}
		double a = 10 * A;
		double b = -B * (1 - pow(1.03, 10)) / 0.03;
		std::cout << "Чтоб выжить, тебе нужно найти ещё " << std::fixed 
			<< std::setprecision(2) << -(a - b) << " денег" 
			<< std::setprecision(6) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Сейф" << std::endl;
	srand(static_cast<unsigned>(time(NULL)));

	do
	{
		int code = rand() % 1000;
		std::cout << "Для запуска команды взлома жми кнопку" << std::endl;
		_getch();

		for (int i = 0; i < 1000; ++i)
		{
			if (i == code)
			{
				std::cout << "Код: " << (i < 10 ? "00" : i < 100 ? "0" : "") << i << std::endl;
				std::cout << "Попыток: " << i << std::endl;
			}
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}
