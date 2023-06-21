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
			count2 += 1;
		}
		istringstream line3(lines2);
		for (int i = size; i < count2; i++) {
			line3 >> values3;
			array[i] = stoi(values3);
		}
		size += count2 - size;
	}
	inFile2.close();

	

	printValues(array, count2);
	//addValue(array, 500, count2);
	//printValues(array, count2);
	//resetValue(array, 3, count2);
	//printValues(array, count2);
}
