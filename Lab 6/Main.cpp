#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Color.h"
using namespace std;

void ReadFile(const char *filename, vector<Color> &outVector);
void SortColors(vector<Color> &colors);
void PrintColors(const vector<Color> &colors);
void PrintColor(Color color);
Color Search(const vector<Color> &colors, string color);


int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	
	int choice;
	cin >> choice;
	vector<Color> colors;
	// Load the selected files
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";

		ReadFile(file.c_str(), colors);

	}
	else if (choice == 7)
	{

		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}
	}

	// Sort and print the loaded data
	SortColors(colors);

	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1) {
		PrintColors(colors);
	}
	else if (choice == 2) {
		string color;
		cin >> color;
		PrintColor(Search(colors, color));
	}

	return 0;
}

void ReadFile(const char *filename, vector<Color> &outVector)
{
	// TODO: Load the file and store the resulting colors in outVector.
	fstream file(filename, ios_base::in);

	string str, temp1="",temp2="";
			
	while (getline(file,str)) {
		Color c;
		//string line, intline;

		stringstream buffer(str);

		getline(buffer, temp1, ' ');
		//cout << line << " ";
		c.SetName(temp1.c_str());

		getline(buffer, temp2);
		//cout << num << endl;
		
		int num =stoi(temp2);
		//buffer >> num;
		c.SetValue(num);


		outVector.push_back(c);
	}

	file.close();
}

void SortColors(vector<Color> &colors)
{
	// TODO: Sort the colors in ascending order by name.
	Color temp;
	unsigned int i, j;
	for ( i = 1; i < colors.size(); i++) {
		j = i;

		while ( j > 0 && colors[j - 1].GetName() > colors[j].GetName()) {

			temp = colors[j];
			colors[j] = colors[j - 1];
			colors[j - 1] = temp;
			j--;

		}

	}
}

Color Search(const vector<Color> &colors, string color) {
	for (unsigned int i = 0; i < colors.size(); i++) {
		if (colors[i].GetName() == color) {
			return colors[i];
		}
	}
	cout << color << "not found!";
	Color c;
	c.SetName("Not Found");
	return c;
}

void PrintColors(const vector<Color> &colors)
{
	for (unsigned int i = 0; i < colors.size(); i++)
	{

		//colors[i].Print();

		cout << colors[i].GetName();
		for (unsigned int j = 0; j < 3 - colors[i].GetName().size() / 8; j++)
			cout << "\t";
		cout << colors[i].GetHexValue() << '\t' << (int)colors[i].GetR() << "," << (int)colors[i].GetG() << "," << (int)colors[i].GetB() << endl;
	}
	cout << "Number of colors: " << colors.size() << endl;
}

void PrintColor(Color color) {
	if (color.GetName() == "Not Found") return;
	cout << color.GetName();
	for (unsigned int j = 0; j < 3 - color.GetName().size() / 8; j++)
		cout << "\t";
	cout << color.GetHexValue() << '\t' << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}