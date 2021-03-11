#include "Date.h"

Date::Date()
{
	day = month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year)
{
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::setDay(int day)
{
	if (day < 1)
		throw "Invalid day!";
	bool leapYear = this->isLeapYear(this->year);
	int maxDaysInMonth = this->daysInEachMonth[this->month];
	if (leapYear && this->month == 2)
		maxDaysInMonth++;
	if (day > maxDaysInMonth)
		throw "Invalid day!";
	this->day = day;
}

void Date::setMonth(int month)
{
	if (month < 1 || month > 12)
		throw "Invalid month!";
	this->month = month;
}

void Date::setYear(int year)
{
	if (year < 1900 || year > 2021)
		throw "Invalid year!";
	this->year = year;
}

std::string Date::toString()
{
	return std::to_string(getMonth()) + " - " + std::to_string(getDay()) + " - " + std::to_string(getYear());
}

bool Date::valid()
{
	return true;
}

bool Date::isLeapYear(int year)
{
	if (year % 4 != 0)
		return false;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
			if (year % 400 == 0)
				return true;
			return false;
		return true;
	}
}

bool Date::operator==(const Date& date)
{
	return this->day == date.day && this->month == date.month && this->year == date.year;
}

std::ostream& operator<<(std::ostream& outputStream, const Date& date)
{
	//std::setfill('0');
	//std::setw(2);
	outputStream << std::setfill('0') << std::setw(2) << date.getMonth() << '-' << std::setfill('0') << std::setw(2) << date.getDay() << '-' << date.getYear();
	return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Date& date)
{
	// TODO: insert return statement here
	std::string argument;
	inputStream >> argument;
	std::string formatedArguments;
	std::stringstream stringStream(argument);
	while (std::getline(stringStream, argument, '-'))
	{
		formatedArguments += (" " + argument);
	}
	std::stringstream dateStream(formatedArguments);
	dateStream >> date.month >> date.day >> date.year;
	return inputStream;
}
