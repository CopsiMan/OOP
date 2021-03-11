#include "FileRepository.h"

FileRepository::FileRepository(std::string filePath)
{
	this->filePath = filePath;
	this->length = 0;
}

void FileRepository::add(TElement element)
{
	// -1 means the element was not found
	/*if (this->dynamicArray.getIndex(element) == -1)
		this->dynamicArray.add(element);
	else {
		delete element;
		throw "Element already exists!";
	}*/

	std::vector<TElement> elements = this->loadFromFile();
	if (std::find_if(elements.begin(), elements.end(), [element](TElement otherElement) {return *element == *otherElement; }) != elements.end()) {
		for (auto const& element : elements) {
			delete element;
		}
		delete element;
		throw "Element already exists!";
	}
	elements.push_back(element);
	this->length++;
	this->writeToFile(elements);
}

void FileRepository::setPath(std::string filePath)
{
	this->filePath = filePath;
}

std::vector<TElement> FileRepository::getAll()
{
	return this->loadFromFile();
}


std::vector<TElement> FileRepository::loadFromFile()
{
	std::vector<TElement> elements;
	std::ifstream file(this->filePath);
	Tape tape{};
	while (file >> tape) {
		Tape* tapeToAdd = new Tape{tape};
		elements.push_back(tapeToAdd);
	}
	file.close();
	return elements;
}

void FileRepository::writeToFile(std::vector<TElement> elements)
{
	std::ofstream file(this->filePath);
	for (auto const& element : elements) {
		file << *element << "\n";
		delete element;
	}
	file.close();
}

int FileRepository::size()
{
	return this->length;
}

void FileRepository::remove(TElement element)
{
	std::vector<TElement> elements = this->loadFromFile();
	auto position = std::find_if(elements.begin(), elements.end(), [element](TElement otherElement) {return *element == *otherElement; });
	if (position != elements.end()) {
 		delete elements.at(position - elements.begin());
		elements.erase(position);
		this->length--;
		this->writeToFile(elements);
		delete element;
	}
	else {
		for (auto const& element : elements) {
			delete element;
		}
		delete element;
		throw "Element not found!";
	}
}

void FileRepository::update(TElement newTElement)
{
	std::vector<TElement> elements = this->loadFromFile();

	for (auto& element : elements) {
		if (*element == *newTElement) {
			delete element;
			element = newTElement;
			this->writeToFile(elements);
			break;
		}
		else {
			for (auto const& element : elements) {
				delete element;
			}
			delete newTElement;
			throw "Element not found!";
		}
	}
}

TElement FileRepository::getElement(int position)
{
	//return this->dynamicArray.getElement(position);
	std::vector<TElement> elements = this->loadFromFile();
	TElement elementToReturn = elements.at(position);
	for (auto const& element : elements) {
		if (!(*element == *elementToReturn))
			delete element;
	}
	return elementToReturn;
}


TElement FileRepository::find(TElement element)
{
	//return this->dynamicArray.getElement(this->dynamicArray.getIndex(element));
	std::vector<TElement> elements = this->loadFromFile();
	bool found = false;
	for (auto const& elementToCompare : elements) {
		if (*element == *elementToCompare) {
			*element = *elementToCompare;
			found = true;
		}
		delete elementToCompare;
	}
	if (!found)
		throw "Element not found!";
	return element;
}
