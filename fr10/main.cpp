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
	std::cout << "Среднее арифметическое" << std::endl;

	do
	{
		std::cout << "Введи длину последовательности: ";
		int n;
		std::cin >> n;

		if (std::cin.fail() || n <= 0 || n > 100)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			continue;
		}

		std::cout << "Введи последовательность дробных:" << std::endl;
		std::vector<double> v(n);

		for (auto &x : v)
		{
			std::cin >> x;
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			continue;
		}

		auto avg = std::accumulate(v.begin(), v.end(), 0.) / v.size();
		std::cout << "Среднее арифметическое: " << std::fixed 
			<< std::setprecision(1) << avg << std::setprecision(6) << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Счастливые билеты" << std::endl;

	do
	{
		std::cout << "Введи номер билета: ";
		std::string ticketNumber;
		std::cin >> ticketNumber;
		int n;

		try
		{
			if (std::cin.fail() || ticketNumber.length() != 6 || ((n = stoi(ticketNumber)) < 1))
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				std::cout << "Почти..." << std::endl;
				std::cout << "Для выхода жми 0" << std::endl;
				continue;
			}
		}
		catch (std::invalid_argument ex)
		{
			std::cout << "Почти... " << ex.what() << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		int n1 = n / 1000;
		int n2 = n % 1000;
		int sum1 = 0; 
		int sum2 = 0;

		for (int i = 0; i < 3; ++i)
		{
			sum1 += n1 % 10;
			n1 /= 10;
			sum2 += n2 % 10;
			n2 /= 10;
		}

		std::cout << "Билет " << ticketNumber << " " << (sum1 == sum2 ? "счастливый" : "не счастливый") << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

const int FIVE = 5;

struct Student
{
	std::string Name;
	int Year;
	int Rating[FIVE];

	bool operator()(const Student &x, const Student &y) const
	{
		return x.Name < y.Name;
	}

	friend std::ostream &operator << (std::ostream &os, const Student &s)
	{
		return os << "ФИО: " << s.Name << "\n" 
			<< "Курс: " << s.Year << "\n" 
			<< "Рейтинг: " << std::accumulate(s.Rating, &s.Rating[FIVE], 0.) / FIVE << "\n";
	}
};

void addStudent(std::set<Student, Student> &);
double avgAll(std::set<Student, Student> &);

void part3()
{
	std::cout << "Студенты" << std::endl;
	std::set<Student, Student> students;

	do
	{
		std::cout << "Сколько студентов добавим?" << std::endl;
		int n;
		std::cin >> n;

		if (std::cin.fail() || n < 1 || n > 10)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		for (int i = 0; i < n; ++i)
		{
			addStudent(students);
		}

		double avg = avgAll(students);
		bool isHave = false;

		for (const auto &s : students)
		{
			if (avg < std::accumulate(s.Rating, &s.Rating[FIVE], 0.) / FIVE)
			{
				isHave = true;
				std::cout << s;
			}
		}

		if (!isHave)
		{
			std::cout << "Выше среднего никто не набрал" << std::endl;
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void addStudent(std::set<Student, Student> &students)
{
	Student s;
	std::cout << "Введите ФИО студента: ";
	std::cin.clear();
	std::cin.ignore(INT32_MAX, '\n');
	std::getline(std::cin, s.Name);
	srand(static_cast<unsigned>(time(NULL)));
	
	do
	{
		std::cout << "Введите год: ";
		std::cin >> s.Year;

		if (std::cin.fail() || s.Year < 1 || s.Year > 5)
		{
			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Почти..." << std::endl;
			std::cout << "Для выхода жми 0" << std::endl;
			continue;
		}

		break;
	}
	while (true);

	do
	{
		std::cout << "Введите оценки (массив из 5 элементов, 1..5):" << std::endl;

		for (int i = 0; i < FIVE; ++i)
		{
			std::cin >> s.Rating[i];

			if (std::cin.fail() || s.Rating[i] < 1 || s.Rating[i] > 5)
			{
				std::cin.clear();
				std::cin.ignore(INT32_MAX, '\n');
				s.Rating[i] = rand() % 4 + 1;
			}
		}


		break;
	}
	while (true);

	students.insert(s);
}

double avgAll(std::set<Student, Student> &students)
{
	double sum = 0.;

	for (const auto &s : students)
	{
		sum += std::accumulate(s.Rating, &s.Rating[FIVE], 0.) / FIVE;
	}

	return sum / students.size();
}

