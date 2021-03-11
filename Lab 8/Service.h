#pragma once

#include "Repository.h"
#include "FileRepository.h"
#include <string.h>

#define MAX_ARGUMENTS 5
#define TITLE 0
#define FILMED_AT 1
#define CREATION_DATE 2
#define ACCES_COUNT 3
#define FOOTAGE_PREVIEW 4

class Service
{
private:
	//Repository repository{};
	FileRepository repository{};
	Repository fieldAgentRepository{};
	int positionInRepository;

public:
	//std::string* parseInput(std::string userCommand);
	Service();
	void add(std::string title, std::string filmedAt, Date creationDate, int accessCount, std::string footagePreview);
	void remove(std::string title);
	void update(std::string title, std::string filmedAt, Date creationDate, int accessCount, std::string footagePreview);
	std::vector<TElement> getAll();
	int size();
	void setPath(std::string filePath);
	TElement nextElement();
	void saveToFieldAgentRepository(std::string title);
	TElement* getAllFromFieldAgentRepository();
	int sizeOfFieldAgentRepository();
};

