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
						if (Replacement_Count < tmp.size())Replacement_Count = tmp.size();}
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
		//Get string for replacements and assign
		Replace.assign((istreambuf_iterator<char>(FinRep)), (istreambuf_iterator<char>()));
		OriginalLines = Replace;
		
		}

	FinOr.close();
	FinRep.close();
	ListFileName();
	ListFileEntry();


	return 0;
}

void Atomic::SetFileName(string orig, string repl)
{
	File_OriginalLine = orig;
	File_Replacment = repl;
}

void Atomic::ListFileName()
{
	cout << "File Names are\n Origin: " << File_OriginalLine << "\n Replacement: " << File_Replacment << endl;

}

void Atomic::ListFileEntry()
{
	cout << "Files entry is as follows\n Origin Entries: \n";
	int ii = 0;
	for (size_t i = 0 ; i < ReplacementName.size(); i++) {
		
		cout <<setw(4) << left <<  ii++ <<setw(20) <<  ReplacementName[i] << " | " <<setw(5) << ReplacementCode[i] << " | " << setw(5) << ReplacementTie[i] << endl;
	}

	cout << "Additionally collected weight values and letter substitutes to match!\n";
}

std::string Atomic::Run()
{
	//Begin String replacement using class OO.

	//Mod is designed around what is replacing the chars. Meaning, that it will advance upon the string by the amount replaced. 
	//ex: if no match for the (min 2) -> advance the string by 1 space. If match found for (3 chars) -> advance the string by 3 chars or end of string.
	int mod = 0;
	//Counter for replacment matches of string
	int matches = 0;

	for (int i = 0; i < OriginalLines.size(); i + mod) {
		
		cout << "Inspection of chars: " << OriginalLines[i] << OriginalLines[i + 1] << endl;


		//replacement and measure length of string
		for (unsigned j = 0; j < ReplacementName.size(); j++) {
			cout << "DEBUG: Starting from Replacments of: " << ReplacementCode[j] << endl;


			//string check
			string t = OriginalLines.substr(i, i + 2);
			
			
			cout << "DEBUG: Compared: " << t << "|  " << ReplacementCode[j] << endl;
			if (t == ReplacementCode[j]) {
				
				matches++;
			}
				
		}
	


		//Set Mod
		//Check end of string 
		}
	


	return "DONE!";
}
