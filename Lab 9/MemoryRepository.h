#pragma once

#include "Tape.h"
#include "DynamicArray.h"
#include "RepositoryInterface.h"
#include <fstream>

typedef Tape* TElement;

class MemoryRepository : public RepositoryInterface
{
private:
	DynamicArray<TElement> dynamicArray{};
	std::string filePath;
	std::string fileType;

public:
	MemoryRepository(std::string filePath = "", std::string fileType = "");
	void add(TElement element) override;
	void remove(TElement element) override;
	void update(TElement newTElement) override;
	std::vector<TElement> getAll() override;
	TElement getElement(int position) override;
	int size() override;
	TElement find(TElement element) override;
	void setPath(std::string filePath) override;
	std::string getPath() override;
	void writeToFile();
};

