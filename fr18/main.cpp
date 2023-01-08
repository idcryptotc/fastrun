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
	//part1();
	//part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "������" << std::endl;

	do
	{
		std::cout << "����� ������� � ���� ����, ��������?\n";
		double pricePerKilo;
		std::cin >> pricePerKilo;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "� ������� ����������� �� ����?\n";
		double kilo;
		std::cin >> kilo;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "�� ��������: " << pricePerKilo * kilo << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� ���������! � �� ��������� ����..." << std::endl;

	do
	{
		std::cout << "����� ������ ����� �����" << std::endl;
		std::vector<int> array;
		int num;

		while (true)
		{
			std::cin >> num;
			
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				break;
			}

			array.push_back(num);

			if (std::cin.peek() == '\n')
			{
				break;
			}
		}

		if (array.size() <= 0)
		{
			std::cout << "\n��� ������ ��� 0" << std::endl;
			continue;
		}

		std::map<int, bool> result;

		for (const auto &item : array)
		{
			if (result.find(item) != result.end())
			{
				result[item] = true;
			}
			else
			{
				result[item] = false;
			}
		}

		std::cout << "����" << std::endl;

		for (const auto &item : array)
		{
			std::cout << item << " ";
		}

		std::cout << "\n�����" << std::endl;

		for (const auto &item : array)
		{
			if (result.find(item) != result.end() && result[item] == false)
			{
				std::cout << item << " ";
			}
		}

		std::cout << "\n��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "��������" << std::endl;
	const int COUNT_WAGONS = 18;
	const int COUNT_PLACES = 36;
	std::vector<std::vector<bool>> places(COUNT_WAGONS, std::vector<bool>(COUNT_PLACES));

	for (auto &wagon : places)
	{
		for (auto place : wagon)
		{
			place = rand() % 2;
			std::cout << place << " ";
		}

		std::cout << "\n";
	}

	do
	{
		std::cout << "����� ����� �����?\n";
		int w;
		std::cin >> w;
		
		if (std::cin.fail() || std::cin.peek() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		if (COUNT_WAGONS >= w && w > 0)
		{
			std::cout << "��������� ����: "
				<< COUNT_PLACES - std::accumulate(places[w - 1].begin(), places[w - 1].end(), 0)
				<< std::endl;
		}
		else
		{
			std::cout << "���� ����� �� ��������" << std::endl;
		}

		std::cout << "\n��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
