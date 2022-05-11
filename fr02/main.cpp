#include <iostream>
#include <conio.h>
#include <limits>

#pragma warning(push)
#pragma warning(disable: 6031)

void part1();
void part2();
void part3();

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)));
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "Про дачу" << std::endl;

	do
	{
		std::cout << "Далеко ли дача (в км)?" << std::endl;
		double s;
		std::cin >> s;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Много ли бензина тачка жрёт (литров на 100 км)?" << std::endl;
		double q;
		std::cin >> q;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Почём бензин (рублей за литр)?" << std::endl;
		double c;
		std::cin >> c;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Итого: " << (s * 2 * q / 100 * c) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Набери на скидку!" << std::endl;
	const int discount_3 = 3;
	const double cost_for_3 = 500.;
	const int discount_5 = 5;
	const double cost_for_5 = 1000.;

	do
	{
		std::cout << "На сколько набрал?" << std::endl;
		double cost;
		std::cin >> cost;

		if (cost < cost_for_3)
		{
			std::cout << "Скидки нет\nТы набрал на " << cost << std::endl;
		}
		else
		{
			if (cost < cost_for_5)
			{
				std::cout << "Скидка " << discount_3 << "\nТы набрал на " << cost * double((100 - discount_3) / 100) << std::endl;
			}
			else
			{
				std::cout << "Скидка " << discount_5 << "\nТы набрал на " << cost * double((100 - discount_5) / 100) << std::endl;
			}
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "Угадай-ка число" << std::endl;

	do
	{
		int x = rand() % 1000;
		int x_arr[3] = { x / 100, x / 10 % 10, x % 10 };


		do
		{
			std::cout << "Предполагай: ";
			int attempt;
			std::cin >> attempt;

			if (x == attempt)
			{
				std::cout << "Ты угадал " << x << std::endl;
				break;
			}
			else
			{
				int attempt_arr[3] = { attempt / 100, attempt / 10 % 10, attempt % 10 };
				int count = 0;
				int perfect = 0;

				for (int i = 0; i < 3; ++i)
				{
					for (int j = 0; j < 3; ++j)
					{
						if (x_arr[i] == attempt_arr[j])
						{
							++count;

							if (i == j)
							{
								++perfect;
							}
						}
					}
				}

				std::cout << "Угадано: " << count << " На своих местах: " << perfect << std::endl;
			}
		}
		while (true);

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}
