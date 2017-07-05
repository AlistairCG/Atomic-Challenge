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

	Origin = (Origin == ".") ? "Asym.txt" : Origin;
	Replace = (Replace == ".") ? "test.txt" : Replace;

	//File IO and err check
	FinOr.open(Origin);
	FinRep.open(Replace);


	if (!FinOr.is_open()) {
		cout << "Error: Origin File '" << Origin << "' could not be opened!\n";

		return -1;
	}
	else if (!FinRep.is_open()) {
		cout << "Error: Replacement File '" << Replace << "' could not be opened!\n";
		return -2;
	}
	else {
		//Set File names;
		SetFileName(Origin, Replace);

		while (FinOr) {
			if (line < 3) {
				//Read
				FinOr >> tmp;
				//Assign
				if (tmp != "") {
					if (line == 0)ReplacementName.push_back(tmp);
					if (line == 1) {
						ReplacementCode.push_back(tmp);
						//Update max size of the replacement elements
						if (Replacement_Count < tmp.size())Replacement_Count = tmp.size();
					}
				};

				if (line == 2)ReplacementTie.push_back(tmp);
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
		//Read the sentance that is being manipulated, nothing fancy.
		while (FinRep) {
			FinRep >> tmp;
			if (tmp != "")
				OriginalLines.push_back(tmp);
			tmp = "";

		}
		//Get string for replacements and assign to the object
		Replace.assign((istreambuf_iterator<char>(FinRep)), (istreambuf_iterator<char>()));
		Origin.assign((istreambuf_iterator<char>(FinOr)), (istreambuf_iterator<char>()));

	}

	FinOr.close();
	FinRep.close();
	GetFileName();
	ListFileEntry();


	return 0;
}

void Atomic::SetFileName(string orig, string repl)
{
	File_OriginalLine = orig;
	File_Replacment = repl;
}


//Output File Names
void Atomic::GetFileName()
{
	cout << "File Names are\n Origin: " << File_OriginalLine << "\n Replacement: " << File_Replacment << endl;

}
//Output the Object contents
void Atomic::ListFileEntry()
{
	cout << "Files entry is as follows\n Origin Entries: \n";
	int ii = 0;
	for (size_t i = 0; i < ReplacementName.size(); i++) {
		cout << setw(4) << left << ii++ << setw(20) << ReplacementName[i] << " | " << setw(5) << ReplacementCode[i] << " | " << setw(5) << ReplacementTie[i] << endl;
	}
	cout << "Collected weight values and letter substitutes to match!\n";
	cout << "The Replacement String is: ";
	for (size_t i = 0; i < OriginalLines.size(); i++) {
		cout << OriginalLines[i] << " ";
	}
	cout << endl;
}

//The objective of Isequal is only to determine how many potential matches exist. -1 for not a match, 0 for perfect match, and 1 for partial match.

int Atomic::isEqual(std::string Origin, std::string Replacement)
{
	//Make easy comparison
	Origin = Lower(Origin);
	Replacement = Lower(Replacement);


	cout << "DEBUG: ISEquals() Received the following:" << Origin << " " << Replacement << endl;
	unsigned int sz = Origin.size();
		if (Origin == Replacement) {
			return 0; //Perfect Match
		}
		else {
	
			for (unsigned int i = 0; i < Origin.size(); ++i) {
				cout << char(tolower(Origin[i])) << " <--Out|| "<<endl;
				//==========Check only when there is plausible match, ie first letter match==========//
				if (Origin[i] == Replacement[0]) {
					int concurmatch = Replacement.size();	
					//Check for Replacement inside of Origin as a partial match. Ex. 'Hello' part matches Hydrogen, Helium, and Oxygen(H,HE,O)
					for (unsigned int j = 1; j < Replacement.size(); ++j) {
						if (!(Replacement[j] == Origin[i + j]))
							return -1;
					}
				}

				//======================//
				
			}

		}


		//Part match
	return 1;
}

std::string Atomic::Run()
{


	//Go through each element of the replacement string
	for (size_t i = 0; i < OriginalLines.size(); i++) {
		//The string that needs to be changed.
		cout << "Original String: " << OriginalLines[i] << endl;

		//replacement and measure length of string
		for (unsigned j = 0; j < ReplacementName.size(); j++) {
			cout << "DEBUG: Starting from Replacements of: " << OriginalLines[i] << " to " << ReplacementCode[j] << endl;

			int check = isEqual(OriginalLines[i], ReplacementCode[j]);
			
		}
	}



	return "DONE!";
}

string Lower(string a)
{
	std::transform(a.begin(), a.end(), a.begin(), ::tolower);
	return a;
}
