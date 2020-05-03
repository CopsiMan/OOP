#include <iostream>
#include <vector>

#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

void testEmployees() {
	vector<Employee*> employees;
	/*
	*/
	employees.push_back(new Manager{ "Alex Tod.", 100 });
	employees.push_back(new Employee{ "Alex Tod.", 100 });
	employees.push_back(new Manager{ "Vic Tod.", 150, 125 });
	employees.push_back(new Manager{ "Vic Tod.", 150 });
	employees.push_back(new Employee{ "Vic Tod.", 150 });
	employees.push_back(new Manager{ "Vic Tod.", 150 });
	employees.push_back(new Employee{ "Vic Tod.", 150 });
	employees.push_back(new Employee{ "Vic Tod.", 150 });
	employees.push_back(new Employee{ "Copsi F.", 250 });
	employees.push_back(new Manager{ "Copsi F.", 250, 100 });
	employees.push_back(new Employee{ "Copsi F.", 250 });
	employees.push_back(new Employee{ "Copsi F.", 250 });
	employees.push_back(new Manager{ "Copsi F.", 250, 100 });
	employees.push_back(new Boss{ "Copsi F.", 250, 100, "lambo" });
	employees.push_back(new Boss{ "Copsi F.", 250, 0, "heh" });
	employees.push_back(new Boss{ "Copsi F.", 250, 100, "ferarri" });
	employees.push_back(new Boss{ "Copsi F.", 250, 100, "mustang" });
	for (Employee* emp : employees) {
		cout << emp->toString() << ": " << emp->computeSalary() << endl;
	}
}

int main() {
	testEmployees();
	system("pause");
	return 0;
}