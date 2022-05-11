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
	std::cout << "�������" << std::endl;

	do
	{
		std::cout << "����� ����� �� 1 �� 99: ";
		unsigned n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�� ���, ������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (n < 1 || n > 99)
		{
			std::cout << "�� ���, ������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << n << " ����"
			<< (n % 10 == 1 && n % 100 != 11
				? "���"
				: (n % 10 == 2 || n % 10 == 3 || n % 10 == 4) && n % 100 != 12 && n % 100 != 13 && n % 100 != 14
				? "���"
				: "��") << std::endl;

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	const static int _4 = 4;
	std::cout << "���������-" << _4 << std::endl;

	do
	{
		std::cout << "����� ����������� ������������� �����:" << std::endl;
		std::string n;
		std::getline(std::cin, n);

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�� ���, ������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (n.length() != _4)
		{
			std::cout << "������� �������..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (!(std::isdigit(n[0]) && std::isdigit(n[1]) && std::isdigit(n[2]) && std::isdigit(n[3])))
		{
			std::cout << "������ ��-�����? ������ ��������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (n[0] == n[3] && n[1] == n[2])
		{
			std::cout << "���������, ������" << std::endl;
		}
		else
		{
			std::cout << "��, �� ���������" << std::endl;
		}

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "������� ����������" << std::endl;
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
		std::cout << "���� ������� ���� �������: " << std::endl;
		double avg;
		std::cin >> avg;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�� ���, ������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (avg < MIN_AVG)
		{
			std::cout << "�������� ����� ��..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (avg > MAX_AVG)
		{
			std::cout << "��-�-�... ����������� �� �������..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "���� ������ �� �������������: " << std::endl;
		double stage;
		std::cin >> stage;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�� ���, ������?" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
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
					std::cout << "�� ���� ����� ���� � ������������, ��..." << std::endl;
				}
			}
		}

		std::cout << (score >= SCORE ? "���� �����!" : "��, �� �������") 
			<< "\n������ ��� �� ������: " << score << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

