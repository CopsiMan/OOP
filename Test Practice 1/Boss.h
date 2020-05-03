#pragma once
#include "Manager.h"
class Boss : public Manager
{
private:
	std::string companyCar;
public:
	Boss(std::string name = "-", double baseSalary = 0, double bonus = 0, std::string companyCar = "-");
	virtual std::string toString() override;
	virtual double computeSalary() override;
};

