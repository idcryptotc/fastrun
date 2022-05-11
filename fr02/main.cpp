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
	std::cout << "��� ����" << std::endl;

	do
	{
		std::cout << "������ �� ���� (� ��)?" << std::endl;
		double s;
		std::cin >> s;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "����� �� ������� ����� ��� (������ �� 100 ��)?" << std::endl;
		double q;
		std::cin >> q;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "����� ������ (������ �� ����)?" << std::endl;
		double c;
		std::cin >> c;
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "�����: " << (s * 2 * q / 100 * c) << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "������ �� ������!" << std::endl;
	const int discount_3 = 3;
	const double cost_for_3 = 500.;
	const int discount_5 = 5;
	const double cost_for_5 = 1000.;

	do
	{
		std::cout << "�� ������� ������?" << std::endl;
		double cost;
		std::cin >> cost;

		if (cost < cost_for_3)
		{
			std::cout << "������ ���\n�� ������ �� " << cost << std::endl;
		}
		else
		{
			if (cost < cost_for_5)
			{
				std::cout << "������ " << discount_3 << "\n�� ������ �� " << cost * double((100 - discount_3) / 100) << std::endl;
			}
			else
			{
				std::cout << "������ " << discount_5 << "\n�� ������ �� " << cost * double((100 - discount_5) / 100) << std::endl;
			}
		}

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "������-�� �����" << std::endl;

	do
	{
		int x = rand() % 1000;
		int x_arr[3] = { x / 100, x / 10 % 10, x % 10 };


		do
		{
			std::cout << "�����������: ";
			int attempt;
			std::cin >> attempt;

			if (x == attempt)
			{
				std::cout << "�� ������ " << x << std::endl;
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

				std::cout << "�������: " << count << " �� ����� ������: " << perfect << std::endl;
			}
		}
		while (true);

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
