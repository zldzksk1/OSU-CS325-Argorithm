/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

void stoogesort(int arr[], int l, int h)
{
    int subsize = h + 1;
    // If first element is smaller than last, 
    // swap them 
    if (subsize==2 && arr[l] > arr[h])
        swap(arr[l], arr[h]);

    // If there are more than 2 elements in 
    // the array 
    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;

        // Recursively sort first 2/3 elements 
        stoogesort(arr, l, h - t);

        // Recursively sort last 2/3 elements 
        stoogesort(arr, l + t, h);

        // Recursively sort first 2/3 elements 
        // again to confirm 
        stoogesort(arr, l, h - t);
    }
}

int main()
{
    int arr[] = { 2, 4, 5, 3, 1, 6, 8, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calling Stooge Sort function to sort 
    // the array 
    stoogesort(arr, 0, n - 1);

    // Display the sorted array 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
