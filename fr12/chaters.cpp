#include "chaters.h"

std::string names[]
{
	"���������",
	"������",
	"���������",
	"�����",
	"�������",
	"�����",
	"�����",
	"��������",
	"������",
	"�������"
};

Human::Human()
{
	age = rand() % 21 + 20;
	name = names[rand() % 10];
}

Human::~Human()
{}

std::string Human::getName() const
{
	return name;
}

unsigned Human::getAge() const
{
	return age;
}

Human *Human::create(HumanType ht)
{
	switch (ht)
	{
	case HumanType::formalist:
		return new Formalist();
	case HumanType::noformal:
		return new Noformal();
	case HumanType::realist:
		return new Realist();
	default:
		throw "׸-�� ����� �� ���";
	}
}

void Human::destroy(Human *h)
{
	if (h != nullptr)
	{
		delete h;
	}
}

std::string Human::getYear()
{
	return age % 10 == 1 && age % 100 != 11
		? "���"
		: (age % 10 == 2 || age % 10 == 3 || age % 10 == 4) && (age % 100 != 12 && age % 100 != 13 && age % 100 != 14)
			? "����"
			: "���";
}

std::string Formalist::sayHello(const Human &h) const
{
	return "�����������, " + h.getName();
}

std::string Formalist::sayAboutSelf()
{
	return "���� ����� " + name + ", ��� ������� " + std::to_string(age) + " " + getYear() + " � � ���������";
}

std::string Noformal::sayHello(const Human &h) const
{
	return "������, " + h.getName();
}

std::string Noformal::sayAboutSelf()
{
	return "���� ����� " + name + ", ��� ������� " + std::to_string(age) + " " + getYear() + " � � ��������";
}

std::string Realist::sayHello(const Human &h) const
{
	return (abs((int)age - (int)h.getAge()) > 5 ? "�����������, " : "������, ") + h.getName();
}

std::string Realist::sayAboutSelf()
{
	return "���� ����� " + name + ", ��� ������� " + std::to_string(age) + " " + getYear() + " � � �������";
}
