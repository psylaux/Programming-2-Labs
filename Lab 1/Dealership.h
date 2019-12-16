#pragma once
#include "Showroom.h"

using namespace std;

class Dealership {
private:
	string name = "Generic Dealership";
	unsigned int capacity = 0;
	vector<Showroom> showrooms;

public:
	Dealership();
	Dealership(string name, unsigned int capacity);

	void AddShowroom(const Showroom &s);
	float GetAveragePrice() const;
	void ShowInventory() const;
};