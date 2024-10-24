#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Bubble Sort - Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort - Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[minIdx], arr[i]);
            swaps++;
        }
    }
    cout << "Selection Sort - Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    // Bubble Sort
    bubbleSort(arr1, n);
    cout << "Sorted array (Bubble Sort): ";
    displayArray(arr1, n);

    // Insertion Sort
    insertionSort(arr2, n);
    cout << "Sorted array (Insertion Sort): ";
    displayArray(arr2, n);

    // Selection Sort
    selectionSort(arr3, n);
    cout << "Sorted array (Selection Sort): ";
    displayArray(arr3, n);

    return 0;
}
