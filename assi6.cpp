#include <iostream>
using namespace std;

template<typename T>
void computeAddress3D(int rows, int cols, int depth, int baseAddress, int i, int j, int k, bool isRowMajor) {
    int elementSize = sizeof(T);
    int address;
    if (isRowMajor)
        address = baseAddress + (((i * cols * depth) + (j * depth) + k) * elementSize);
    else
        address = baseAddress + (((k * rows * cols) + (j * rows) + i) * elementSize);

    cout << "Address of element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;
}

int main() {
    int rows = 3, cols = 3, depth = 3, baseAddress = 1000;
    int i = 1, j = 2, k = 1;
    bool isRowMajor = true; // set to false for column major

    computeAddress3D<int>(rows, cols, depth, baseAddress, i, j, k, isRowMajor);

    return 0;
}
