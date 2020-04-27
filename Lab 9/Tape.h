#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "Date.h"

class Tape
{
private:
	std::string title, filmedAt,footagePreview;
	Date creationDate;
	int accessCount;

public:
	//Tape();
	Tape(std::string title = "-", std::string filmedAt = "-", Date creationDate = Date{ 1,1,2000 }, int accessCount = 0, std::string footagePreview = "-");
	Tape(const Tape& tape);
	std::string getTitle() const;
	std::string getFilmedAt() const;
	Date getCreationDate() const;
	std::string getFootagePreview() const;
	int getAccessCount() const;
	std::string setTitle(std::string title);
	std::string setFilmedAt(std::string filmedAt);
	Date setCreationDate(Date creationDate);
	std::string setFootagePreview(std::string footagePreview);
	int setAccessCount(int accessCount);
	Tape& operator=(const Tape& tape);
	friend bool operator==(const Tape& tape1, const Tape& tape2);
	std::string htmlHeader();
	std::string toHtml();
	std::string htmlEnd();
	//~Tape();
	friend std::istream& operator>> (std::istream& inputStream, Tape& tape);
	friend std::ostream& operator<< (std::ostream& outputStream, const Tape& tape);
};

bool operator==(const Tape& tape1, const Tape& tape2);

class Tape_Exception : public std::exception {
private:
	std::string message;
public:
	Tape_Exception(std::string message);
	const char* what() const noexcept override;
};

class Tape_Validator {
public:
	static void Validate(const Tape& tape);
};