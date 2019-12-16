#pragma once
/*===== #include statements go here =====*/
// strings, vectors, anything you need access to
// Also, if since this class needs to know about Vehicle objects... you need to include "Vehicle.h" as well
#include "Vehicle.h"
#include <vector>

/*===== using statements go here =====*/
using namespace std;

class Showroom
{
private:
	// Private stuff goes here: Data members, functions the "outside world" doesn't need to know about
	string name = "Unnamed Showroom";
	unsigned int capacity = 0;

	vector<Vehicle> vehicles;

public:
	// Functions go here, and any public variables, if you're using them (generally you shouldn't)

	Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
	//Getters
	const vector<Vehicle>& GetVehicleList() const;

	//Behaviors
	void AddVehicle(const Vehicle& v);
	void ShowInventory() const;
};