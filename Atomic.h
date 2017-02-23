#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>



class Atomic {
	//Files
	std::string File_OriginalLine = "N/A";
	std::string File_Replacment = "N/A";
	

	//Arrays of string
	std::string OriginalLines;
	//Replacement slots
	std::vector<std::string>Replacement;
	//Completed Lines
	std::string ChangedLines;

	int Replacement_Count;
	int Original_Count;

	public:


		int LoadFiles();
		void ListFileName();
		void ListFileEntry();


		std::string Run();


};