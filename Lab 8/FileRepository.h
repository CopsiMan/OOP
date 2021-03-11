#pragma once
#include "Tape.h"
#include <fstream>
#include <vector>
#include <algorithm>

typedef Tape* TElement;


class FileRepository
{
private:
	// DynamicArray<TElement> dynamicArray{};
	//std::vector<TElement> elements{}; 
	std::string filePath;
	int length;

public:
	FileRepository(std::string filePath = "");
	void add(TElement element);
	void setPath(std::string filePath);
	std::vector<TElement> getAll();
	std::vector<TElement> loadFromFile();
	void writeToFile(std::vector<TElement> elements);
	int size();
	void remove(TElement element);
	void update(TElement newTElement);
	TElement getElement(int position);
	TElement find(TElement element);
};

