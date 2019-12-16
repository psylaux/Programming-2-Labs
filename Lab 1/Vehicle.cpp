#include "Vehicle.h"

	Vehicle::Vehicle() {}
	Vehicle::Vehicle(string make, string model, int year, float price, int miles) {
		this->make = make;
		this->model = model;
		this->year = year;
		this->price = price;
		this->miles = miles;
	}

	//1973 ford mustang $9500 113000
	void Vehicle::Display() const {
		cout << GetYearMakeModel() << " $" << this->price << " " << this->miles;
	}

	//1970 ford mustang
	string Vehicle::GetYearMakeModel() const {
		string line = to_string(this->year) + " " + this->make + " " + this->model;
		return line;
	}

	float Vehicle::GetPrice() const {
		return this->price;
	}