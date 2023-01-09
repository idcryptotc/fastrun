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
	std::cout << "Буквы, цифры. И ничего больше" << std::endl;

	do
	{
		std::cout << "Введи предложение с знаками препинания, или нет\n";
		std::string message;
		std::getline(std::cin, message);
		std::locale loc("ru");
		message.erase(
			std::remove_if(
				message.begin(), message.end()
				, [&](unsigned char a)
				{
					return !(isupper(a, loc) || islower(a, loc) || isdigit(a, loc));
				})
			, message.end());
		std::cout << "\n" << message << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Индекс большого" << std::endl;

	do
	{
		std::cout << "Введи адекватное целое число" << std::endl;
		int n;
		std::cin >> n;

		if (std::cin.fail() || n <= 0)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (n > 20)
		{
			std::cout << "Ну-у... не хочешь адекватно, дело твоё :)" << std::endl;
		}

		std::vector<int> numbers(n);

		for (auto &number : numbers)
		{
			number = rand() % 200 - 100;
			std::cout << number << " ";
		}

		std::cout << "\n";
		int index = std::minmax_element(numbers.begin(), numbers.end()).second - numbers.begin();
		std::cout << "Индекс: " << index << " -> " << numbers[index] << "\n";
		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Таблица умножения" << std::endl;

	do
	{
		std::cout << "Жми чё-нить для начала\n";
		_getch();
		const int COUNT = 10;
		int state = 0;

		for (ptrdiff_t i = 0; i < COUNT; ++i)
		{
			system("cls");
			int a = rand() % 9 + 1;
			int b = rand() % 9 + 1;
			std::cout << a << " * " << b << " = ";
			int result;
			std::cin >> result;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				result = -1;
			}

			if (result == a * b)
			{
				++state;
			}
		}

		std::cout << "Результат: ";

		switch (state)
		{
		case 10:
			std::cout << "Отлично\n";
			break;
		case 9:
		case 8:
			std::cout << "Хорошо\n";
			break;
		case 7:
		case 6:
			std::cout << "Удовлетворительно\n";
			break;
		default:
			std::cout << "Плохо\n";
		}

		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}
