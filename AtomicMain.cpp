//Main.cpp

#include <iostream>
#include "Atomic.h"
using namespace std;




int main() {


	int  input = 0;
	while (input == 0) {
		cout << "====Main Menu====" << endl << endl;

		cout << "1: Load File Entries\n";
		cout << "2: List Entries\n";
		cout << "3: Load Testing Strings\n";
		cout << "4: Run\n";

		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cout << "Enter a Number!\n\n";
		}


		switch (input) {
		case 1:	cout << "Loading Files...\n";
			break;
		case 2: cout << "List Entries...\n";
			break;
		case 3: cout << "Testing Strings...\n";
			break;
		case 4: cout << "Run\n";
			break;

		}
		cin.ignore(1000, '\n');

	}

	return 0;

}