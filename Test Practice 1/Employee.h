#pragma once

#include <string>

class Employee
{
protected:
	std::string name;
	double baseSalary;
public:
	Employee(std::string name = "-", double baseSalary = 0);
	virtual std::string toString();
	virtual double computeSalary();
};

