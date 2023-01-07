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
	std::cout << "Наименьший элемент массива через указатель" << std::endl;

	do
	{
		std::cout << "Введи массив целых чисел:" << std::endl;
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
			std::cout << "Чисел не обнаружено" << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		std::cout << "Наименьший элемент: ";
		int min = INT32_MAX;

		for (ptrdiff_t *i = &arrayInt[0]; i < &arrayInt[0] + arrayInt.size(); ++i)
		{
			if (*i < min)
			{
				min = *i;
			}
		}

		std::cout << min << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Начнём с пробела, закончим точкой" << std::endl;

	do
	{
		std::cout << "Введи строку:" << std::endl;
		std::string string;
		std::getline(std::cin, string);
		
		if (std::cin.fail() || string.empty())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		string[0] = ' ';
		string[string.length() - 1] = '.';
		std::cout << "Результат:" << std::endl;
		std::cout << string << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

std::vector<std::pair<std::string, bool>> names =
{
	{ "София", false }
	, { "Анастасия", false }
	, { "Виктория", false }
	, { "Ксения", false }
	, { "Арина", false }
	, { "Елизавета", false }
	, { "Аделина", false }
	, { "Ирина", false }
	, { "Елена", false }
	, { "Полина", false }
	, { "Дарья", false }
	, { "Наталья", false }
	, { "Светлана", false }
	, { "Вера", false }
	, { "Надежда", false }
	, { "Галина", false }
	, { "Любовь", false }
	, { "Александра", false }
	, { "Мария", false }
	, { "Анна", false }
	, { "Ангелина", false }
	, { "Марина", false }
	, { "Екатерина", false }
	, { "Людмила", false }
	, { "Татьяна", false }
	, { "Артём", false }
	, { "Александр", false }
	, { "Роман", false }
	, { "Евгений", false }
	, { "Иван", false }
	, { "Максим", false }
	, { "Денис", false }
	, { "Алексей", false }
	, { "Дмитрий", false }
	, { "Даниил", false }
	, { "Сергей", false }
	, { "Николай", false }
	, { "Константин", false }
	, { "Никита", false }
	, { "Михаил", false }
	, { "Борис", false }
	, { "Виктор", false }
	, { "Геннадий", false }
	, { "Вячеслав", false }
	, { "Владимир", false }
	, { "Андрей", false }
	, { "Анатолий", false }
	, { "Илья", false }
	, { "Кирилл", false }
	, { "Олег", false }
};

const std::vector<std::string> SUBJECT_NAMES =
{
	"Программирование"
	, "Математика"
	, "Физика"
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
	std::cout << "Студентики" << std::endl;

	do
	{
		Statement statement;
		std::vector<Row *> greats = statement.getGreatStudent();
		std::cout << "Лучшие студенты: " << std::endl;
		
		if (greats[0]->goodWeekCounter > 0)
		{
			for (const auto &great : greats)
			{
				std::cout << great->student.name << std::endl;
			}
		}
		else
		{
			std::cout << "Набрали дебилов, блин... -_-" << std::endl;
		}

		std::cout << "Недель на 4 и 5: " << greats[0]->goodWeekCounter << std::endl;
		std::cout << "\nДля выхода жми 0\n" << std::endl;
	}
	while ('0' != _getch());
}
