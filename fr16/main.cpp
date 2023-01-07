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
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "���������� ������� ������� ����� ���������" << std::endl;

	do
	{
		std::cout << "����� ������ ����� �����:" << std::endl;
		std::vector<int> arrayInt;
		int tempInput;
		
		while (true)
		{
			std::cin >> tempInput;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				break;
			}

			arrayInt.push_back(tempInput);
		}

		if (arrayInt.size() <= 0)
		{
			std::cout << "����� �� ����������" << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		std::cout << "���������� �������: ";
		int min = INT32_MAX;

		for (ptrdiff_t *i = &arrayInt[0]; i < &arrayInt[0] + arrayInt.size(); ++i)
		{
			if (*i < min)
			{
				min = *i;
			}
		}

		std::cout << min << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "����� � �������, �������� ������" << std::endl;

	do
	{
		std::cout << "����� ������:" << std::endl;
		std::string string;
		std::getline(std::cin, string);
		
		if (std::cin.fail() || string.empty())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "�����..." << std::endl;
			std::cout << "��� ������ ��� 0" << std::endl;
			continue;
		}

		string[0] = ' ';
		string[string.length() - 1] = '.';
		std::cout << "���������:" << std::endl;
		std::cout << string << std::endl;
		std::cout << "��� ������ ��� 0" << std::endl;
	}
	while ('0' != _getch());
}

std::vector<std::pair<std::string, bool>> names =
{
	{ "�����", false }
	, { "���������", false }
	, { "��������", false }
	, { "������", false }
	, { "�����", false }
	, { "���������", false }
	, { "�������", false }
	, { "�����", false }
	, { "�����", false }
	, { "������", false }
	, { "�����", false }
	, { "�������", false }
	, { "��������", false }
	, { "����", false }
	, { "�������", false }
	, { "������", false }
	, { "������", false }
	, { "����������", false }
	, { "�����", false }
	, { "����", false }
	, { "��������", false }
	, { "������", false }
	, { "���������", false }
	, { "�������", false }
	, { "�������", false }
	, { "����", false }
	, { "���������", false }
	, { "�����", false }
	, { "�������", false }
	, { "����", false }
	, { "������", false }
	, { "�����", false }
	, { "�������", false }
	, { "�������", false }
	, { "������", false }
	, { "������", false }
	, { "�������", false }
	, { "����������", false }
	, { "������", false }
	, { "������", false }
	, { "�����", false }
	, { "������", false }
	, { "��������", false }
	, { "��������", false }
	, { "��������", false }
	, { "������", false }
	, { "��������", false }
	, { "����", false }
	, { "������", false }
	, { "����", false }
};

const std::vector<std::string> SUBJECT_NAMES =
{
	"����������������"
	, "����������"
	, "������"
};

const unsigned COUNT_STUDENTS = 40;
const unsigned COUNT_WEEKS = 35;
const unsigned COUNT_SUBJECTS = 3;

struct Subject
{
	std::string name;
	unsigned int score;
};

struct Student
{
	std::string name;

	Student()
	{
		ptrdiff_t index;

		do
		{
			index = rand() % names.size();
		}
		while (names[index].second);

		names[index].second = true;
		name = names[index].first;
	}
};

struct Week
{
	Subject subjects[COUNT_SUBJECTS];
	bool isGood;

	Week()
	{
		isGood = true;

		for (ptrdiff_t i = 0; i < COUNT_SUBJECTS; ++i)
		{
			subjects[i].name = SUBJECT_NAMES[i];
			subjects[i].score = rand() % 4 + 2;

			if (subjects[i].score < 4)
			{
				isGood = false;
			}
		}
	}
};

struct Row
{
	Student student;
	Week weeks[COUNT_WEEKS];
	unsigned int goodWeekCounter;

	Row()
	{
		goodWeekCounter = 0;

		for (auto &week : weeks)
		{
			if (week.isGood)
			{
				++goodWeekCounter;
			}
		}
	}
};

struct Statement
{
	std::vector<Row> rows;

	Statement() : rows(COUNT_STUDENTS)
	{
		std::sort(rows.begin(), rows.end()
			, [](const Row &a, const Row &b)
			{
				return a.goodWeekCounter > b.goodWeekCounter;
			});
		
		for (auto &name : names)
		{
			name.second = false;
		}
	}

	std::vector<Row *> getGreatStudent()
	{
		std::vector<Row *> greats;
		for (auto &great : rows)
		{
			if (rows[0].goodWeekCounter == great.goodWeekCounter)
			{
				greats.push_back(&great);
			}
			else
			{
				break;
			}
		}

		return greats;
	}
};

void part3()
{
	std::cout << "����������" << std::endl;

	do
	{
		Statement statement;
		std::vector<Row *> greats = statement.getGreatStudent();
		std::cout << "������ ��������: " << std::endl;
		
		if (greats[0]->goodWeekCounter > 0)
		{
			for (const auto &great : greats)
			{
				std::cout << great->student.name << std::endl;
			}
		}
		else
		{
			std::cout << "������� �������, ����... -_-" << std::endl;
		}

		std::cout << "������ �� 4 � 5: " << greats[0]->goodWeekCounter << std::endl;
		std::cout << "\n��� ������ ��� 0\n" << std::endl;
	}
	while ('0' != _getch());
}
