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

#pragma warning(push)
#pragma warning(disable: 6031)

void part1();
void part2();
void part3();

class Students;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	part1();
	part2();
	part3();
	return 0;
}

HWND hwnd = GetConsoleWindow();
HDC dc = GetDC(hwnd);
HDC hdc = NULL, hDC;
HBITMAP hScreen, oldBmp = NULL;
int screen_x = GetDeviceCaps(dc, HORZRES);
int screen_y = GetDeviceCaps(dc, VERTRES);
POINT fullNumberTemplate[4][8][4] =
{
	{
		{//верхний сегмент
			{0 + 30, 30},
			{100 + 30, 30},
			{70 + 30, 50},
			{30 + 30, 50}
		},
		{//левый верхний сегмент
			{0 + 30, 30},
			{0 + 30, 130},
			{20 + 30, 100},
			{20 + 30, 60}
		},
		{//правый верхний сегмент
			{100 + 30, 30},
			{100 + 30, 130},
			{80 + 30, 100},
			{80 + 30, 60}
		},
		{//верхний средний сегмент
			{0 + 30, 130},
			{100 + 30, 130},
			{70 + 30, 120},
			{30 + 30, 120}
		},
		{//нижний средний сегмент
			{0 + 30, 130},
			{100 + 30, 130},
			{70 + 30, 140},
			{30 + 30, 140}
		},
		{//левый нижний сегмент
			{0 + 30, 130},
			{0 + 30, 230},
			{20 + 30, 200},
			{20 + 30, 160}
		},
		{//правый нижний сегмент
			{100 + 30, 130},
			{100 + 30, 230},
			{80 + 30, 200},
			{80 + 30, 160}
		},
		{//нижний сегмент
			{0 + 30, 230},
			{100 + 30, 230},
			{70 + 30, 210},
			{30 + 30, 210}
		}
	},
	{//вторая цифра
		{//верхний сегмент
			{0 + 150, 30},
			{100 + 150, 30},
			{70 + 150, 50},
			{30 + 150, 50}
		},
		{//левый верхний сегмент
			{0 + 150, 30},
			{0 + 150, 130},
			{20 + 150, 100},
			{20 + 150, 60}
		},
		{//правый верхний сегмент
			{100 + 150, 30},
			{100 + 150, 130},
			{80 + 150, 100},
			{80 + 150, 60}
		},
		{//верхний средний сегмент
			{0 + 150, 130},
			{100 + 150, 130},
			{70 + 150, 120},
			{30 + 150, 120}
		},
		{//нижний средний сегмент
			{0 + 150, 130},
			{100 + 150, 130},
			{70 + 150, 140},
			{30 + 150, 140}
		},
		{//левый нижний сегмент
			{0 + 150, 130},
			{0 + 150, 230},
			{20 + 150, 200},
			{20 + 150, 160}
		},
		{//правый нижний сегмент
			{100 + 150, 130},
			{100 + 150, 230},
			{80 + 150, 200},
			{80 + 150, 160}
		},
		{//нижний сегмент
			{0 + 150, 230},
			{100 + 150, 230},
			{70 + 150, 210},
			{30 + 150, 210}
		}
	},
	{//третья цифра
		{//верхний сегмент
			{0 + 300, 30},
			{100 + 300, 30},
			{70 + 300, 50},
			{30 + 300, 50}
		},
		{//левый верхний сегмент
			{0 + 300, 30},
			{0 + 300, 130},
			{20 + 300, 100},
			{20 + 300, 60}
		},
		{//правый верхний сегмент
			{100 + 300, 30},
			{100 + 300, 130},
			{80 + 300, 100},
			{80 + 300, 60}
		},
		{//верхний средний сегмент
			{0 + 300, 130},
			{100 + 300, 130},
			{70 + 300, 120},
			{30 + 300, 120}
		},
		{//нижний средний сегмент
			{0 + 300, 130},
			{100 + 300, 130},
			{70 + 300, 140},
			{30 + 300, 140}
		},
		{//левый нижний сегмент
			{0 + 300, 130},
			{0 + 300, 230},
			{20 + 300, 200},
			{20 + 300, 160}
		},
		{//правый нижний сегмент
			{100 + 300, 130},
			{100 + 300, 230},
			{80 + 300, 200},
			{80 + 300, 160}
		},
		{//нижний сегмент
			{0 + 300, 230},
			{100 + 300, 230},
			{70 + 300, 210},
			{30 + 300, 210}
		}
	},
	{//четвёртая цифра
		{//верхний сегмент
			{0 + 420, 30},
			{100 + 420, 30},
			{70 + 420, 50},
			{30 + 420, 50}
		},
		{//левый верхний сегмент
			{0 + 420, 30},
			{0 + 420, 130},
			{20 + 420, 100},
			{20 + 420, 60}
		},
		{//правый верхний сегмент
			{100 + 420, 30},
			{100 + 420, 130},
			{80 + 420, 100},
			{80 + 420, 60}
		},
		{//верхний средний сегмент
			{0 + 420, 130},
			{100 + 420, 130},
			{70 + 420, 120},
			{30 + 420, 120}
		},
		{//нижний средний сегмент
			{0 + 420, 130},
			{100 + 420, 130},
			{70 + 420, 140},
			{30 + 420, 140}
		},
		{//левый нижний сегмент
			{0 + 420, 130},
			{0 + 420, 230},
			{20 + 420, 200},
			{20 + 420, 160}
		},
		{//правый нижний сегмент
			{100 + 420, 130},
			{100 + 420, 230},
			{80 + 420, 200},
			{80 + 420, 160}
		},
		{//нижний сегмент
			{0 + 420, 230},
			{100 + 420, 230},
			{70 + 420, 210},
			{30 + 420, 210}
		}
	}
};
bool arraySegments[10][8] =
{
	{//0
		true,true,true,false,false,true,true,true
	},
	{//1
		false,false,true,false,false,false,true,false
	},
	{//2
		true,false,true,true,true,true,false,true
	},
	{//3
		true,false,true,true,true,false,true,true
	},
	{//4
		false,true,true,true,true,false,true,false
	},
	{//5
		true,true,false,true,true,false,true,true
	},
	{//6
		true,true,false,true,true,true,true,true
	},
	{//7
		true,false,true,false,false,false,true,false
	},
	{//8
		true,true,true,true,true,true,true,true
	},
	{//9
		true,true,true,true,true,false,true,true
	}
};
void CALLBACK oClockDraw(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime);
HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));

