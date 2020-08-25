
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void stoogesort(int arr[], int beg, int n)
{
     int subSize = n - beg + 1;
     if (beg == n)
         return;

    // If first element is smaller than last, 
    // swap them 
    if ((subSize == 2) && (arr[beg] > arr[n]))
    {
        swap(arr[beg], arr[n]);
    }

    // If there are more than 2 elements in 
    // the array 
    else if (subSize> 2) {
        double t = subSize * 2.0 / 3.0;
        int m = ceil(t);
        // Recursively sort first 2/3 elements 
        stoogesort(arr, beg, beg + m - 1);

        // Recursively sort last 2/3 elements 
        stoogesort(arr, n + 1 - m, n);

        // Recursively sort first 2/3 elements 
        // again to confirm 
        stoogesort(arr, beg, beg + m - 1);
    }
}

int main()
{
    int arr[] = { 8, 4, 5, 1, 6, 7, 3, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calling Stooge Sort function to sort 
    // the array 
    stoogesort(arr, 0, n-1);

    // Display the sorted array 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
