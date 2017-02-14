//Class for Atomics. Will hold parallel vectors of Atomic Name and Atomic Value. 
//Tied by array.
/*Main Menu:
	

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

Atomic(Need generic name): 
TOCHECK: Template class????

