#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


struct LEGO {
	string number, theme, name;
	int numParts, numMinifigures;
	double price;

	LEGO(string number, string theme, string name, int minifigures, int numParts, double price) {
		this->number = number;
		this->theme = theme;
		this->name = name;
		this->numMinifigures = minifigures;
		this->numParts = numParts;
		this->price = price;
	}

	string getNumber() {
		return number;
	}
	string getTheme() {
		return theme;
	}
	string getName() {
		return name;
	}
	int getNumParts() {
		return numParts;
	}
	int getNumMinifigures() {
		return numMinifigures;
	}
	double getPrice() {
		return price;
	}

	void setNumber(string number) {
		this->number = number;
	}
	void setTheme(string theme) {
		this->theme = theme;
	}
	void setName(string name) {
		this->name = name;
	}
	void setNumParts(int num) {
		this->numParts = num;
	}
	void setNumMinifigures(int num) {
		this->numMinifigures = num;
	}
	void setPrice(double price) {
		this->price = price;
	}

	void printLEGO() {
		cout << "Name: " << name << endl;
		cout << "Number: " << number << endl;
		cout << "Theme: " << theme << endl;
		cout << "Price: $" << price << endl;
		cout << "Minifigures: " << numMinifigures << endl;
		cout << "Piece count: " << numParts << endl;
	}

	void printIDNamePrice() {
		cout << number << " " << name << " $" << price << endl;
	}
};

int getAvgMinifigures(vector<LEGO>&);
double getAvgPrice(vector<LEGO>&);
int getMaximumPriceSet(vector<LEGO>&);
int getMinimumPriceSet(vector<LEGO>&);
int getMaxMinifigures(vector<LEGO>&);
double getTotalCost(vector<LEGO> &v);
int getTotalParts(vector<LEGO> &v);
int getTotalMinifigures(vector<LEGO> &v);
void ReadFile(string str, vector<LEGO> &v);

int main()
{

	vector<LEGO> legos;

	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	//switch case through files

	switch (option) {
	case 1: {
		ReadFile("lego1.csv", legos);
		break;
	}
	case 2: {
		ReadFile("lego2.csv", legos);
		break;
	}
	case 3: {
		ReadFile("lego3.csv", legos);
		break;
	}
	case 4: {
		ReadFile("lego1.csv", legos);
		ReadFile("lego2.csv", legos);
		ReadFile("lego3.csv", legos);
		break;
	}
	}


	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << legos.size() << endl;

	
	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input


				/*======= Based on the choice, execute the appropriate task and show the results =======*/
	switch (choice) {
	case 1: //most expensive set
	{
		double largestPrice = -1;
		int savedIndex = 0;

		for (unsigned int i = 0; i < legos.size(); i++) {
			if (legos[i].getPrice() > largestPrice) {
				savedIndex = i;
				largestPrice = legos[i].getPrice();
			}
		}

		cout << "The most expensive set is:" << endl;

		legos[savedIndex].printLEGO();
		break;
	}
	case 2: //largest piece count
	{
		int largestCount = -1;
		int savedIndex = 0;
		for (unsigned int i = 0; i < legos.size(); i++) {
			if (legos[i].getNumParts() > largestCount) {
				savedIndex = i;
				largestCount = legos[i].getNumParts();
			}
		}

		cout << "The set with the highest parts count:" << endl;

		legos[savedIndex].printLEGO();
		break;
	}
	case 3: //search for set name containing...
	{
		string in;
		getline(cin, in);

		vector<LEGO> matches;

		for (unsigned int i = 0; i < legos.size(); i++) {
			if (legos[i].getName().find(in) != string::npos) {
				matches.push_back(legos[i]);
			}
		}

		if (matches.size() == 0) {
			cout << "No sets found matching that search term";
		}
		else {
			cout << "Sets matching \"" << in << "\":" << endl;

			for (unsigned int i = 0; i < matches.size(); i++) {
				matches[i].printIDNamePrice();
			}
		}

		break;
	}
	case 4: //search themes
	{
		string in;
		getline(cin, in);
		
		vector<LEGO> matches;

		for (unsigned int i = 0; i < legos.size(); i++) {
			if (legos[i].getTheme().find(in) != string::npos) {
				matches.push_back(legos[i]);
			}
		}

		if (matches.size() == 0) {
			cout << "No sets found matching that search term";
		}
		else {
			cout << "Sets matching \"" << in << "\":" << endl;

			for (unsigned int i = 0; i < matches.size(); i++) {
				matches[i].printIDNamePrice();
			}
		}

		break;
	}
	case 5: //average part count
	{
		int totalParts = 0;

		for (unsigned int i = 0; i < legos.size(); i++) {
			totalParts += legos[i].getNumParts();
		}

		int avg = totalParts / legos.size();

		cout << "Average part count for " << legos.size() << " sets: " << avg << endl;
		break;
	}
	case 6: //show average, minimum, and maximum prices
	{
		cout << "Average price for " << legos.size() << " sets: $" << getAvgPrice(legos) << endl;

		cout << "Least expensive set:" << endl;

		legos[getMinimumPriceSet(legos)].printLEGO();

		cout << "Most expensive set:" << endl;

		legos[getMaximumPriceSet(legos)].printLEGO();

		break;
	}
	case 7: //minifigure information
	{
		cout << "Average number of minifigures: " << getAvgMinifigures(legos) << endl;

		cout << "Set with the most minifigures:" << endl;
		legos[getMaxMinifigures(legos)].printLEGO();

		break;
	}
	case 8:
	{
		cout << "If you bought one of everything..." << endl;
		cout << "It would cost: $" << getTotalCost(legos) << endl;
		cout << "You would have " << getTotalParts(legos) << " pieces in your collection" << endl;
		cout << "You would have an army of " << getTotalMinifigures(legos) << " minifigures!" << endl;

		break;
	}
	}

	return 0;
}

