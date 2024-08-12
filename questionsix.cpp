#include<iostream>
using namespace std;

int main() {
    // Step 1: Input the type of array
    string type;
    cout << "Enter type of array (int, char, float, etc.): ";
    cin >> type;

    // Step 2: Define the size of each type
    int typeSize;
    if (type == "int") typeSize = sizeof(int);
    else if (type == "char") typeSize = sizeof(char);
    else if (type == "float") typeSize = sizeof(float);
    else {
        cout << "Unsupported type!" << endl;
        return 1;
    }

    // Step 3: Input the size of the array (rows, columns, depth)
    int rows, columns, depth;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << "Enter the number of depth: ";
    cin >> depth;

    // Step 4: Input the memory arrangement (ROW major or COLUMN major)
    string arrangement;
    cout << "Enter memory arrangement (ROW/COLUMN): ";
    cin >> arrangement;

    // Step 5: Input the base address of the array
    int baseAddress;
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    // Step 6: Input the indices of the element (i, j, k)
    int i, j, k;
    cout << "Enter the index of the element (i j k): ";
    cin >> i >> j >> k;

    // Step 7: Calculate the address based on the arrangement
    int address;
    if (arrangement == "ROW") {
        address = baseAddress + ((i * columns * depth) + (j * depth) + k) * typeSize;
    } else if (arrangement == "COLUMN") {
        address = baseAddress + ((k * rows * columns) + (j * rows) + i) * typeSize;
    } else {
        cout << "Invalid memory arrangement!" << endl;
        return 1;
    }

    // Output the computed address
    cout << "The address of the element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;

    return 0;
}