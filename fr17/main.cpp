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
	part1();
	part2();
	part3();
	return 0;
}

void part1()
{
	std::cout << "Случайно: Среднее" << std::endl;

	do
	{
		const int COUNT = 10;
		std::cout << "Массив целых чисел:" << std::endl;
		std::vector<int> sequence;

		for (ptrdiff_t i = 0; i < COUNT; ++i)
		{
			int num = rand() % 10 + 1;
			sequence.push_back(num);
			std::cout << num << ' ';
		}

		std::cout << std::endl;
		double avg = std::accumulate(sequence.begin(), sequence.end(), 0)
			/ (double)sequence.size();
		std::cout << "Среднее арифметическое: " << avg << std::endl;
		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

void part2()
{
	std::cout << "Случайно: min и max" << std::endl;

	do
	{
		const int COUNT = 9;
		std::cout << "Массив целых чисел:" << std::endl;
		std::vector<int> sequence;

		for (ptrdiff_t i = 0; i < COUNT; ++i)
		{
			int num = rand() % 10;
			sequence.push_back(num);
			std::cout << num << ' ';
		}

		std::cout << std::endl;
		auto minmax =
			std::minmax_element(sequence.begin(), sequence.end());
		std::swap(*minmax.first, *minmax.second);
		
		for (const auto &item : sequence)
		{
			std::cout << item << ' ';
		}
		
		std::cout << "\nДля выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

std::map<int, std::string> textQuestions =
{
	{ 1, "Что такое курица?"}
	, { 2, "Что такое таракан?"}
	, { 3, "Что такое лягушка?"}
	, { 4, "Что такое баклажан?"}
	, { 5, "Что такое сельдь?"}
};

std::multimap<std::string, std::string> textAnswers =
{
	{ "Что такое курица?", "Птица" }
	, { "Что такое курица?", "Насекомое" }
	, { "Что такое курица?", "Рыба" }
	, { "Что такое курица?", "Земноводное" }
	, { "Что такое курица?", "Растение" }

	, { "Что такое таракан?", "Насекомое" }
	, { "Что такое таракан?", "Рыба" }
	, { "Что такое таракан?", "Птица" }
	, { "Что такое таракан?", "Земноводное" }
	, { "Что такое таракан?", "Растение" }

	, { "Что такое лягушка?", "Земноводное" }
	, { "Что такое лягушка?", "Рыба" }
	, { "Что такое лягушка?", "Насекомое" }
	, { "Что такое лягушка?", "Птица" }
	, { "Что такое лягушка?", "Растение" }

	, { "Что такое баклажан?", "Растение" }
	, { "Что такое баклажан?", "Рыба" }
	, { "Что такое баклажан?", "Насекомое" }
	, { "Что такое баклажан?", "Птица" }
	, { "Что такое баклажан?", "Земноводное" }

	, { "Что такое сельдь?", "Рыба" }
	, { "Что такое сельдь?", "Насекомое" }
	, { "Что такое сельдь?", "Птица" }
	, { "Что такое сельдь?", "Земноводное" }
	, { "Что такое сельдь?", "Растение" }
};

struct Answer
{
	std::string text;
	bool isCorrect;

	Answer() : isCorrect(false)
	{

	}
};

struct Question
{
	std::string text;
	std::vector<Answer> answers;

	Question() : answers(5)
	{

	}
};

void part3()
{
	int COUNT = 5;
	std::vector<Question> questions(COUNT);

	for (ptrdiff_t i = 0; i < COUNT; ++i)
	{
		questions[i].text = textQuestions[i + 1];
		questions[i].answers[0].isCorrect = true;

		for (int j = 0; j < COUNT; ++j)
		{
			std::multimap<std::string, std::string>::iterator it =
				textAnswers.equal_range(textQuestions[i + 1]).first;
			std::advance(it, j);
			questions[i].answers[j].text = it->second;
		}
	}

	do
	{
		std::cout << "Тест по биологии" << std::endl;
		std::cout << "Жми чё-нить для начала" << std::endl;
		_getch();
		int indexQuestion = 1;
		std::random_device rd;
		std::default_random_engine rng { rd() };
		std::shuffle(questions.begin(), questions.end(), rng);
		int state = 0;

		for (auto &question : questions)
		{
			system("cls");
			std::cout << indexQuestion++ << ". " << question.text << std::endl;
			std::shuffle(question.answers.begin(), question.answers.end(), rng);
			int indexAnswer = 1;

			for (const auto &answer : question.answers)
			{
				std::cout << "\t" << indexAnswer++ << ". " << answer.text << std::endl;
			}

			int answer;

			do
			{
				std::cout << "Что решил? Введи цифру: ";
				std::cin >> answer;

				if (std::cin.fail() || answer > 5 || answer < 1)
				{
					std::cin.clear();
					std::cin.ignore(INT32_MAX, '\n');
					std::cout << "Почти... Давай снова" << std::endl;
					continue;
				}

				break;
			}
			while (true);

			state += question.answers[answer - 1].isCorrect ? 1 : 0;
		}

		std::cout << "Ты набрал " << state << " баллов" << std::endl;
		std::cout << "Вывод: ";

		switch (state)
		{
		case 0:
			std::cout << "#&!$%, ты полено...";
			break;
		case 1:
			std::cout << "Чутка смог, да...";
			break;
		case 2:
			std::cout << "Недостаточно умён...";
			break;
		case 3:
			std::cout << "Не тупой. Уже хорошо";
			break;
		case 4:
			std::cout << "Почти красавчик!";
			break;
		case 5:
			std::cout << "Да ты мегамозг!";
		}

		std::cout << "\nДля выхода жми 0\n" << std::endl;
	}
	while ('0' != _getch());
}
