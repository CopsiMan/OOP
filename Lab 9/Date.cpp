#include "Date.h"

Date::Date()
{
	day = month = 1;
	year = 2000;
}

Date::Date(int day, int month, int year)
{
	/*
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
	*/
	this->day = day;
	this->month = month;
	this->year = year;
	// Date_Validator::Validate(*this);
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
	/*bool leapYear = this->isLeapYear(this->year);
	int maxDaysInMonth = this->daysInEachMonth[this->month];
	if (leapYear && this->month == 2)
		maxDaysInMonth++;
	if (day > maxDaysInMonth || day < 1)
		throw "Invalid day!";*/
	this->day = day;
	Date_Validator::Validate(*this);
}

void Date::setMonth(int month)
{
	/*if (month < 1 || month > 12)
		throw "Invalid month!";*/
	this->month = month;
	Date_Validator::Validate(*this);
}

void Date::setYear(int year)
{
	/*if (year < 1900 || year > 2021)
		throw "Invalid year!";*/
	this->year = year;
	Date_Validator::Validate(*this);
}

std::string Date::toString()
{
	return std::to_string(getMonth()) + "-" + std::to_string(getDay()) + "-" + std::to_string(getYear());
}

bool Date::isLeapYear(int year) const
{
	if (year % 4 != 0)
		return false;
	if (year % 4 == 0)
	{
		if (year % 100 == 0) {
			if (year % 400 == 0)
				return true;
			return false;
		}
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

Date_Exception::Date_Exception(std::string message)
{
	this->message = message;
}

const char* Date_Exception::what() const noexcept
{
	return this->message.c_str();
}

//std::string Date_Exception::getMessage() const
//{
//	return this->message;
//}

void Date_Validator::Validate(const Date& date)
{
	std::string errors;

	if (date.getYear() < 1900 || date.getYear() > 2021)
		errors += "Invalid year!";

	if (date.getMonth() < 1 || date.getMonth() > 12)
		errors += "Invalid month!";

	bool leapYear = date.isLeapYear(date.getYear());
	int maxDaysInMonth = date.daysInEachMonth[date.getMonth()];
	if (leapYear && date.getMonth() == 2)
		maxDaysInMonth++;
	if (date.getDay() > maxDaysInMonth || date.getDay() < 1)
		errors += "Invalid day!";

	if (errors.size())
		throw Date_Exception(errors);
}
