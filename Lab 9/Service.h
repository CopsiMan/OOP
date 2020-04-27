#pragma once

/**/
#include "RepositoryInterface.h"
#include "MemoryRepository.h"
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
	/*
	RepositoryInterface* adminRepository = new FileRepository{};
	RepositoryInterface* fieldAgentRepository = new MemoryRepository{};
	*/
	RepositoryInterface* adminRepository;
	RepositoryInterface* fieldAgentRepository;

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
	void setMyListPath(std::string myListPath);
	TElement nextElement();
	void saveToFieldAgentRepository(std::string title);
	std::vector<TElement> getAllFromFieldAgentRepository();
	int sizeOfFieldAgentRepository();
	std::string getFieldAgentPath();
	~Service();
};

