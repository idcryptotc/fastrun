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
	std::cout << "Чётно-кратно-пятые" << std::endl;

	do
	{
		std::cout << "Вот они:" << std::endl;

		for (int i = 2; i < 100; i += 2)
		{
			if (!(i % 5))
			{
				std::cout << i << " ";
			}
		}

		std::cout << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Счастье, 13" << std::endl;
	const int THIRTEEN = 13;

	do
	{
		std::cout << "Количество билетов: ";
		int count_13_3 = 0;

		for (int i = 0; i < 10; ++i)
		{
			for (int j = i; j < 10; ++j)
			{
				for (int k = j; k < 10; ++k)
				{
					if (i + j + k == THIRTEEN)
					{
						count_13_3 += 3 + (i != j && j != k && k != i ? 3 : 0);
					}
				}
			}
		}

		std::cout << count_13_3 * count_13_3 << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Монетка" << std::endl;
	enum class Chance { heads, tails };
	std::string heads = "Орёл";
	std::string tails = "Решка";

	do
	{
		std::ofstream file("result.txt");

		if (!file.is_open())
		{
			std::cout << "Жопа... файл не открылся..." << std::endl;
		}

		std::pair<int, int> count{ 0,0 };

		for (int i = 0; i < 100; ++i)
		{
			switch (Chance(rand() % 2))
			{
			case Chance::heads:
				file << heads << std::endl;
				++count.first;
				break;
			case Chance::tails:
				file << tails << std::endl;
				++count.second;
				break;
			}
		}

		std::cout << "Орлов: " << count.first << std::endl;
		std::cout << "Решек: " << count.second << std::endl;
		file << "Орлов: " << count.first << " Решек: " << count.second << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
		file.close();
	}
	while ('0' != _getch());
}
