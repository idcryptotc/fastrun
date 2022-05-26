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
	//part1();
	//part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "����� ������ \"�������\"" << std::endl;

	do
	{
		std::cout << "����� ������:" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		std::cout << "����� ������ " << (str.end() - str.begin()) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "���������" << std::endl;
	std::cout << "������ ��������� ��� ���������� ����������� �� $24 � 1826 �. " << std::endl;
	std::cout << "������ ���� �� � ��������� ����� ��������� �� �����, " << std::endl;
	std::cout << "���� �� ��� 24 ������� ���� �������� ����� � ���� ��� 6% " << std::endl;
	std::cout << "�������� ������?" << std::endl;
	std::time_t t = std::time(NULL);
	struct tm buf {};
	localtime_s(&buf, &t);
	int year = 1900 + buf.tm_year;
	const int START_YEAR = 1826;
	const double K = 1.06;
	const int BASE_SUM = 24;

	do
	{
		std::cout << "��������� ���:\t" << START_YEAR << std::endl;
		std::cout << "������� ���:\t" << year << std::endl;
		std::cout << std::fixed << std::setprecision(2) 
			<< "���� ����� $" << -BASE_SUM * (1 - pow(K, year - START_YEAR)) / (K - 1.)
			<< std::setprecision(6) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "������ ����" << std::endl;

	do
	{
		std::cout << "����� �����:" << std::endl;
		std::string str;
		std::cin >> str;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
