#pragma once

#include "Tape.h"
#include "DynamicArray.h"

typedef Tape* TElement;

class Repository
{
private:
	DynamicArray<TElement> dynamicArray{};

public:
	Repository();
	void add(TElement element);
	void remove(TElement element);
	void update(TElement newTElement);
	TElement* getAll();
	TElement getElement(int position);
	int size();
	TElement find(TElement element);
};

