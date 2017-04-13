#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string.h>



class Atomic {
	//Files
	std::string File_OriginalLine = "N/A";
	std::string File_Replacment = "N/A";
	

	//Arrays of string(The sentence to be changed)
	std::vector<std::string> OriginalLines;

	//Replacement slots
	std::vector<std::string>ReplacementName;
	std::vector<std::string>ReplacementCode;
	std::vector<std::string>ReplacementTie;

	//Completed Lines
	std::vector<std::string> ChangedLines;


	size_t Replacement_Count;

	int Original_Count;

	public:


		int LoadFiles();
		void SetFileName(std::string a, std::string b);
		void ListFileName();
		void ListFileEntry();
		int isEqual(std::string a, std::string b);

		std::string Run();


};