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
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "Тема первая" << std::endl;
	std::cout << "Будем вводить разное и искать в этом бутерброды" << std::endl;

	do
	{
		std::cout << "Введи строку:" << std::endl;
		std::string s;
		std::cin >> s;
		char c1 = '\0', c2 = '\0';
		int len = static_cast<int>(s.length() / 2.0 + 0.5);
		int last = s.length() - 1;
		std::string result;

		for (int i = 0; i < len; ++i)
		{
			if (s[i] != s[last - i])
			{
				result = "Не бутер...";
				c1 = '\0';
				c2 = '\0';
				break;
			}

			if (c1 == 0)
			{
				c1 = s[i];
				continue;
			}
			else
			{
				if (c1 == s[i] && c2 == 0)
				{
					continue;
				}
				else
				{
					if (c2 == 0)
					{
						c2 = s[i];
						continue;
					}
					else
					{
						if (c2 == s[i])
						{
							continue;
						}
						else
						{
							result = "Не бутер...";
							c1 = '\0';
							c2 = '\0';
							break;
						}
					}
				}
			}
		}

		if (c1 != c2 && c1 != 0 && c2 != 0)
		{
			result = "Похоже на бутер...";
		}
		else
		{
			result = "Не бутер...";
		}

		std::cout << result << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	do
	{
		std::cout << "Продолжаем" << std::endl;
		std::cout << "Итак... Сколько ты готов положительных ввести чисел? \nДа, руками. Да, все 100500, если хочешь. Я ограничивать не буду" << std::endl;
		int n = 0;
		std::cin >> n;
		std::cout << (n < 1 ? "Да ты одарённый?" : "") << (n >= 1 ? "Начнём ввод" : "") << (n > 10 ? ", хули..." : "") << std::endl;

		if (n > 0)
		{
			int current;
			int min = INT32_MAX;
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');

			for (int i = 0; i < n; ++i)
			{
				do
				{
					std::cout << "Введи число: ";
					std::cin >> current;
				}
				while ([=]()-> bool { if (current < 0) { std::cout << "Ты, наверное, шутишь...\nДавай снова...\n"; } return current > 0 ? false : true; }());

				min = current < min ? current : min;
			}

			std::cout << "Пройдя сквозь всё, ты получаешь минимум: " << min << std::endl;
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	do
	{
		std::cout << "Последний вопрос..." << std::endl;
		std::cout << "Ты про месяцы слышал, не? Их 12. Введи цифру от 1 до 12:" << std::endl;
		int n;
		std::cin >> n;
		std::cout << (n < 1 || n > 12 ? "-_-" : "")
			<< (n < 1 || n > 12
				? ""
				: ([=]()
					{
						switch (n % 12 / 3)
						{
						case 0: return "Зима";
						case 1: return "Весна";
						case 2: return "Лето";
						case 3: return "Осень";
						default: return "";
						}
					}()))
			<< std::endl;
					std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}
