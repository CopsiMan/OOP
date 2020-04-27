#include "MemoryRepository.h"

MemoryRepository::MemoryRepository(std::string filePath, std::string fileType)
{
	this->fileType = fileType;
	this->setPath(filePath);
}

void MemoryRepository::add(TElement element)
{
	// -1 means the element was not found
	if (this->dynamicArray.getIndex(element) == -1)
		this->dynamicArray.add(element);
	else {
		delete element;
		throw "Element already exists!";
	}
	if (this->filePath != "")
		this->writeToFile();
}

void MemoryRepository::remove(TElement element)
{
	int position = this->dynamicArray.getIndex(element);
	// -1 means the element was not found
	if (position == -1) {
		delete element;
		throw "Element doesn't exist"; }
	else
		//delete &element;
		this->dynamicArray.remove(position);
}

void MemoryRepository::update(TElement newTElement)
{
	int position = this->dynamicArray.getIndex(newTElement);
	// -1 means the element was not found
	if (position == -1) {
		delete newTElement;
		throw "Element doesn't exist"; }
	else {
		Tape* oldTape = this->dynamicArray.getElement(position);
		//delete &oldTape;
		// oldTape = &Tape{}
		*oldTape = *newTElement;
		delete newTElement;
	}
}

std::vector<TElement> MemoryRepository::getAll()
{
	std::vector<TElement> result{};
	for (int i = 0; i < this->dynamicArray.getSize(); i++)
		result.push_back(this->dynamicArray.getElement(i));
	return result;
}

TElement MemoryRepository::getElement(int position)
{
	return this->dynamicArray.getElement(position);
}

int MemoryRepository::size()
{
	return this->dynamicArray.getSize();
}

TElement MemoryRepository::find(TElement element)
{
	return this->dynamicArray.getElement(this->dynamicArray.getIndex(element));
}

void MemoryRepository::setPath(std::string filePath)
{
	this->filePath = filePath;
	if (filePath != "")
		this->fileType = filePath.substr(filePath.find_last_of(".", filePath.size()));
}

std::string MemoryRepository::getPath()
{
	return this->filePath;
}

void MemoryRepository::writeToFile()
{
	std::ofstream file(this->filePath);
	if (this->fileType == ".html" && this->dynamicArray.getSize() > 0)
		file << this->dynamicArray.getElement(0)->htmlHeader() << '\n';
	for (int i = 0; i < this->dynamicArray.getSize(); i++) {
		if (this->fileType == ".html") {
			TElement element= this->dynamicArray.getElement(i);
			file << element->toHtml();
		}
		else if (this->fileType == ".csv")
		{
			file << *this->dynamicArray.getElement(i) << '\n';
		}
	}
	if (this->fileType == ".html" && this->dynamicArray.getSize() > 0)
		file << this->dynamicArray.getElement(0)->htmlEnd() << '\n';
	file.close();
}
