#pragma once

#include "Tape.h"
#include <vector>

typedef Tape* TElement;

class RepositoryInterface
{

public:
	RepositoryInterface();
	virtual void add(TElement element) = 0;
	virtual void remove(TElement element) = 0;
	virtual void update(TElement newTElement) = 0;
	virtual std::vector<TElement> getAll() = 0;
	virtual TElement getElement(int position) = 0;
	virtual int size() = 0;
	virtual TElement find(TElement element) = 0;
	virtual void setPath(std::string path) = 0;
	virtual ~RepositoryInterface();
	virtual std::string getPath() = 0;
};

