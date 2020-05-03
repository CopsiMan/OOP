#include "Manager.h"

Manager::Manager(std::string name, double baseSalary, double bonus) : Employee{ name, baseSalary }
{
	this->bonus = bonus;
}

std::string Manager::toString()
{
	return std::string("Manager: ") + Employee::toString();
}

double Manager::computeSalary()
{
	return bonus + Employee::computeSalary();
}
