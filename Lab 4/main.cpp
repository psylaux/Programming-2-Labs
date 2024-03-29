#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Starship {
	string name_, class_;
	int length_, shield_;
	float maxWarp_;
	struct Armament {
		string weapon;
		int firepower;
		float warp;
		Armament() {};
		Armament(string weapon, int firepower, float warp) {
			this->weapon = weapon;
			this->firepower = firepower;
			this->warp = warp;
		}
	};

	vector<Armament> armaments;
	Starship() {};
	Starship(string name_, string class_, int length_, int shield_, float maxWarp_, vector<Armament> arms) {
		this->name_ = name_;
		this->class_ = class_;
		this->length_ = length_;
		this->shield_ = shield_;
		this->maxWarp_ = maxWarp_;
		for (unsigned int i = 0; i < arms.size(); i++) {
			this->armaments.push_back(arms[i]);
		}
	}


	void printShip() {
		cout << "Name: " << name_ << endl;
		cout << "Class: " << class_ << endl;
		cout << "Length: " << length_ << endl;
		cout << "Shield capacity: " << shield_ << endl;
		cout << "Maximum Warp: " << maxWarp_ << endl;
		cout << "Armaments: " << endl;

		if (armaments.size() > 0) {
			int total = 0;
			for (unsigned int i = 0; i < armaments.size(); i++) {
				total += armaments[i].firepower;
				cout << armaments[i].weapon << ", " << armaments[i].firepower << ", " << armaments[i].warp << endl;
			}
			cout << "Total firepower: " << total;
		}
		else {
			cout << "Unarmed";
		}
	}

	int getTotalPower() {
		int total = 0;
		for (unsigned int i = 0; i < armaments.size(); i++) {
			total += armaments[i].firepower;
		}
		return total;
	}

};

void LoadFile(string, vector<Starship>&);
string convertToString(char*, int);

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	vector<Starship> ships;

	/* Load files here */
	switch (option) {
	case 1: {
		LoadFile("friendlyships.shp", ships);
		break;
	}
	case 2: {
		LoadFile("enemyships.shp", ships);
		break;
	}
	case 3: {
		LoadFile("friendlyships.shp", ships);
		LoadFile("enemyships.shp", ships);
		break;
	}
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */

	switch (option) {
	//print all ships
	case 1: {
		cout << "Number of ships: " << ships.size() << endl;
		for (unsigned int i = 0; i < ships.size(); i++) {
			ships[i].printShip();
			cout << endl << endl;
		}
		break;
	}
	//strongest weapon
	case 2: {
		Starship strongest;
		int highestFP = 0;
		for (unsigned int i = 0; i < ships.size(); i++) {
			for (unsigned int j = 0; j < ships[i].armaments.size(); j++) {
				if (ships[i].armaments[j].firepower > highestFP) {
					highestFP = ships[i].armaments[j].firepower;
					strongest = ships[i];
				}
			}
		}
		try {
			strongest.printShip();
		}
		catch (exception e) {
			cout << "no such ship";
		}
		break;
	}
	//print the most powerful ship
	case 3: {
		Starship powerful;
		int highestPower = 0;
		for (unsigned int i = 0; i < ships.size(); i++) {
			int totalPower = ships[i].getTotalPower();
			if (totalPower > highestPower) {
				highestPower = totalPower;
				powerful = ships[i];
			}
		}
		try {
			powerful.printShip();
		}
		catch (exception e) {
			cout << "no such ship";
		}
		break;
	}
	//print weakest ship
	case 4: {
		Starship weakest;
		int lowestPower = 2147483647;
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships[i].armaments.size() == 0) continue;
			int totalPower = ships[i].getTotalPower();
			if (totalPower < lowestPower) {
				lowestPower = totalPower;
				weakest = ships[i];
			}
		}
		try {
			weakest.printShip();
		}
		catch (exception e) {
			cout << "no such ship";
		}

		break;
	}
	//print unarmed ships
	case 5: {
		for (unsigned int i = 0; i < ships.size(); i++) {
			if (ships[i].armaments.size() == 0) {
				ships[i].printShip();
				cout << endl;
			}
		}
		break;
	}
	}

	return 0;
}

void LoadFile(string filename, vector<Starship>& v) {
	ifstream file(filename, ios_base::binary);
	
		int numOfShips;

		//ship info
		int lengthOfShipName, lengthOfShipClass;
		//string shipName, className;
		short shipLength;
		int shipShieldCap, shipWeaponCount;
		float shipWarp;
		
		//weapon info
		int lengthOfWeaponName, powerRating;
		//string weaponName;
		float powerConsumption;

		if (file.is_open()) { 

		file.read((char *)&numOfShips, 4);

		for (int i = 0; i < numOfShips; i++) {
			file.read((char *)&lengthOfShipName, 4);
			char* shipName = new char[lengthOfShipName];
			file.read((char *)&shipName[0], lengthOfShipName);

			file.read((char *)&lengthOfShipClass, 4);
			char* className = new char[lengthOfShipClass];
			file.read((char *)&className[0], lengthOfShipClass);

			file.read((char *)&shipLength, 2);
			file.read((char *)&shipShieldCap, 4);
			file.read((char *)&shipWarp, 4);
			file.read((char *)&shipWeaponCount, 4);
			vector<Starship::Armament> arms;
			for (int j = 0; j < shipWeaponCount; j++) {
				file.read((char *)&lengthOfWeaponName, 4);
				char* weaponName = new char[lengthOfWeaponName];
				file.read((char *)&weaponName[0], lengthOfWeaponName);
				file.read((char *)&powerRating, 4);
				file.read((char *)&powerConsumption, 4);

				Starship::Armament* s = new Starship::Armament(convertToString(weaponName, lengthOfWeaponName), powerRating, powerConsumption);
				arms.push_back(*s);
			}
			Starship* ship = new Starship(convertToString(shipName,lengthOfShipName), convertToString(className, lengthOfShipClass), shipLength, shipShieldCap, shipWarp, arms);
			v.push_back(*ship);
		}
		file.close();
	}
}

string convertToString(char* arr, int size) {
	int i;
	string s = "";
	for (i = 0; i < size-1; i++) {
		s = s + arr[i];
	}
	return s;
}