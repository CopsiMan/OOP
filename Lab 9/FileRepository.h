#pragma once

#include "Tape.h"
#include "RepositoryInterface.h"

#include <fstream>
#include <vector>
#include <algorithm>

typedef Tape* TElement;


class FileRepository : public RepositoryInterface
{
private:
	// DynamicArray<TElement> dynamicArray{};
	//std::vector<TElement> elements{}; 
	std::string filePath;
	std::string fileType;
	int length;

public:
	FileRepository(std::string filePath = "", std::string fileType = "");
	void add(TElement element) override;
	void remove(TElement element) override;
	void update(TElement newTElement) override;
	std::vector<TElement> getAll() override;
	TElement getElement(int position) override;
	TElement find(TElement element) override;
	int size() override;
	void setPath(std::string filePath) override;
	std::string getPath() override;

	std::vector<TElement> loadFromFile();
	void writeToFile(std::vector<TElement> elements);
	~FileRepository();
};

class FileRepository_Exception : public std::exception {
private:
	std::string message;
public:
	FileRepository_Exception(std::string message);
	const char* what() const noexcept override;
};
