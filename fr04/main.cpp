#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <numeric>

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
	std::cout << "Бешеному псу 40 вёрст не крюк" << std::endl;

	do
	{
		std::cout << "Сколько вёрст пробежал бешеный пёс?" << std::endl;
		double s;
		const double k = 1.0668;
		std::cin >> s;
		std::cout << "Пёс пробежал " << s * k << " км" << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Последовательности дробных" << std::endl;

	do
	{
		std::cout << "Сколько чисел?" << std::endl;
		int n;
		std::cin >> n;
		std::cout << "Теперь сами числа (через пробел или ентер):" << std::endl;
		std::vector<double> v(n);

		for (int i = 0; i < n; ++i)
		{
			std::cin >> v[i];
		}

		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Среднее арифметическое: " << std::accumulate(v.begin(), v.end(), 0.0) / v.size() << std::endl;
		std::cout << "Минимальное: " << *std::min_element(v.begin(), v.end()) << std::endl;
		std::cout << "Максимальное: " << *std::max_element(v.begin(), v.end()) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Массив + Массив (по 5 элементов)" << std::endl;

	do
	{
		const int n = 5;
		bool isStupid = false;
		std::cout << "Введи первый отсортированный массив чисел:" << std::endl;
		std::vector<int>v1(n);

		for (int i = 0; i < n; ++i)
		{
			std::cin >> v1[i];
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Дебил, что ли..." << std::endl;
			isStupid = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
		}

		if (!std::is_sorted(v1.begin(), v1.end()))
		{
			std::cout << "Бля... А сортировка где?" << std::endl;
			isStupid = true;
		}

		std::cout << "Введи второй отсортированный массив чисел:" << std::endl;
		std::vector<int>v2(n);

		for (int i = 0; i < n; ++i)
		{
			std::cin >> v2[i];
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Дебил, что ли..." << std::endl;
			isStupid = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
		}

		if (!std::is_sorted(v2.begin(), v2.end()))
		{
			std::cout << "Хуёвая сортировка какая-то..." << std::endl;
			isStupid = true;
		}

		v1.insert(v1.end(), v2.begin(), v2.end());
		std::sort(v1.begin(), v1.end());
		std::cout << (isStupid ? "Я сделал всё, что мог:" : "Результат:") << std::endl;

		for (auto v : v1)
		{
			std::cout << v << " ";
		}

		std::cout << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());

	setlocale(LC_ALL, "Russian");
}
