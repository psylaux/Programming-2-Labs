#include "Color.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

Color::Color() {}

void Color::SetValue(int value) {
	char hexArray[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	intvalue = value;

	this->r = (value >> 16) & 255;
	this->g = (value >> 8) & 255;
	this->b = (value) & 255;

	int val;

	while (intvalue){
		val = intvalue % 16;
		hex = hexArray[val] + hex;
		intvalue = intvalue / 16;
	}

	while (hex.length() < 6) {
		hex = "0" + hex;
	}

	hex = "0x" + hex;
}

void Color::SetName(const char *name) {

	this->name = name;

}

//Accessors
unsigned char Color::GetR() const {

	return r;

}
unsigned char Color::GetG() const {

	return g;

}
unsigned char Color::GetB() const {

	return b;

}
string Color::GetHexValue() const {

	return hex;

}
string Color::GetName() const {

	return name;

}
int Color::GetIntValue() const {

	return intvalue;

}
void Color::Print() const {

	cout << GetName() << " ";
	cout << GetIntValue() << endl;

}