/* 
 * File: IterativeBinarySearch.cpp
 * Purpose: Perform a binary search on an array of integers.
 * Author: Ayush Morbar
 * Date: March 5, 2024
 */

#include <iostream>
using namespace std;

int main(){
    // Initialize variables
    int mid, a[10], low=0, high=9, item;
    bool found = false; // flag to track if item is found

    // Prompt user to enter 10 elements in ascending order
    cout<<"Enter 10 elements in ascending order: ";
    for(int i=0; i<10; i++)
        cin>>a[i];

    // Prompt user to enter the element to be searched
    cout<<"Enter the element to be searched: ";
    cin>>item;

    // Perform binary search
    while(low<=high){
        mid = (low+high)/2;
        if(a[mid] == item){
            // If item is found, print its position and set found flag to true
            cout<<item<<" found at position "<<mid+1;
            found = true;
            break;
        }
        else if(a[mid] < item)
            low = mid+1;
        else
            high = mid-1;
    }

    // If item is not found, print a message
    if (!found)
        cout << "Item not found in the array." << endl;

    return 0;
}