
/*===== #include statements go here =====*/
#pragma once
#include <string>
#include <iostream>

/*===== using statements go here =====*/
using namespace std;

class Vehicle
{
private:
	// Private stuff goes here: Data members, functions the "outside world" doesn't need to know about
	string make = "COP3503";
	string model = "Rust Bucket";
	unsigned int year = 1900;
	float price = 0;
	unsigned int miles = 0;


public:
	// Functions go here, and any public variables, if you're using them (generally you shouldn't)
	Vehicle();
	Vehicle(string make, string model, int year, float price, int miles);
	void Display() const;
	string GetYearMakeModel() const;
	float GetPrice() const;
};