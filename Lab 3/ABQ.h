#pragma once

#include <string>
#include <iostream>

using namespace std;

template<typename T>
class ABQ{
private:
	T *data;
	unsigned int size;
	unsigned int capacity;

public:
	ABQ();
	ABQ(int capacity);
	ABQ(const ABQ &d);
	ABQ &operator=(const ABQ &d);
	~ABQ();

	void enqueue(T data);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();


	const T &operator[](int index) const;
	T & operator[](int index);


	void resize(float factor);

	const float scale_factor = 2.0f;
};

//constructors
template<typename T>
ABQ<T>::ABQ() {
	size = 0;
	capacity = 1;

	data = nullptr;
}

template<typename T>
ABQ<T>::ABQ(int capacity) {
	size = 0;
	this->capacity = capacity;

	data = new T[capacity];
}

//copy constructor
template<typename T>
ABQ<T>::ABQ(const ABQ &d) {

	this->size = d.size;
	this->capacity = d.capacity;

	this->data = new T[capacity];

	for (unsigned int i = 0; i < size; i++) {
		this->data[i] = d.data[i];
	}
}

//assignment operator
template<typename T>
ABQ<T> &ABQ<T>::operator=(const ABQ &d) {
	this->size = d.size;
	this->capacity = d.capacity;

	this->data = new T[capacity];

	for (unsigned int i = 0; i < size; i++) {
		this->data[i] = d.data[i];
	}

	return *this;
}


//destructor
template<typename T>
ABQ<T>::~ABQ() {
	delete[] data;
}

//methods

template<typename T>
void ABQ<T>::enqueue(T d) {
	
	if (data == nullptr) {
		data = new T[capacity];
	}

	if (size == capacity) {
		resize(2);
	}

	data[size] = d;
	size++;

}

template<typename T>
T ABQ<T>::dequeue() {

	if (size == 0) {
		throw("Empty array");
	}

	if ((size/capacity) < (1/scale_factor)) {
		resize(.5);
	}


	T* newPtr;
	newPtr = new T[capacity];

	T val = data[0];

	for (unsigned int i = 1; i < size; i++) {
		newPtr[i-1] = data[i];
	}

	size--;

	for(unsigned int )
	delete[] data;
	data = nullPtr;

	return val;

}

template<typename T>
T ABQ<T>::peek() {

	if (size == 0) {
		throw("Empty array");
	}

	return data[0];
}

template<typename T>
unsigned int ABQ<T>::getSize() {
	return size;
}

template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
	return capacity;
}

template<typename T>
T* ABQ<T>::getData() {
	return data;
}

template<typename T>
void ABQ<T>::resize(float factor) {
	
	capacity *= factor;

	T* newArray = new T[capacity];

	for (unsigned int i = 0; i < size; i++) {
		newArray[i] = data[i];
	}

	delete[] data;

	data = newArray;

}
