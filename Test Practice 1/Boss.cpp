#include "Boss.h"

Boss::Boss(std::string name, double baseSalary, double bonus, std::string companyCar) : Manager{name, baseSalary, bonus}
{
	this->companyCar = companyCar;
}

std::string Boss::toString()
{
	return std::string("Boss ") + Manager::toString() + " Car: " + this->companyCar;
}

double Boss::computeSalary()
{
	return 1000 + Manager::computeSalary();
}
