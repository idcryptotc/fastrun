#pragma once
#include <string>
#include <vector>

enum class HumanType { formalist, noformal, realist };

class Human
{
public:
	Human();
	virtual ~Human();
	virtual std::string sayHello(const Human &) const = 0;
	virtual std::string sayAboutSelf() = 0;
	std::string getName() const;
	unsigned getAge() const;
	static Human* create(HumanType);
	static void destroy(Human *);

protected:
	std::string name;
	unsigned age;
	std::string getYear();
};

class Formalist : public Human
{
	std::string sayHello(const Human &) const override;
	std::string sayAboutSelf() override;
};

class Noformal : public Human
{
	std::string sayHello(const Human &) const override;
	std::string sayAboutSelf() override;
};

class Realist : public Human
{
	std::string sayHello(const Human &) const override;
	std::string sayAboutSelf() override;
};
