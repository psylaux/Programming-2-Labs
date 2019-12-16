#pragma once

#include <string>
#include <iostream>

using namespace std;

template<typename T>
class ABS {
private:
	T * data;
	unsigned int size;
	unsigned int capacity;

public:
	ABS();
	ABS(int capacity);
	ABS(const ABS &d);
	ABS &operator=(const ABS &d);
	~ABS();

	void push(T data);
	T pop();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();

	void resize(float factor);

	const float scale_factor = 2.0f;
};

//constructors
template<typename T>
ABS<T>::ABS() {
	size = 0;
	capacity = 1;

	data = nullptr;
}

template<typename T>
ABS<T>::ABS(int capacity) {
	size = 0;
	this->capacity = capacity;

	data = new T[capacity];
}

//copy constructor
template<typename T>
ABS<T>::ABS(const ABS &d) {

	this->size = d.size;
	this->capacity = d.capacity;

	this->data = new T[capacity];

	for (int i = 0; i < size; i++) {
		this->data[i] = d.data[i];
	}
}

//assignment operator
template<typename T>
ABS<T> &ABS<T>::operator=(const ABS &d) {
	this->size = d.size;
	this->capacity = d.capacity;

	this->data = new T[capacity];

	for (int i = 0; i < size; i++) {
		this->data[i] = d.data[i];
	}

	return *this;
}

//destructor
template<typename T>
ABS<T>::~ABS() {
	delete[] data;
}

//methods

template<typename T>
void ABS<T>::push(T d) {

	if (data == nullptr) {
		data = new T[capacity];
	}

	if ( size == capacity) {
		resize(2);
	}

	this->data[size] = d;
	size++;
}

template<typename T>
T ABS<T>::pop() {

	if (size == 0) {
		throw("Empty array");
	}

	if ((size / capacity) < (1 / scale_factor)) {
		resize(.5);
	}

	T* newPtr = new T[capacity];

	T removed = data[size-1];

	for (unsigned int i = 0; i < size-1; i++) {
		newPtr[i] = data[i];
	}

	size--;
	delete[] data;
	data = newPtr;

	return removed;
}

template<typename T>
T ABS<T>::peek() {
	if (size == 0) {
		throw("Empty array");
	}

	return data[size-1];
}

template<typename T>
unsigned int ABS<T>::getSize() {
	return size;
}

template<typename T>
unsigned int ABS<T>::getMaxCapacity() {
	return capacity;
}

template<typename T>
T* ABS<T>::getData() {
	return data;
}

template<typename T>
void ABS<T>::resize(float factor) {
	
	capacity *= factor;

	T* newArray = new T[capacity];

	for (unsigned int i = 0; i < size; i++) {
		newArray[i] = data[i];
	}

	delete[] data;

	data = newArray;

}
