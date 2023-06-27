#pragma once
#include <iostream>
using namespace std;

char Display_Menu(); //displays options for user interaction

void printValues(int array[], int arraySize); //prints array values

void searchValue(int array[], int value, int arraySize); //searches array for value

void changeValue(int array[], int value, int index, int arraySize); //changes value at index specified

void resetValue(int* &array, int index, int& arraySize); //modifies array size to change delete value or edits existing value to zero

void addValue(int* &array, int value, int &arraySize); //modifies array size to add value
