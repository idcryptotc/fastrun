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
	//part2();
	//part3();
	return 0;
}

void part1()
{
	std::cout << "Високосные" << std::endl;
	const int _2K = 2000;

	do
	{
		std::cout << "Введи год в пределах [-2000;0)+(0;2000]: ";
		int n;
		std::cin >> n;

		if (std::cin.fail() || n == 0 || n < -_2K || n > _2K)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << (n % 4 == 0 ? "Високосный" : "Нормальный год") << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Палиндром-" << std::endl;

	do
	{
		std::cout << "Введи натуральное четырёхзначное число:" << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Рейтинг бакалавров" << std::endl;

	do
	{
		std::cout << "Твой средний балл диплома: " << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

