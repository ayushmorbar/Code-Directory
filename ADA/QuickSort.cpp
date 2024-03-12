/* 
 * File: QuickSort.cpp
 * Purpose: Perform a quick sort on an array of integers.
 * Author: Ayush Morbar
 * Date and Time: 14:58 IST March 12, 2024
 */

#include <iostream>

// Avoid using namespace std globally
// It can lead to name clashes in larger projects

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// This function takes last element as pivot, places
// the pivot element at its correct position in sorted
// array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot
int partition (int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now
        // at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Enter 10 elements: ";
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}