#include "FileRepository.h"

FileRepository::FileRepository(std::string filePath, std::string fileType)
{
	this->filePath = filePath;
	this->fileType = fileType;
	this->length = 0;
}

void FileRepository::add(TElement element)
{
	std::vector<TElement> elements = this->loadFromFile();
	if (std::find_if(elements.begin(), elements.end(), [element](TElement otherElement) {return *element == *otherElement; }) != elements.end()) {
		for (auto const& element : elements) {
			delete element;
		}
		delete element;
		throw FileRepository_Exception("Element already exists!");
	}
	elements.push_back(element);
	this->length++;
	this->writeToFile(elements);


	// -1 means the element was not found
	/*if (this->dynamicArray.getIndex(element) == -1)
		this->dynamicArray.add(element);
	else {
		delete element;
		throw "Element already exists!";
	}*/

}

void FileRepository::setPath(std::string filePath)
{
	this->filePath = filePath;
	this->fileType = filePath.substr(filePath.find_last_of(".", filePath.size()));
	// std::cout << this->fileType << "\n";
}

std::string FileRepository::getPath()
{
	return this->filePath;
}

std::vector<TElement> FileRepository::getAll()
{
	return this->loadFromFile();
}


std::vector<TElement> FileRepository::loadFromFile()
{
	std::vector<TElement> elements;
	std::ifstream file(this->filePath);

	if (this->fileType == ".html") {
		std::string line;
		std::getline(file, line); // skip the first line
		std::getline(file, line);
		while (line == "<tr>") { // while we have a new table row
			std::getline(file, line);
			std::string objectParameters;
			while (line != "</tr>") { // while we didn't reach the end of the row
				std::string field = line.substr(4, line.size() - 9);  // we read a new field
				objectParameters += (field + ",");
				//std::cout << field << ' ';
				std::getline(file, line);
			}
			//std::cout << '\n';
			objectParameters = objectParameters.substr(0, objectParameters.size() - 1); // removing "," from the end
			objectParameters += "\n";
			//std::cout << objectParameters;
			std::stringstream objectStream(objectParameters);
			Tape tapeToRead{};
			objectStream >> tapeToRead;
			Tape* tapeToAdd = new Tape{ tapeToRead };
			elements.push_back(tapeToAdd);
			std::getline(file, line); // we read the next line
			//std::cout << tapeToRead << std::endl;
		}
	}
	else {
		Tape tapeToRead{};
		while (file >> tapeToRead) {
			Tape* tapeToAdd = new Tape{ tapeToRead };
			elements.push_back(tapeToAdd);
		}
	}

	file.close();
	return elements;
}

void FileRepository::writeToFile(std::vector<TElement> elements)
{
	/*std::ofstream file(this->filePath);
	for (auto const& element : elements) {
		file << *element << "\n";
		delete element;
	}
	file.close();*/
	std::ofstream file(this->filePath);
	if (this->fileType == ".html" && elements.size() > 0)
		file << elements[0]->htmlHeader() << '\n';
	for (int i = 0; i < elements.size(); i++) {
		if (this->fileType == ".html") {
			TElement element = elements[i];
			file << element->toHtml() << '\n';
		}
		else if (this->fileType == ".csv")
		{
			file << *elements[i] << '\n';
		}
		else if (this->fileType == ".txt")
		{
			file << *elements[i] << '\n';
		}
		delete elements[i];
	}
	if (this->fileType == ".html" && elements.size() > 0)
		file << elements[0]->htmlEnd();
	file.close();
}

FileRepository::~FileRepository()
{

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
		throw FileRepository_Exception("Element not found!"); }
}

void FileRepository::update(TElement newTElement)
{
	std::vector<TElement> elements = this->loadFromFile();

	for (auto& element : elements) {
		if (*element == *newTElement) {
			delete element;
			element = newTElement;
			this->writeToFile(elements);
			break; }
		else {
			for (auto const& element : elements) {
				delete element;
			}
			delete newTElement;
			throw FileRepository_Exception("Element not found!"); } }
}

TElement FileRepository::getElement(int position)
{
	//return this->dynamicArray.getElement(position);
	std::vector<TElement> elements = this->loadFromFile();
	TElement elementToReturn = elements.at(position);
	for (TElement element : elements) {
		if (!(*element == *elementToReturn))
			delete element;
	}
	return elementToReturn;
}


TElement FileRepository::find(TElement element)
{
	//return this->dynamicArray.getElement(this->dynamicArray.getIndex(element));
	std::vector<TElement> elements = this->loadFromFile();
	bool foundTheElement = false;
	for (auto const& elementToCompare : elements) {
		if (*element == *elementToCompare) {
			*element = *elementToCompare;
			foundTheElement = true;
		}
		delete elementToCompare;
	}
	if (!foundTheElement)
		throw FileRepository_Exception("Element not found!");
	return element;
}

FileRepository_Exception::FileRepository_Exception(std::string message)
{
	this->message = message;
}

const char* FileRepository_Exception::what() const noexcept
{
	return this->message.c_str();
}
