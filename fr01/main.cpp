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
	std::cout << "���� ������" << std::endl;
	std::cout << "����� ������� ������ � ������ � ���� ����������" << std::endl;

	do
	{
		std::cout << "����� ������:" << std::endl;
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
				result = "�� �����...";
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
							result = "�� �����...";
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
			result = "������ �� �����...";
		}
		else
		{
			result = "�� �����...";
		}

		std::cout << result << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	do
	{
		std::cout << "����������" << std::endl;
		std::cout << "����... ������� �� ����� ������������� ������ �����? \n��, ������. ��, ��� 100500, ���� ������. � ������������ �� ����" << std::endl;
		int n = 0;
		std::cin >> n;
		std::cout << (n < 1 ? "�� �� ��������?" : "") << (n >= 1 ? "����� ����" : "") << (n > 10 ? ", ����..." : "") << std::endl;

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
					std::cout << "����� �����: ";
					std::cin >> current;
				}
				while ([=]()-> bool { if (current < 0) { std::cout << "��, ��������, ������...\n����� �����...\n"; } return current > 0 ? false : true; }());

				min = current < min ? current : min;
			}

			std::cout << "������ ������ ��, �� ��������� �������: " << min << std::endl;
		}

		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	do
	{
		std::cout << "��������� ������..." << std::endl;
		std::cout << "�� ��� ������ ������, ��? �� 12. ����� ����� �� 1 �� 12:" << std::endl;
		int n;
		std::cin >> n;
		std::cout << (n < 1 || n > 12 ? "-_-" : "")
			<< (n < 1 || n > 12
				? ""
				: ([=]()
					{
						switch (n % 12 / 3)
						{
						case 0: return "����";
						case 1: return "�����";
						case 2: return "����";
						case 3: return "�����";
						default: return "";
						}
					}()))
			<< std::endl;
					std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}
