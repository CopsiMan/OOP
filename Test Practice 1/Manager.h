#pragma once

#include "Employee.h"

class Manager : public Employee
{
private:
	double bonus;
public:
	Manager(std::string name = "-", double baseSalary = 0, double bonus = 0);
	virtual std::string toString() override;
	virtual double computeSalary() override;
};

