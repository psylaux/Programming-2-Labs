#include <string>
using namespace std;

class LEGO {
	string set, theme, name;
	int numParts, numMinifigures;
	double price;

	LEGO(string, string, string, int, int, double);

	vector<LEGO> legos;

	string getSet();
	string getTheme();
	string getName();
	int getNumParts();
	int getNumMinifigures();
	double getPrice();

	void setSet(string);
	void setTheme(string);
	void setName(string);
	void setNumParts(int);
	void setNumMinifigures(int);
	void setPrice(double);
	
	void printLEGO();
	void printIDNamePrice();

};

LEGO::LEGO(string set, string theme, string name, int numParts, int minifigures, double price) {
	this->set = set;
	this->theme = theme;
	this->name = name;
	this->numParts = numParts;
	this->numMinifigures = minifigures;
	this->price = price;
}

string LEGO::getSet() {
	return set;
}
string LEGO::getTheme() {
	return theme;
}
string LEGO::getName() {
	return name;
}
int LEGO::getNumParts() {
	return numParts;
}
int LEGO::getNumMinifigures() {
	return numMinifigures;
}
double LEGO::getPrice() {
	return price;
}

void LEGO::setSet(string set) {
	this->set = set;
}
void LEGO::setTheme(string theme) {
	this->theme = theme;
}
void LEGO::setName(string name) {
	this->name = name;
}
void LEGO::setNumParts(int num) {
	this->numParts = num;
}
void LEGO::setNumMinifigures(int num) {
	this->numMinifigures = num;
}
void LEGO::setPrice(double price) {
	this->price = price;
}

void LEGO::printLEGO() {
	cout << "Name: " << name << endl;
	cout << "Number: " << set << endl;
	cout << "Theme: " << theme << endl;
	cout << "Price: $" << price << endl;
	cout << "Minifigures: " << numMinifigures << endl;
	cout << "Piece count: " << numParts << endl;
}

void LEGO::printIDNamePrice() {
	cout << set << " " << name << " $" << price << endl;
}