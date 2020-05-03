#include "Employee.h"

Employee::Employee(std::string name, double baseSalary) : name{ name }, baseSalary{ baseSalary } {}

std::string Employee::toString()
{
	return name;
}

double Employee::computeSalary()
{
	return baseSalary;
}
