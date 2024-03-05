/* 
 * File: RecursiveMergeSort.cpp
 * Purpose: Perform a merge sort on an array of integers using recursion.
 * Author: Ayush Morbar
 * Date: 15:41 IST March 5, 2024
 */

#include <iostream>
using namespace std;

// Function prototypes
void mergeSort(int[], int, int, int);
void partition(int[], int, int);

int main(){
    int list[50];
    int i, size;

    // Prompt user to enter total number of elements
    cout<<"Enter total number of elements: ";
    cin>>size;

    // Prompt user to enter the elements
    cout<<"Enter the elements: ";
    for(i=0; i<size; i++)
        cin>>list[i];

    // Perform merge sort
    partition(list, 0, size-1);

    // Print sorted elements
    cout<<"After merge sorting: ";
    for(i=0; i<size; i++)
        cout<<list[i]<<" ";
    cout<<endl;

    return 0;
}

// Function to partition the array
void partition(int list[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        partition(list, low, mid); // Recursively sort first half
        partition(list, mid+1, high); // Recursively sort second half
        mergeSort(list, low, mid, high); // Merge the two halves
    }
}

// Function to merge two halves
void mergeSort(int list[], int low, int mid, int high){
    int i, mi, k, lo, temp[50];
    lo = low;
    i = low;
    mi = mid+1;

    // Merge two halves in sorted order
    while((lo<=mid) && (mi<=high)){
        if(list[lo]<=list[mi]){
            temp[i] = list[lo];
            lo++;
        }
        else{
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }

    // Copy remaining elements of first half
    if(lo>mid){
        for(k=mi; k<=high; k++){
            temp[i] = list[k];
            i++;
        }
    }
    // Copy remaining elements of second half
    else{
        for(k=lo; k<=mid; k++){
            temp[i] = list[k];
            i++;
        }
    }

    // Copy back elements from temporary array to original array
    for(k=low; k<=high; k++)
        list[k] = temp[k];
}