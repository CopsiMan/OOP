#include "Repository.h"

Repository::Repository()
{

}

void Repository::add(TElement element)
{
	// -1 means the element was not found
	if (this->dynamicArray.getIndex(element) == -1)
		this->dynamicArray.add(element);
	else {
		delete element;
		throw "Element already exists!";
	}
}

void Repository::remove(TElement element)
{
	int position = this->dynamicArray.getIndex(element);
	// -1 means the element was not found
	if (position == -1) {
		delete element;
		throw "Element doesn't exist";
	}
	else
		//delete &element;
		this->dynamicArray.remove(position);
}

void Repository::update(TElement newTElement)
{
	int position = this->dynamicArray.getIndex(newTElement);
	// -1 means the element was not found
	if (position == -1) {
		delete newTElement;
		throw "Element doesn't exist";
	}
	else {
		Tape* oldTape = this->dynamicArray.getElement(position);
		//delete &oldTape;
		// oldTape = &Tape{}
		*oldTape = *newTElement;
		delete newTElement;
	}
}

TElement* Repository::getAll()
{
	return this->dynamicArray.getElements();
}

TElement Repository::getElement(int position)
{
	return this->dynamicArray.getElement(position);
}

int Repository::size()
{
	return this->dynamicArray.getSize();
}

TElement Repository::find(TElement element)
{
	return this->dynamicArray.getElement(this->dynamicArray.getIndex(element));
}
