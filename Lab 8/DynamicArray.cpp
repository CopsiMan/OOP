#include "DynamicArray.h"

//void DynamicArray::resize()
//{
//	this->capacity *= 2;
//	TElement* newArray = new TElement[this->capacity];
//
//	for (int i = 0; i < this->size; i++)
//		newArray[i] = this->elements[i];
//
//	delete[] this->elements;
//	this->elements = newArray;
//}
//
//DynamicArray::DynamicArray(int capacity)
//{
//	this->capacity = capacity;
//	this->size = 0;
//	this->elements = new TElement[capacity];
//}
//
//void DynamicArray::add(TElement element)
//{
//	if (this->size == this->capacity)
//		this->resize();
//
//	this->elements[this->size++] = element;
//}
//
//int DynamicArray::getIndex(TElement element)
//{
//	int index = -1;
//	for (int i = 0; i < this->size; i++)
//		if (*this->elements[i] == *element)
//			index = i;
//	return index;
//}
//
//TElement DynamicArray::getElement(int position)
//{
//	if (position < 0 || position >= this->size)
//		throw "Invalid Position";
//	return this->elements[position];
//}
//
//void DynamicArray::remove(int position)
//{
//	if (position < 0 || position >= this->size)
//		throw "Position out of range";
//
//	delete this->elements[position];
//	for (int i = position; i < this->size - 1; i++)
//		this->elements[i] = this->elements[i + 1];
//	
//	this->size--;
//}
//
//int DynamicArray::getSize() const
//{
//	return this->size;
//}
//
//TElement* DynamicArray::getElements()
//{
//	return this->elements;
//}
//
//DynamicArray::~DynamicArray()
//{
//	for (int i = 0; i < this->size; i++)
//		delete this->elements[i];
//	delete[] this->elements;
//}
