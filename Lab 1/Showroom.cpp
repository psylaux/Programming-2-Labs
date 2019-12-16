#include "Showroom.h"

Showroom::Showroom(string name, unsigned int capacity) {
	this->name = name;
	this->capacity = capacity;
}

const vector<Vehicle>& Showroom::GetVehicleList() const {
	return this->vehicles;
}

void Showroom::AddVehicle(const Vehicle& v) {
	if (this->vehicles.size() == capacity) {
		cout << "Showroom is full! Cannot add " << v.GetYearMakeModel();
	}
	else {
		this->vehicles.push_back(v);
	}
}

void Showroom::ShowInventory() const {
	if (this->vehicles.size() == 0) {
		cout << this->name << " is empty!";
	}
	else {
		cout << "\nVehicles in " << this->name;
		for (unsigned int i = 0; i < this->vehicles.size(); i++) {
			cout << endl;
			this->vehicles[i].Display();
		}
	}
}

