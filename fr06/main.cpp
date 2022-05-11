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

#pragma warning(push)
#pragma warning(disable: 6031)

void part1();
void part2();
void part3();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "Сравним числа" << std::endl;

	do
	{
		std::cout << "Введи 2 числа (целых): ";
		int a = 0, b = 0;
		std::cin >> a >> b;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "И чё ты такое ввёл?" << std::endl;
		}

		std::cout << a << (a > b ? " больше " : a == b ? " равно " : " меньше ") << b << std::endl;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Телеграф" << std::endl;

	do
	{
		std::cout << "Ничё не вводи, я сам" << std::endl;
		std::string str = "Привет, водила!";

		for (std::size_t i = 0; i < str.length(); ++i)
		{
			std::cout << str[i];
			Sleep(200);
		}

		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

struct Ticket
{
	std::string destination;
	unsigned flightNumber;
	std::string FIO;
	std::string date;
};

void part3()
{
	std::cout << "Заявки на авиавбилеты" << std::endl;
	std::list<Ticket> lt =
	{
		{"Москва"    , 12  , "Иван"      , "21.10.2030"}
		,{"Нью-Йорк"  , 123 , "Пётр"      , "22.10.2030"}
		,{"Караганда" , 122 , "Василий"   , "24.10.2030"}
		,{"Париж"     , 112 , "Ольга"     , "21.10.2023"}
		,{"Лондон"    , 142 , "Евгения"   , "21.11.2030"}
		,{"Пекин"     , 412 , "Пенелопа"  , "21.09.2030"}
		,{"Токио"     , 172 , "Арнольд"   , "21.01.2030"}
		,{"Мадрид"    , 712 , "Штраус"    , "20.10.2030"}
		,{"Урюпинск"  , 912 , "Магеллан"  , "19.10.2030"}
		,{"Киров"     , 312 , "Елизавета" , "23.10.2030"}
	};
	char n;
	void add(std::list<Ticket> &);
	void del(std::list<Ticket> &);
	void getall(std::list<Ticket> &);

	do
	{
		std::cout << "У нас есть " << lt.size() << " заявок" << std::endl;
		std::cout << "1 - Добавить\n2 - Удалить\n3 - Показать все\n0 - Выход" << std::endl;
		setlocale(LC_ALL, "Russian");
		n = _getche();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Ёбаный карась... давай снова" << std::endl;
			n = 0;
		}

		switch (n)
		{
		case '1':
			{
				add(lt);
				break;
			}
		case '2':
			{
				del(lt);
				break;
			}
		case '3':
			{
				getall(lt);
				break;
			}
		default:
			{
				std::cout << "Блять..." << std::endl;
				break;
			}
		}
	}
	while ('0' != n);
}

void add(std::list<Ticket> &lt)
{
	std::cout << "Ну, давай добавим" << std::endl;
	Ticket t{ "",0,"","" };
	std::cout << "Куда летим: ";
	std::cin >> t.destination;
	std::cout << "Номер рейса: ";
	std::cin >> t.flightNumber;
	std::cout << "ФИО: ";
	std::cin >> t.FIO;
	std::cout << "Когда летим: ";
	std::cin >> t.date;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Не буду добавлять" << std::endl;
		return;
	}

	lt.push_back(t);
	std::cout << "Добавлено" << std::endl;
}

void del(std::list<Ticket> &lt)
{
	std::cout << "Ну, давай удалим" << std::endl;
	std::cout << "Найти по:\n1 - Пункту назначения\n2 - ФИО\n3 - Номеру рейса" << std::endl;
	setlocale(LC_ALL, "Russian");
	char n = _getche();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << std::endl;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Не нашёл" << std::endl;
		n = 0;
	}

	std::list<Ticket>::iterator x;

	switch (n)
	{
	case '1':
		{
			std::string f;
			std::cout << "Пункт назначения: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.destination == f; });
			break;
		}
	case '2':
		{
			std::string f;
			std::cout << "ФИО: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.FIO == f; });
			break;
		}
	case '3':
		{
			unsigned f;
			std::cout << "Номер: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.flightNumber == f; });
			break;
		}
	default:
		{
			std::cout << "Ты херню какую-то нажал..." << std::endl;
			return;
		}
	}

	if (x == lt.end())
	{
		std::cout << "Не нашёл" << std::endl;
		return;
	}
	else
	{
		std::cout << "Нашёл:" << std::endl;
		std::cout << "Пункт назначения: " << x->destination << std::endl;
		std::cout << "ФИО: " << x->FIO << std::endl;
		std::cout << "Номер рейса: " << x->flightNumber << std::endl;
		std::cout << "Дата: " << x->date << std::endl;
		std::cout << "Удаляем? 0 - да: ";
		setlocale(LC_ALL, "Russian");
		char d = _getche();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << std::endl;

		if (d == '0')
		{
			lt.erase(x);
			std::cout << "Удалено" << std::endl;
		}
		else
		{
			std::cout << "Ну, и ладно, пусть летит" << std::endl;
		}
	}
}

void getall(std::list<Ticket> &lt)
{
	std::cout << "Вот, что мы имеем:" << std::endl;

	if (lt.size() > 0)
	{
		for (auto t : lt)
		{
			std::cout << "\nПункт назначения: " << t.destination << std::endl;
			std::cout << "ФИО: " << t.FIO << std::endl;
			std::cout << "Номер рейса: " << t.flightNumber << std::endl;
			std::cout << "Дата: " << t.date << std::endl;
		}
	}
	else
	{
		std::cout << "Никого..." << std::endl;
	}

	std::cout << std::endl;
}
