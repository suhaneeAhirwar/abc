#include <iostream>
using namespace std;

// Function to calculate the address of an element in a 2D array
template<typename T>
void computeAddress2D(int rows, int cols, int baseAddress, int i, int j, bool isRowMajor) {
    int elementSize = sizeof(T);  // Size of each element
    int address;

    if (isRowMajor) {
        // Row-major arrangement
        address = baseAddress + ((i * cols) + j) * elementSize;
    } else {
        // Column-major arrangement
        address = baseAddress + ((j * rows) + i) * elementSize;
    }

    cout << "Address of element at (" << i << ", " << j << ") is: " << address << endl;
}

int main() {
    int rows, cols, baseAddress, i, j;
    char type;
    string memoryArrangement;

    // Input array type (int, char, float, etc.)
    cout << "Enter the type of array (i for int, c for char, f for float): ";
    cin >> type;

    // Input size of array (rows and columns)
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Input base address of the array
    cout << "Enter base address of the array: ";
    cin >> baseAddress;

    // Input memory arrangement (Row-major or Column-major)
    cout << "Enter memory arrangement (row or column): ";
    cin >> memoryArrangement;
    bool isRowMajor = (memoryArrangement == "row");

    // Input the index of the element (i, j) whose address is to be calculated
    cout << "Enter the index (i, j) of the element: ";
    cin >> i >> j;

    // Call the appropriate function based on the type of the array
    switch (type) {
        case 'i':
            computeAddress2D<int>(rows, cols, baseAddress, i, j, isRowMajor);
            break;
        case 'c':
            computeAddress2D<char>(rows, cols, baseAddress, i, j, isRowMajor);
            break;
        case 'f':
            computeAddress2D<float>(rows, cols, baseAddress, i, j, isRowMajor);
            break;
        default:
            cout << "Invalid array type." << endl;
    }

    return 0;
}
