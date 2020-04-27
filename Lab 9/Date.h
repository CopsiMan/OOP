#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class Date
{
private:
	int day, month, year;
public:
	int daysInEachMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	Date();
	Date(int day, int month, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	bool isLeapYear(int year) const;
	std::string toString();
	bool operator==(const Date& date);
	friend std::ostream& operator<< (std::ostream& outputStream, const Date& date);
	friend std::istream& operator>> (std::istream& inputStream, Date& date);
};

class Date_Exception : public std::exception {
private:
	std::string message;
public:
	Date_Exception(std::string message);
	const char* what() const noexcept override;
};

class Date_Validator {
public:
	static void Validate(const Date& date);
};