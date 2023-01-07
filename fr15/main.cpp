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
	std::cout << "Длина строки \"ручками\"" << std::endl;

	do
	{
		std::cout << "Введи строку:" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		std::cout << "Длина строки " << (str.end() - str.begin()) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Манхэттен" << std::endl;
	std::cout << "Остров Манхэттен был приобретен поселенцами за $24 в 1826 г. " << std::endl;
	std::cout << "Каково было бы в настоящее время состояние их счета, " << std::endl;
	std::cout << "если бы эти 24 доллара были помещены тогда в банк под 6% " << std::endl;
	std::cout << "годового дохода?" << std::endl;
	std::time_t t = std::time(NULL);
	struct tm buf {};
	localtime_s(&buf, &t);
	int year = 1900 + buf.tm_year;
	const int START_YEAR = 1826;
	const double K = 1.06;
	const int BASE_SUM = 24;

	do
	{
		std::cout << "Стартовый год:\t" << START_YEAR << std::endl;
		std::cout << "Текущий год:\t" << year << std::endl;
		std::cout << std::fixed << std::setprecision(2)
			<< "Куча денег $" << -BASE_SUM * (1 - pow(K, year - START_YEAR)) / (K - 1.)
			<< std::setprecision(6) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

// Перемешка строки
// Принимает строку
// Возвращает пару строк: индексы и перемешанную строку
std::pair<std::string, std::string> mix(std::string);

void part3()
{
	std::cout << "Скачки букв" << std::endl;

	do
	{
		std::cout << "Введи слово (не больше 9 букв):" << std::endl;
		std::string str;
		std::cin >> str;

		if (std::cin.fail() || str.length() > 9)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::pair<std::string, std::string> s{ "", str };
		int count = 0;

		// Так делать не надо, но очень хотелось :)
		while (str != (std::cout << "[" << count++ << "] " << (s = mix(s.second)).first << " " << s.second << std::endl, s.second));

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

std::pair<std::string, std::string> mix(std::string str)
{
	std::size_t l = str.length();
	std::string indexes = str;

	for (std::size_t i = 0; i < l; ++i)
	{
		indexes[i] = i + '0';
	}

	int r;

	for (std::size_t i = 0; i < l; ++i)
	{
		r = rand() % l;

		if (i == r)
		{
			continue;
		}

		str[i] = str[i] ^ str[r];
		str[r] = str[i] ^ str[r];
		str[i] = str[i] ^ str[r];
		indexes[i] = indexes[i] ^ indexes[r];
		indexes[r] = indexes[i] ^ indexes[r];
		indexes[i] = indexes[i] ^ indexes[r];
	}

	return { indexes, str };
}