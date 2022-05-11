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
	std::cout << "Копейки" << std::endl;

	do
	{
		std::cout << "Введи число от 1 до 99: ";
		unsigned n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Ты что, дурной?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (n < 1 || n > 99)
		{
			std::cout << "Ты что, дурной?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << n << " копе"
			<< (n % 10 == 1 && n % 100 != 11
				? "йка"
				: (n % 10 == 2 || n % 10 == 3 || n % 10 == 4) && n % 100 != 12 && n % 100 != 13 && n % 100 != 14
				? "йки"
				: "ек") << std::endl;

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	const static int _4 = 4;
	std::cout << "Палиндром-" << _4 << std::endl;

	do
	{
		std::cout << "Введи натуральное четырёхзначное число:" << std::endl;
		std::string n;
		std::getline(std::cin, n);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Ты что, дурной?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (n.length() != _4)
		{
			std::cout << "Считать научись..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (!(std::isdigit(n[0]) && std::isdigit(n[1]) && std::isdigit(n[2]) && std::isdigit(n[3])))
		{
			std::cout << "Откуда не-цифры? пальцы дрогнули?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (n[0] == n[3] && n[1] == n[2])
		{
			std::cout << "Палиндром, однако" << std::endl;
		}
		else
		{
			std::cout << "Не, не палиндром" << std::endl;
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Рейтинг бакалавров" << std::endl;
	const double SCORE = 45.;
	const double MIN_AVG = 3.;
	const double MAX_AVG = 5.;
	const double eps = 0.0001;
	double score;

	enum class Stage
	{
		NONE = 1,
		ALMOST_TWO = 13,
		TWO_FIVE = 16,
		MORE = 100500
	};

	do
	{
		std::cout << "Твой средний балл диплома: " << std::endl;
		double avg;
		std::cin >> avg;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Ты что, дурной?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (avg < MIN_AVG)
		{
			std::cout << "Маловато будет же..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (avg > MAX_AVG)
		{
			std::cout << "Эм-м-м... пятибальная же система..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "Стаж работы по специальности: " << std::endl;
		double stage;
		std::cin >> stage;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Ты что, дурной?" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		if (stage <= eps)
		{
			score = avg * (int)Stage::NONE;
		}
		else
		{
			if (stage < 2)
			{
				score = avg * (int)Stage::ALMOST_TWO;
			}
			else
			{
				if (stage <= 5)
				{
					score = avg * (int)Stage::TWO_FIVE;
				}
				else
				{
					score = avg * (int)Stage::MORE;
					std::cout << "Не знаю зачем тебе в магистратуру, но..." << std::endl;
				}
			}
		}

		std::cout << (score >= SCORE ? "Тебя взяли!" : "Не, не возьмут") 
			<< "\nПотому что ты набрал: " << score << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

