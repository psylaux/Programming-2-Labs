#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{

	/* Type code here. */
	string col1, col2, col3;
	string data = "";
	string name = "";
	int numOfNovels = 0;

	vector<string> nameList;
	vector<int> numList;

	cout << "Enter a title for the data:" << endl;
	getline(cin, col1);
	cout << "You entered: " << col1 << endl << endl;

	cout << "Enter the column 1 header:" << endl;
	getline(cin, col2);
	cout << "You entered: " << col2 << endl << endl;

	cout << "Enter the column 2 header:" << endl;
	getline(cin, col3);
	cout << "You entered: " << col3 << endl << endl;

	while (data.compare("-1") != 0) {

		cout << "Enter a data point (-1 to stop input):" << endl;
		getline(cin, data);

		try {
			if (stoi(data) == -1) break;
		}
		catch (exception e) {

		}

		size_t found = data.find(",");

		if (found == string::npos) {
			cout << "Error: No comma in string." << endl << endl;
			continue;
		}

		size_t nfound = data.find(",", found + 1);

		if (nfound != string::npos) {
			cout << "Error: Too many commas in input." << endl << endl;
			continue;
		}

		string num = data.substr(found + 1);

		try {
			numOfNovels = stoi(num);
		}
		catch (exception invalid_argument) {
			cout << "Error: Comma not followed by an integer." << endl << endl;
			continue;
		}

		name = data.substr(0, found);

		cout << "Data string: " << name << endl;
		cout << "Data integer: " << numOfNovels << endl << endl;

		nameList.push_back(name);
		numList.push_back(numOfNovels);

	}
	cout << endl;
	cout << setw(33) << col1 << endl;
	cout << left << setw(20) << col2;
	cout << "|";
	cout << right << setw(23) << col3 << endl;
	cout << "--------------------------------------------" << endl;

	//set up table
	for (unsigned int i = 0; i < nameList.size(); i++) {
		cout << left << setw(20) << nameList[i];
		cout << "|";
		cout << right << setw(23) << numList[i] << endl;
	}

	cout << endl;

	//set up chart

	for (unsigned int i = 0; i < nameList.size(); i++) {
		cout << right << setw(20) << nameList[i];
		cout << " ";
		for (int j = 0; j < numList[i]; j++) {
			cout << left << "*";
		}
		cout << endl;
	}

	return 0;
}