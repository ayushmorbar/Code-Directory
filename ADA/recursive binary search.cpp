#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearchRecursive(int arr[], int left, int right, int x) {
    // Check base case
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, left, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearchRecursive(arr, mid + 1, right, x);
    }

    // We reach here when element is not present in array
    return -1;
}

int main() {
    int n, x;

    // Get the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Declare the array
    int arr[n];

    // Get the elements of the array
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the number to search for
    cout << "Enter the number to search for: ";
    cin >> x;

    // Perform the binary search
    int result = binarySearchRecursive(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}