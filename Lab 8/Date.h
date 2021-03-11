#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class Date
{
private:
	int day, month, year, daysInEachMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	std::string toString();
	bool valid();
	bool isLeapYear(int year);
	bool operator==(const Date& date);
	friend std::ostream& operator<< (std::ostream& outputStream, const Date& date);
	friend std::istream& operator>> (std::istream& inputStream, Date& date);
};

