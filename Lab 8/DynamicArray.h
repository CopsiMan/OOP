#pragma once

#include "Tape.h"

//typedef void* TElement;
//typedef Tape* TElement;

template <typename TElement>
class DynamicArray
{
	TElement* elements;
	int capacity;
	int size;

	void resize();

public:
	DynamicArray(int capacity = 8);
	void add(TElement element);

	// returns an index of an element , -1 if not found
	int getIndex(TElement element);
	TElement getElement(int position);
	void remove(int position);
	int getSize() const;
	TElement* getElements();
	~DynamicArray();
};

template <typename TElement>
void DynamicArray<TElement>::resize()
{
	this->capacity *= 2;
	TElement* newArray = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		newArray[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newArray;
}

template <typename TElement>
DynamicArray<TElement>::DynamicArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new TElement[capacity];
}

template <typename TElement>
void DynamicArray<TElement>::add(TElement element)
{
	if (this->size == this->capacity)
		this->resize();

	this->elements[this->size++] = element;
}

template <typename TElement>
int DynamicArray<TElement>::getIndex(TElement element)
{
	int index = -1;
	for (int i = 0; i < this->size; i++)
		if (*this->elements[i] == *element)
			index = i;
	return index;
}

template <typename TElement>
TElement DynamicArray<TElement>::getElement(int position)
{
	if (position < 0 || position >= this->size)
		throw "Invalid Position";
	return this->elements[position];
}

template <typename TElement>
void DynamicArray<TElement>::remove(int position)
{
	if (position < 0 || position >= this->size)
		throw "Position out of range";

	delete this->elements[position];
	for (int i = position; i < this->size - 1; i++)
		this->elements[i] = this->elements[i + 1];

	this->size--;
}

template <typename TElement>
int DynamicArray<TElement>::getSize() const
{
	return this->size;
}

template <typename TElement>
TElement* DynamicArray<TElement>::getElements()
{
	return this->elements;
}

template <typename TElement>
DynamicArray<TElement>::~DynamicArray()
{
	for (int i = 0; i < this->size; i++)
		delete this->elements[i];
	delete[] this->elements;
}


