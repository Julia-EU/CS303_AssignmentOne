#include "Functions.h"
#include <vector>


void printValues(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void searchValue(int array[], int value, int arraySize) {
    char exists = 'n';
    int i;
    vector<int> index;
    for (i = 0; i < arraySize; ++i) {
        if (array[i] == value) {
            index.push_back(i);
            exists = 'y';
        }
    }

    if (exists != 'n') {
        cout << "The number you entered is at the following index(es): " << endl;
        for (i = 0; i < index.size(); i++) {
            cout << index[i] << " ";
        }
    }

    else {
        cout << "The number you entered does not exist at any index." << endl;
    }
  
}


void changeValue(int array[], int value, int index, int arraySize) {

    int temp_val;

    if (index < 0 || index >= arraySize) {
        throw invalid_argument("The index number you entered is out of range");
    }

    else {
        temp_val = array[index];
        array[index] = value;
    }

    cout << "The old value at this index was " << temp_val << endl;
    cout << "The new value at this index is now" << value << endl;

}

void addValue(int* &array, int value, int &arraySize) {

    arraySize = arraySize + 1;
    int* resized = new int[arraySize];
    for (int i = 0; i < arraySize - 1; i++) {
        resized[i] = array[i];
    }
    resized[arraySize - 1] = value;
    
    delete[] array;
    array = resized;
}

void resetValue(int* &array, int index, int &arraySize) {

    if (index < 0 || index >= arraySize) {
        throw invalid_argument("The index number you entered is out of range");
    }

    else {

        string choice;
        cout << "Would you like to change value to 0 or delete value? " << endl;
        cout << "A - change to 0\nB- delete value" << endl;
        cin >> choice;
        while (choice.size() > 1 || toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B') {
            cout << "Please enter a valid choice of A or B" << endl;
        }

        if (toupper(choice[0]) == 'A') {
            array[index] = 0;
            cout << "The value at the index entered has been changed to 0" << endl;
        }

        else {
            int* newArr = new int[arraySize - 1];
            if (index == arraySize - 1) {
                for (int i = 0; i < index; i++) {
                    newArr[i] = array[i];
                }
            }
            else{
                for (int i = 0; i < index; i++) {
                    newArr[i] = array[i];
                }
                for (int i = index; i < arraySize - 1; i++) {
                    newArr[i] = array[i + 1];
                }
            }

            arraySize -= 1;
            delete[] array;
            array = newArr;
        }
    }
}