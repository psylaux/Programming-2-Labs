#include "Dealership.h"


Dealership::Dealership() {}
Dealership::Dealership(string name, unsigned int capacity) {
	this->name = name;
	this->capacity = capacity;
}

void Dealership::AddShowroom(const Showroom &s) {
	unsigned int numberOfShowrooms = this->showrooms.size();

	if (numberOfShowrooms == capacity) {
		cout << "Dealership is full, can't add another showroom!";
	}
	else {
		this->showrooms.push_back(s);
	}
}

float Dealership::GetAveragePrice() const {
	float totalPrice = 0;
	int numberOfShowrooms = this->showrooms.size();
	int numberOfVehicles = 0;

	if (numberOfShowrooms == 0) {
		return 0;
	}

	for (int i = 0; i < numberOfShowrooms; i++) {
		numberOfVehicles += this->showrooms[i].GetVehicleList().size();
	}

	for (unsigned int i = 0; i < this->showrooms.size(); i++) {
		for (unsigned int j = 0; j < this->showrooms[i].GetVehicleList().size(); j++) {
			totalPrice += this->showrooms[i].GetVehicleList()[j].GetPrice();
		}
	}

	return totalPrice / numberOfVehicles;
}

void Dealership::ShowInventory() const {
	if (this->showrooms.size() == 0) {
		cout << this->name << " is empty!";
	}
	else {
		for (unsigned int i = 0; i < showrooms.size(); i++) {
			this->showrooms[i].ShowInventory();
		}
	}

	cout << "\nAverage car price: $" << this->GetAveragePrice();
}