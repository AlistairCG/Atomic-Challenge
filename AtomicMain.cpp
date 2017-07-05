//Main.cpp

#include <iostream>
#include "Atomic.h"
using namespace std;




int main() {


	int  input = 1;
	Atomic A;
	while (input != 0) {
		cout << "====Main Menu====" << endl << endl;

		cout << "1: Load File Entries\n";
		cout << "2: List Entries\n";
		cout << "3: Load Testing Strings\n";
		cout << "4: Run\n";
		cout << "5: Exit\n";

		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cout << "Enter a Number!\n\n";
		}

		
		switch (input) {

		case 1:	cout << "Loading Files...\n";
			A.LoadFiles();
			break;
		case 2: cout << "List Entries...\n";
			A.ListFileEntry();
			break;
		case 3: cout << "Testing Strings...\n";
			break;
		case 4: cout << "Run\n";
			A.Run();
			break;
		case 5: cout << "Good bye\n";
			input = 0; //Exit
			break;
		default: cout << "Sorry that is not a valid number!";
			break;
		}
		cin.ignore(1000, '\n');

	}

	return 0;

}