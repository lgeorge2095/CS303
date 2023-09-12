#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
using namespace std;

bool printArray(int array[][10], int rows, int columns){
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (array[i][j] != 0 || (i == rows - 1 && j == columns - 1)) {
				cout << array[i][j] << " ";
			}
		}
		cout << endl; 
	}
	return false;
}

//validate int input
int intInput() {
    int value;
    while (true) {
        cout << "Enter an integer: ";
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return value;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input, enter an integer" << endl;
        }
    }
}

//search array for the input, return true if found
bool findNumber(int array[][10], int rows, int columns, int findNum, int& rowIndex, int& columnIndex){
	int number;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < columns; ++j){
			if (array[i][j] == findNum){
				rowIndex = i;
				columnIndex = j;
				return true;
			}
		}
	}
	return false;
}

//change value to new value
bool changeVal(int array[][10], int rows, int columns, int rIndex, int cIndex, int newValue, int& oldValue){
	oldValue = array[rIndex][cIndex];
	array[rIndex][cIndex] = newValue;
	return true;   
}

bool intToArray(int array [][10], int rows, int columns, int newInt){
	
	if (array == nullptr || rows <= 0 || columns <= 0) {
        throw invalid_argument ("Invalid array/dimensions");
    }
    array[rows - 1][columns - 1] = newInt;
    return true;
}

bool removeReplace(int array[][10], int rows, int columns, int rowIndexToRR,
						int columnIndexToRR, int action){
              if (action == 1) {
                array[rowIndexToRR][columnIndexToRR] = 0;
    } 
		
	else if (action == 2) { 
		array[rowIndexToRR][columnIndexToRR] = NULL;
    }
  return true;
}

