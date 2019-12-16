#pragma once
using namespace std;

#include <string>

class Color {

private:

	unsigned char r, g, b;
	string name, hex;
	int intvalue;

public:

	void SetValue(int value);
	void SetName(const char *name);

	//Accessors
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
	int GetIntValue() const;
	
	void Print() const;

	Color();


};