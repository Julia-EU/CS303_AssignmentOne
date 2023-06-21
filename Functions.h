#pragma once
#include <iostream>
using namespace std;

void printValues(int array[], int arraySize);

void searchValue(int array[], int value, int arraySize);

void changeValue(int array[], int value, int index, int arraySize);

void resetValue(int* &array, int index, int& arraySize);

void addValue(int* &array, int value, int &arraySize);