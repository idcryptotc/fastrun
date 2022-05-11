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
	std::cout << "������ ���� �� �����" << std::endl;

	do
	{
		std::cout << "����� ���������� �����: ";
		int n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "���" << std::endl;
		}

		std::cout << n << " �����"
			<< (n % 10 == 1 && n % 100 != 11
				? "�"
				: n % 10 > 1 && n % 10 < 5 && n % 100 != 12 && n % 100 != 13 && n % 100 != 14
				? "�"
				: "")
			<< ": " << n / 60 << " �. " << n % 60 << " ���." << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "�������� ����" << std::endl;

	do
	{
		std::cout << "����� ��������� �����?" << std::endl;
		double n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "������-�����, ��?" << std::endl;
		}

		std::cout << "���\t���������\n(�)\t(���.)" << std::fixed << std::setprecision(2) << std::endl;

		for (int i = 100; i <= 1000; i += 100)
		{
			std::cout << i << "\t" << i * n / 1000 << std::endl;
		}

		std::cout << std::setprecision(6) << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	HWND hwnd = GetConsoleWindow();
	HDC dc = GetDC(hwnd);
	HDC hdc = NULL, hDC;
	HBITMAP hScreen, oldBmp = NULL;
	int screen_x = GetDeviceCaps(dc, HORZRES);
	int screen_y = GetDeviceCaps(dc, VERTRES);
	std::cout << "������" << std::endl;

	do
	{
		std::cout << "����� ���������� ������: ";
		int n;
		std::cin >> n;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "-_-?" << std::endl;
			n = 10;
		}

		system("cls");
		double angleArrowHour = -270. + 6. * (n % 60);

		for (int i = n % 60 + 1; i > 0; --i)
		{
			if (angleArrowHour < -360.0)
			{
				angleArrowHour = 0.0;
			}

			hDC = CreateCompatibleDC(dc);
			hScreen = CreateCompatibleBitmap(dc, screen_x, screen_y);
			oldBmp = (HBITMAP)SelectObject(hDC, hScreen);
			PatBlt(hDC, 100, 100, 400, 400, BLACKNESS);
			Ellipse(hDC, 100, 100, 400, 400);
			MoveToEx(hDC, 250, 250, 0);
			LineTo(hDC, 110 * (int)cos(angleArrowHour * M_PI / 180) + 250, -110 * (int)sin(angleArrowHour * M_PI / 180) + 250);
			BitBlt(dc, 0, 0, screen_x, screen_y, hDC, 0, 0, SRCCOPY);
			SelectObject(hDC, oldBmp);
			DeleteDC(hDC);
			
			if (i != 1)
			{
				Sleep(1000);
			}

			angleArrowHour -= 6;
		}

		Beep(100, 1000);
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());

	DeleteDC(dc);
}
