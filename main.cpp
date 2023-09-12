#include "functions.h"

int main() {
  //open file
    ifstream file("input.txt");
    if (!file) {
        cerr << "Could not open file";
        system("pause");
        return 1;
    }

	const int rows = 10, columns = 10;
    int array[rows][columns];

	//initialize array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            file >> array[i][j];
        }
    }

	cout << "Contents of Array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
	
	int choice;
	bool continueMenu = true;
	while (continueMenu){
		cout << "\n(1) Find a value" << endl << "(2) Modify a value" << endl << "(3) Add a value" << endl << "(4) Replace with 0 or Remove" << endl << "(5) Exit" << endl << "\nChoose an option: ";
		cin >> choice;

		switch (choice){
      //check if num is in array
			case 1:
			    int findNum;
			    cout << "Enter a value to find: ";
			    cin >> findNum;
					int rowIndex, columnIndex;
			    if (findNumber(array, rows, columns, findNum, rowIndex, columnIndex)) {
			        cout << "Value at the index: [" << rowIndex <<"] ["<< columnIndex <<"]" << endl;
			    } 
				else {
			        cout << "Value not found" << endl;
			    }
				break;
      
      //user inputs			
			case 2:
				int rIndex, cIndex, newValue, oldValue;
				try{
					cout << "Enter index to modify \nRow: ";
					cin >> rIndex;
					if (rIndex < 0 || rIndex >= rows) {
				        throw runtime_error("Invalid row index.");
				    }
					cout << "Column: ";
					cin >> cIndex;
					if (cIndex < 0 || cIndex >= columns) {
						throw runtime_error("Invalid column index.");
					}
					cout << "Modify index with value: ";
				 	cin >> newValue;
					
					//modify value 
					if (changeVal(array, rows, columns, rIndex, cIndex, newValue, oldValue)){
						cout << "Old Value is " << oldValue << endl;
						cout << "New Value is " << newValue << endl;
					}
				}
				catch (const runtime_error &e){
					cerr << "Error: " << e.what() << endl;
				}
				break;
	
			case 3:
				try{
					int newInt;
					cout << "Enter an integer to add to the array: ";
					cin >> newInt;
					
					//new int in array for new input
					if (intToArray(array, rows, columns, newInt)){
						cout << "Array with new integer: " << endl
							 << "Array Contents:" << endl;
						
						 //printing the array with the new integer that has been added
				        printArray(array, rows, columns);
					}
				}
				catch (const exception &e) {
				cerr << "Error: " << e.what() << endl;
				}
				break;
      
			case 4:
				int rowIndexToRR, columnIndexToRR, action;
				cout << "Enter index to remove \nRow: ";
				cin >> rowIndexToRR;
				cout << "Column: ";
				cin >> columnIndexToRR;
				cout << "(1) replace or (2) remove a value: ";
				cin >> action;
	       //print new array
				if (removeReplace(array, rows, columns, rowIndexToRR, columnIndexToRR, action)){
					cout << "Array Contents:" << endl;
			        printArray(array, rows, columns);
				}
				break;
			case 5:
	                continueMenu = false;
	                break;
	
			default:
				cout << "Invalid, enter a valid option" << endl;
		}
	}
    return 0;
}