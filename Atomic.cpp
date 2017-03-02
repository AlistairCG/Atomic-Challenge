#include "Atomic.h"

using namespace std;


//Class for Atomics. Will hold parallel vectors of Atomic Name and Atomic Value. 
//Tied by array.
/*
Main Menu:
	

	-> Load Entry Files and specify file arguements.
		This function will accept text files of N size and read 
		line seperated data(Should this be a single value per line or keep reading?).
		Each text file will run in parralel of vector with each other, meaning the class must count!

	-> List entries. 
		Function will list all known entries from file, seperated by comma.

	-> Load Strings and specify file arguement.
		Function will read strings seperated on spaces. These could be loaded on start?
		Assuming valid input, display success!

	-> Run
		Function will check for all load flags. If good, attempt to replace 
		elements in the string with corresponding Elements fom entry file. 
		Will keep expanding search parameter depending on max length of entry files.



Class Note:

Atomic Data Holder(Need generic name):

Needs vectors of file args. 
Max file arg length(max string size)
Load flags.
File Name(s)/array.





*/

int Atomic::LoadFiles()
{
	string Origin, Replace;
	fstream FinOr, FinRep;
	string tmp = "";
	int line = 0;

	cout << "Specfiy Origin File Name(Including extensions): ";
	cin >> Origin;
	cout << "\nSpecify Replacement File Name: ";
	cin >> Replace;

	//File IO and err check
	FinOr.open(Origin);
	FinRep.open(Replace);


	if (!FinOr.is_open()) {
		cout << "Origin File '" << Origin << "' could not be opened!\n";
		
		return -1;
	}
	else if(!FinRep.is_open()){
		cout << "Replacement File '" << Replace << "' could not be opened!\n";
		return -2;
	}
	else {
		//File Read
		//Origin.assign((istreambuf_iterator<char>(FinOr)), (istreambuf_iterator<char>()));
		
		
		while (FinOr) {
			
			

			if (line < 3) {
				
				//Read
				FinOr >> tmp;
				//Assign
				if (tmp != "") {
					if (line == 0)ReplacementName.push_back(tmp);
					if (line == 1)ReplacementCode.push_back(tmp);
					if (line == 2)ReplacementTie.push_back(tmp);
				}
				//Count
				line++;
				tmp = "";

			}
			else {
				//Garbage
				getline(FinOr, tmp);
				//Reset

				tmp = "";
				line = 0;
			}
			
		}
		Replace.assign((istreambuf_iterator<char>(FinRep)), (istreambuf_iterator<char>()));

		
		}

	FinOr.close();
	FinRep.close();



	return 0;
}

void Atomic::ListFileName()
{
}

void Atomic::ListFileEntry()
{
}

std::string Atomic::Run()
{
	return std::string();
}
