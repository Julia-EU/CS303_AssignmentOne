// CS303_AssignmentOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{

	ifstream inFile;
	inFile.open("TestFile.txt");
	if (!inFile.is_open()) {
		cout << "Error opening file\n";
		return 1;
	}
	//First instance of file reading is to count lines & values to determine initial array size
	int count = 0;
	string lines;
	string values;
	while (!inFile.eof()) {
		getline(inFile, lines);
		istringstream line(lines);
		while (line >> values) {
			count += 1;
		}
	}
	inFile.close();

	int* array = new int[count]; //initializing dynamic array based on number of values in file
	//Second instance of file reading is to initialize array values from file
	ifstream inFile2;
	inFile2.open("TestFile.txt");
	if (!inFile2.is_open()) {
		cout << "Error opening file\n";
		return 1;
	}
	int count2 = 0;
	string lines2;
	string values2;
	string values3;
	int size = 0;
	while (!inFile2.eof()) {
		getline(inFile2, lines2);
		istringstream line2(lines2);
		while (line2 >> values2) {
			count2 += 1; //increments by total number of values per line till end of file. Final value is number of values in array
		}
		istringstream line3(lines2);
		for (int i = size; i < count2; i++) {
			line3 >> values3;
			array[i] = stoi(values3);
		}
		size += count2 - size; //increments by count minus previous size to match starting index value for each line
	}
	inFile2.close();

	cout << "The text file contains the following values:\n";
	printValues(array, count2);
	cout << endl;

	char inUse = 'Y'; //Variable character condition for while loop
	while (inUse == 'Y') { 

		char userChoice = Display_Menu();

		try {

			if (userChoice == 'A') {
				string value;
				cout << "Please type an integer value to search for: ";
				cin >> value;
				int avalue = stoi(value); //user input is converted to integer. if not compatible, exception is caught
				searchValue(array, avalue, count2);
				cout << endl;
				cout << endl;;
			}

			else if (userChoice == 'B') {
				string index;
				string value;
				cout << "Please enter the index number of the value you wish to change: ";
				cin >> index;
				int bindex = stoi(index);
				cout << "\nPlease enter the value you wish to change it to: ";
				cin >> value;
				int bvalue = stoi(value);
				changeValue(array, bvalue, bindex, count2);
				cout << endl;
				cout << "New array values are:\n";
				printValues(array, count2);
				cout << endl;
			}

			else if (userChoice == 'C') {
				string value;
				cout << "Please type an integer value to add to this array: ";
				cin >> value;
				int cvalue = stoi(value);
				addValue(array, cvalue, count2);
				cout << endl;
				cout << "New array values are:\n";
				printValues(array, count2);
				cout << endl;
			}

			else if (userChoice == 'D') {
				string index;
				cout << "Please enter the index number of the value you wish to change: ";
				cin >> index;
				int dindex = stoi(index);
				resetValue(array, dindex, count2);
				cout << endl;
				cout << "New array values are:\n";
				printValues(array, count2);
				cout << endl;
			}

			else {
				inUse = 'N'; 
			}

		}

		catch (invalid_argument& e) {
			cout << e.what() << endl;
			cout << endl;
		}

		catch (...) {
			cout << "Invalid user input. Please enter a valid integer when prompted." << endl;
			cout << endl;
		}
	}
	
}
