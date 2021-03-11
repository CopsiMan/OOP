#include "Service.h"

//#include <iostream>
//using namespace std;

//std::string* Service::parseInput(std::string userCommand)
//{
//	std::string* arguments = new std::string[MAX_ARGUMENTS];
//	std::string delimiter = ", ";
//	int argument_index = 0;
//	int positionInString = 0;
//	//cout << userCommand << endl;
//
//	// removing the first part of the user input so only the arguments remain
//	userCommand = userCommand.substr(userCommand.find(" ", 0) + 1, userCommand.size());
//
//	// this is basically a strtok for std::string 
//	while ((positionInString = userCommand.find(delimiter)) != std::string::npos) {
//		arguments[argument_index++] = userCommand.substr(0, positionInString);
//		userCommand.erase(0, positionInString + delimiter.length());
//		// cout << arguments[argument_index - 1] << endl;
//	}
//	arguments[argument_index++] = userCommand;
//	return arguments;
//
//	/*for (int i = 0; i < argument_index; i++)
//		cout << arguments[i] << endl;*/
//}

Service::Service()
{
	this->positionInRepository = 0;
}

void Service::add(std::string title, std::string filmedAt, Date creationDate,int accessCount, std::string footagePreview)
{
	/*std::string title = arguments[TITLE];
	std::string filmedAt = arguments[FILMED_AT];
	std::string creationDate = arguments[CREATION_DATE];
	int accessCount = std::stoi(arguments[ACCES_COUNT]);
	std::string footagePreview = arguments[FOOTAGE_PREVIEW];*/
	Tape* tape = new Tape{ title,filmedAt,creationDate,accessCount,footagePreview };
	repository.add(tape);
}

void Service::remove(std::string title)
{
	//std::string title = arguments[TITLE];
	Tape* tape = new Tape{title};
	repository.remove(tape);
	//delete tape;
}

void Service::update(std::string title, std::string filmedAt, Date creationDate, int accessCount, std::string footagePreview)
{
	/*std::string title = arguments[TITLE];
	std::string filmedAt = arguments[FILMED_AT];
	std::string creationDate = arguments[CREATION_DATE];
	int accessCount = std::stoi(arguments[ACCES_COUNT]);
	std::string footagePreview = arguments[FOOTAGE_PREVIEW];*/

	Tape* tape = new Tape{ title,filmedAt,creationDate,accessCount,footagePreview };
	repository.update(tape);
}

std::vector<TElement> Service::getAll()
{
	return this->repository.getAll();
}

int Service::size()
{
	return this->repository.size();
}

void Service::setPath(std::string filePath)
{
	this->repository.setPath(filePath);
}

TElement Service::nextElement()
{
	if (this->positionInRepository == this->repository.size())
		this->positionInRepository = 0;
	return this->repository.getElement(this->positionInRepository++) ;
}

void Service::saveToFieldAgentRepository(std::string title)
{
	Tape tapeToFind{ title };
	Tape* tapeToAdd = new Tape{ *this->repository.find(&tapeToFind) };
	// *tapeToAdd = *this->repository.find(&tapeToFind);
	this->fieldAgentRepository.add(tapeToAdd);
}

TElement* Service::getAllFromFieldAgentRepository()
{
	return this->fieldAgentRepository.getAll();
}

int Service::sizeOfFieldAgentRepository()
{
	return this->fieldAgentRepository.size();
}
