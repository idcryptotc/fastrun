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

#include "chaters.h"

#pragma warning(push)
#pragma warning(disable: 6031)
#pragma warning(push)
#pragma warning(disable: 26495)

void part1();
void part2();
void part3();


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
	std::cout << "Переворот! Строки..." << std::endl;

	do
	{
		std::cout << "Введи, строку: " << std::endl;
		std::string str;
		std::getline(std::cin, str);
		std::reverse(str.begin(), str.end());
		std::cout << str << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "День недели" << std::endl;
	std::vector<std::string> v{ "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };

	do
	{
		std::cout << "Введи номер дня в году: ";
		unsigned n;
		std::cin >> n;

		if (std::cin.fail() || n > 366)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "Сегодня " << v[n % 7] << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Чатик" << std::endl;
	const int THREE = 3;
	const int FIVE = 5;
	std::vector<Human *> v(FIVE);

	do
	{
		for (int i = 0; i < FIVE; ++i)
		{
			v[i] = Human::create(HumanType(rand() % 3));
		}

		std::cout << "Начнём. Участники:" << std::endl;

		for (const auto &h : v)
		{
			std::cout << h->sayAboutSelf() << std::endl;
		}

		for (std::size_t i = 0; i < v.size() - 1; ++i)
		{
			for (std::size_t j = i + 1; j < v.size(); ++j)
			{
				std::cout << v[i]->sayHello(*v[j]) << std::endl;
				std::cout << v[j]->sayHello(*v[i]) << std::endl;
			}
		}

		std::cout << "Для выхода жми 0" << std::endl;

		for (int i = 0; i < FIVE; ++i)
		{
			Human::destroy(v[i]);
		}
	}
	while ('0' != _getch());
}
