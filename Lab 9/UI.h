#pragma once

#include "Service.h"
#include "Tape.h"
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define USER_MODE 1
#define LIST_FILMED_AT 0
#define LIST_ACCES_COUNT 1
#define DAY 1
#define MONTH 0
#define YEAR 2

using namespace std;

class UI
{
private:
	bool adminMode = false;
public:
	void Start(); 
	std::string* parseInput(std::string userCommand);
	vector<string> splitString(string stringToSplit, char delimiter);
};

