#include <iostream>
using namespace std;

int main() {
    char type; // type of array (e.g. 'i' for int, 'c' for char, 'f' for float)
    int rows, cols; // size of array (number of rows and columns)
    char arrangement; // memory arrangement (either 'R' for row major or 'C' for column major)
    int base_address; // base address of the array
    int i, j; // index of the element whose address is to be calculated

    cout << "Enter the type of array (e.g. 'i' for int, 'c' for char, 'f' for float): ";
    cin >> type;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the memory arrangement (either 'R' for row major or 'C' for column major): ";
    cin >> arrangement;

    cout << "Enter the base address of the array: ";
    cin >> base_address;

    cout << "Enter the index of the element (i and j): ";
    cin >> i >> j;

    int size; // size of each element in bytes
    if (type == 'i') {
        size = sizeof(int);
    } else if (type == 'c') {
        size = sizeof(char);
    } else if (type == 'f') {
        size = sizeof(float);
    } else {
        cout << "Invalid type" << endl;
        return 1;
    }

    int address; // address of the element
    if (arrangement == 'R' || arrangement == 'r') {
        address = base_address + (i * cols + j) * size;
    } else if (arrangement == 'C' || arrangement == 'c') {
        address = base_address + (j * rows + i) * size;
    } else {
        cout << "Invalid arrangement" << endl;
        return 1;
    }

    cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;

    return 0;
}