void part1()
{
	std::cout << "Часы" << std::endl;
	std::cout << "Жми чё-нить для старта" << std::endl;
	_getch();
	system("cls");
	std::cout << "Для выхода жми чё-нить" << std::endl;
	MSG msg;
	SetTimer(NULL, 1, 500, (TIMERPROC)&oClockDraw);
	CONSOLE_CURSOR_INFO CCI;
	CCI.bVisible = false;
	CCI.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (_kbhit())
		{
			break;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	_getch();
	CCI.bVisible = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CCI);
	KillTimer(hwnd, 1);
	DeleteDC(dc);
	DeleteObject(brush);
	system("cls");
}

void CALLBACK oClockDraw(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	static bool isPoints = true;
	hDC = CreateCompatibleDC(dc);
	hScreen = CreateCompatibleBitmap(dc, screen_x, screen_y);
	oldBmp = (HBITMAP)SelectObject(hDC, hScreen);
	PatBlt(hDC, 100, 100, 400, 400, BLACKNESS);
	SelectObject(hDC, brush);
	std::time_t t = std::time(0);   // get time now
	std::tm now;
	localtime_s(&now, &t);
	std::string time =
		(now.tm_hour < 10 ? "0" + std::to_string(now.tm_hour) : std::to_string(now.tm_hour)) +
		(now.tm_min < 10 ? "0" + std::to_string(now.tm_min) : std::to_string(now.tm_min));

	for (std::size_t i = 0; i < time.length(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (!arraySegments[time[i] - '0'][j])
			{
				continue;
			}

			Polygon(hDC, fullNumberTemplate[i][j], 4);
		}
	}

	if (isPoints)
	{
		Ellipse(hDC, 270, 100, 280, 110);
		Ellipse(hDC, 270, 160, 280, 170);
		isPoints = false;
	}
	else
	{
		isPoints = true;
	}

	BitBlt(dc, 30, 30, screen_x, screen_y, hDC, 30, 30, SRCCOPY);
	SelectObject(hDC, oldBmp);
	DeleteDC(hDC);
}


void part2()
{
	std::cout << "Строка/число" << std::endl;

	do
	{
		std::cout << "Введи строку:" << std::endl;
		std::string str;
		std::getline(std::cin, str);

		for (std::size_t i = 0; i < str.length(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				std::cout << str << " не является целым числом" << std::endl;
				break;
			}

			if (i == str.length() - 1)
			{
				std::cout << str << " является целым числом" << std::endl;
			}
		}

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

struct Ticket
{
	std::string destination;
	unsigned flightNumber;
	std::string FIO;
	std::string date;
};

struct Student
{
	std::string FIO;
	unsigned one = 0;
	unsigned two = 0;
	unsigned three = 0;
};

class Students
{
public:
	Students()
	{
		std::ifstream file("input_data.txt");

		if (!file.is_open())
		{
			std::cout << "Жопа... файл не открылся..." << std::endl;
		}

		std::string line;
		std::getline(file, line);

		int n = stoi(line);
		arr.resize(n);

		for (int k = 0; k < n; ++k)
		{
			std::getline(file, line);
			int count = 0;

			for (std::size_t i = 0; i < line.length(); ++i)
			{
				if (line[i] == ' ' && count < 3)
				{
					++count;

					if (count == 3)
					{
						arr[k].FIO = line.substr(0, i);
					}
				}

				if (line[i] == ' ' && count >= 3)
				{
					switch (count)
					{
					case 3:
						{
							arr[k].one = line[i + 1] - '0';
							++count;
							break;
						}
					case 4:
						{
							arr[k].two = line[i + 1] - '0';
							++count;
							break;
						}
					case 5:
						{
							arr[k].three = line[i + 1] - '0';
							break;
						}
					}
				}
			}
		}

		file.close();
		std::sort(arr.begin(), arr.end(), [](const auto &i1, const auto &i2)
			{
				return
					((double)i1.one + (double)i1.two + (double)i1.three) / 3.
				>
					double((double)i2.one + (double)i2.two + (double)i2.three) / 3.;
			});
	}

	void showAll()
	{
		for (std::size_t i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i].FIO << " " << arr[i].one << " " << arr[i].two << " " << arr[i].three << std::endl;
		}
	}
private:
	std::vector<Student> arr;
};

void part3()
{
	std::cout << "Студенты" << std::endl;
	Students st;

	do
	{
		st.showAll();

		std::cout << "Для выхода жми 0" << std::endl;
	}
	while ('0' != _getch());
}

