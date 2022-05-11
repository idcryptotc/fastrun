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
	std::cout << "������� �����" << std::endl;

	do
	{
		std::cout << "����� 2 ����� (�����): ";
		int a = 0, b = 0;
		std::cin >> a >> b;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "� �� �� ����� ���?" << std::endl;
		}

		std::cout << a << (a > b ? " ������ " : a == b ? " ����� " : " ������ ") << b << std::endl;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "��������" << std::endl;

	do
	{
		std::cout << "���� �� �����, � ���" << std::endl;
		std::string str = "������, ������!";

		for (std::size_t i = 0; i < str.length(); ++i)
		{
			std::cout << str[i];
			Sleep(200);
		}

		std::cout << "\n��� ������ ��� 0" << std::endl;
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
	std::cout << "������ �� �����������" << std::endl;
	std::list<Ticket> lt =
	{
		{"������"    , 12  , "����"      , "21.10.2030"}
		,{"���-����"  , 123 , "ϸ��"      , "22.10.2030"}
		,{"���������" , 122 , "�������"   , "24.10.2030"}
		,{"�����"     , 112 , "�����"     , "21.10.2023"}
		,{"������"    , 142 , "�������"   , "21.11.2030"}
		,{"�����"     , 412 , "��������"  , "21.09.2030"}
		,{"�����"     , 172 , "�������"   , "21.01.2030"}
		,{"������"    , 712 , "������"    , "20.10.2030"}
		,{"��������"  , 912 , "��������"  , "19.10.2030"}
		,{"�����"     , 312 , "���������" , "23.10.2030"}
	};
	char n;
	void add(std::list<Ticket> &);
	void del(std::list<Ticket> &);
	void getall(std::list<Ticket> &);

	do
	{
		std::cout << "� ��� ���� " << lt.size() << " ������" << std::endl;
		std::cout << "1 - ��������\n2 - �������\n3 - �������� ���\n0 - �����" << std::endl;
		setlocale(LC_ALL, "Russian");
		n = _getche();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << std::endl;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "������ ������... ����� �����" << std::endl;
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
				std::cout << "�����..." << std::endl;
				break;
			}
		}
	}
	while ('0' != n);
}

void add(std::list<Ticket> &lt)
{
	std::cout << "��, ����� �������" << std::endl;
	Ticket t{ "",0,"","" };
	std::cout << "���� �����: ";
	std::cin >> t.destination;
	std::cout << "����� �����: ";
	std::cin >> t.flightNumber;
	std::cout << "���: ";
	std::cin >> t.FIO;
	std::cout << "����� �����: ";
	std::cin >> t.date;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "�� ���� ���������" << std::endl;
		return;
	}

	lt.push_back(t);
	std::cout << "���������" << std::endl;
}

void del(std::list<Ticket> &lt)
{
	std::cout << "��, ����� ������" << std::endl;
	std::cout << "����� ��:\n1 - ������ ����������\n2 - ���\n3 - ������ �����" << std::endl;
	setlocale(LC_ALL, "Russian");
	char n = _getche();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << std::endl;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "�� �����" << std::endl;
		n = 0;
	}

	std::list<Ticket>::iterator x;

	switch (n)
	{
	case '1':
		{
			std::string f;
			std::cout << "����� ����������: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.destination == f; });
			break;
		}
	case '2':
		{
			std::string f;
			std::cout << "���: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.FIO == f; });
			break;
		}
	case '3':
		{
			unsigned f;
			std::cout << "�����: ";
			std::cin >> f;
			x = std::find_if(lt.begin(), lt.end(), [f](const Ticket &t)->bool { return t.flightNumber == f; });
			break;
		}
	default:
		{
			std::cout << "�� ����� �����-�� �����..." << std::endl;
			return;
		}
	}

	if (x == lt.end())
	{
		std::cout << "�� �����" << std::endl;
		return;
	}
	else
	{
		std::cout << "�����:" << std::endl;
		std::cout << "����� ����������: " << x->destination << std::endl;
		std::cout << "���: " << x->FIO << std::endl;
		std::cout << "����� �����: " << x->flightNumber << std::endl;
		std::cout << "����: " << x->date << std::endl;
		std::cout << "�������? 0 - ��: ";
		setlocale(LC_ALL, "Russian");
		char d = _getche();
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << std::endl;

		if (d == '0')
		{
			lt.erase(x);
			std::cout << "�������" << std::endl;
		}
		else
		{
			std::cout << "��, � �����, ����� �����" << std::endl;
		}
	}
}

void getall(std::list<Ticket> &lt)
{
	std::cout << "���, ��� �� �����:" << std::endl;

	if (lt.size() > 0)
	{
		for (auto t : lt)
		{
			std::cout << "\n����� ����������: " << t.destination << std::endl;
			std::cout << "���: " << t.FIO << std::endl;
			std::cout << "����� �����: " << t.flightNumber << std::endl;
			std::cout << "����: " << t.date << std::endl;
		}
	}
	else
	{
		std::cout << "������..." << std::endl;
	}

	std::cout << std::endl;
}
