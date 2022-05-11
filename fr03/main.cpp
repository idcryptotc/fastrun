#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <Windows.h>

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
	std::cout << "��������" << std::endl;

	do
	{
		std::cout << "������� ������ ��������?" << std::endl;
		double s;
		std::cin >> s;
		std::cout << "� �� ������� �� ��� ��������?" << std::endl;
		double t, mm, ss;
		std::cin >> t;
		mm = modf(t, &ss);
		mm *= 100;
		std::cout << "������, �������� � ���� "
			<< std::fixed << std::setprecision(2)
			<< ((s / 1000) / ((ss * 60 + mm) / 3600))
			<< std::setprecision(6) << " ��/�" << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� ������ �������������" << std::endl;

	do
	{
		std::cout << "����� ���������� �����������" << std::endl;
		int n;
		std::cin >> n;
		std::cout << "�����: " << (n + 1) * n << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part3()
{
	std::cout << "��������������" << std::endl;
	std::vector<std::string> v =
	{
		".-"   , "-..."  , ".--"    , "--."  ,
		"-.."  , "."     , "...-"   , "--.." ,
		".."   , ".---"  , "-.-"    , ".-.." ,
		"--"   , "-."    , "---"    , ".--." ,
		".-."  , "..."   , "-"      , "..-"  ,
		"..-." , "...."  , "-.-."   , "---." ,
		"----" , "--.-"  , ".--.-." , "-.--" ,
		"-..-" , "..-.." , "..--"   , ".-.-"
	};

	do
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::cout << "����� �����:" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		int len = str.length();
		std::string result;

		for (int i = 0; i < len; ++i)
		{
			if (str[i] == ' ')
			{
				result += "   ";
				continue;
			}

			if (str[i] == '�' || str[i] == '�')
			{
				result += v['�' - '�'];
				continue;
			}

			if (str[i] >= '�' && str[i] <= '�')
			{
				result += v[(str[i] < '�' ? str[i] + 32 : str[i]) - '�'] + " ";
			}
		}

		for (std::size_t i = 0; i < result.length(); ++i)
		{
			std::cout << result[i];
			result[i] == '.' ? Beep(300, 150) : result[i] == '-' ? Beep(300, 300) : Beep(0, 150);
		}

		std::cout << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());

	setlocale(LC_ALL, "Russian");
}
