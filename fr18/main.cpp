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
	//part1();
	//part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "Яблоки" << std::endl;

	do
	{
		std::cout << "Почём яблочки в твоём мире, странник?\n";
		double pricePerKilo;
		std::cin >> pricePerKilo;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "И сколько килограммов ты взял?\n";
		double kilo;
		std::cin >> kilo;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "Ты потратил: " << pricePerKilo * kilo << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Долой дубликаты! И их оригиналы тоже..." << std::endl;

	do
	{
		std::cout << "Введи массив целых чисел" << std::endl;
		std::vector<int> array;
		int num;

		while (true)
		{
			std::cin >> num;
			
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				break;
			}

			array.push_back(num);

			if (std::cin.peek() == '\n')
			{
				break;
			}
		}

		if (array.size() <= 0)
		{
			std::cout << "\nДля выхода жми 0" << std::endl;
			continue;
		}

		std::map<int, bool> result;

		for (const auto &item : array)
		{
			if (result.find(item) != result.end())
			{
				result[item] = true;
			}
			else
			{
				result[item] = false;
			}
		}

		std::cout << "Было" << std::endl;

		for (const auto &item : array)
		{
			std::cout << item << " ";
		}

		std::cout << "\nСтало" << std::endl;

		for (const auto &item : array)
		{
			if (result.find(item) != result.end() && result[item] == false)
			{
				std::cout << item << " ";
			}
		}

		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Поездато" << std::endl;
	const int COUNT_WAGONS = 18;
	const int COUNT_PLACES = 36;
	std::vector<std::vector<bool>> places(COUNT_WAGONS, std::vector<bool>(COUNT_PLACES));

	for (auto &wagon : places)
	{
		for (auto place : wagon)
		{
			place = rand() % 2;
			std::cout << place << " ";
		}

		std::cout << "\n";
	}

	do
	{
		std::cout << "Какой вагон нужен?\n";
		int w;
		std::cin >> w;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (COUNT_WAGONS >= w && w > 0)
		{
			std::cout << "Свободных мест: "
				<< COUNT_PLACES - std::accumulate(places[w - 1].begin(), places[w - 1].end(), 0)
				<< std::endl;
		}
		else
		{
			std::cout << "Этот вагон не доступен" << std::endl;
		}

		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}