double getAvgPrice(vector<LEGO> &v) {
	double totalPrice = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		totalPrice += v[i].getPrice();
	}

	double avg = totalPrice / v.size();

	return avg;
}

int getMinimumPriceSet(vector<LEGO> &v) {
	double minPrice = INT64_MAX;
	int savedIndex = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i].getPrice() < minPrice) {
			minPrice = v[i].getPrice();
			savedIndex = i;
		}
	}

	return savedIndex;
}

int getMaximumPriceSet(vector<LEGO> &v) {
	double maxPrice = -1;
	int savedIndex = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i].getPrice() > maxPrice) {
			maxPrice = v[i].getPrice();
			savedIndex = i;
		}
	}

	return savedIndex;
}

int getAvgMinifigures(vector<LEGO> &v) {
	int totalMinifigures = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		totalMinifigures += v[i].getNumMinifigures();
	}

	return totalMinifigures / v.size();
}

int getMaxMinifigures(vector<LEGO> &v) {
	int maxMinifigures = -1;
	int savedIndex = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		if (v[i].getNumMinifigures() > maxMinifigures) {
			maxMinifigures = v[i].getNumMinifigures();
			savedIndex = i;
		}
	}

	return savedIndex;
}

double getTotalCost(vector<LEGO> &v) {

	double cost = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		cost += v[i].getPrice();
	}

	return cost;
}

int getTotalParts(vector<LEGO> &v) {
	int parts = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		parts += v[i].getNumParts();
	}

	return parts;
}

int getTotalMinifigures(vector<LEGO> &v) {
	int mini = 0;

	for (unsigned int i = 0; i < v.size(); i++) {
		mini += v[i].getNumMinifigures();
	}

	return mini;
}

void ReadFile(string str, vector<LEGO> &v) {
	string line;

	string number, theme, name;
	int numParts, numMinifigures;
	double price;

	ifstream file(str);

	getline(file, line);

	while (getline(file, line)) {
		stringstream s(line);
		getline(s, line, ',');
		number = line;
		getline(s, line, ',');
		theme = line;
		getline(s, line, ',');
		name = line;
		getline(s, line, ',');
		numMinifigures = stoi(line);
		getline(s, line, ',');
		numParts = stoi(line);
		getline(s, line, '\n');
		price = stod(line);

		v.push_back(LEGO(number, theme, name, numMinifigures, numParts, price));
	}

}