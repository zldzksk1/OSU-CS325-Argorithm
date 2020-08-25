////sangyun lee
////i refered the sttogesort from 
//
//
//#include <stdio.h>
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//void badsort(int arr[], int l, int h)
// {
//    if (l >= h)
//        return;
//
//    // if first element is smaller than last, 
//    // swap them 
//    if (arr[l] > arr[h])
//        swap(arr[l], arr[h]);
//
//    // if there are more than 3 elements in 
//    // the array 
//    if (h - l + 1 >= 2) {
//        int t = (h - l + 1) / 3;
//
//        // recursively sort first 2/3 elements 
//        badsort(arr, l, h - t);
//
//        // recursively sort last 2/3 elements 
//        badsort(arr, l + t, h);
//
//        // recursively sort first 2/3 elements 
//        // again to confirm 
//        badsort(arr, l, h - t);
//    }
//}
//
//int main()
//{
//    int arr[] = { 2, 4, 5, 3, 1, 6, 8, 7};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // calling stooge sort function to sort 
//    // the array 
//    badsort(arr, 0, n - 1);
//
//    // display the sorted array 
//    for (int i = 0; i < n; i++)
//        cout << arr[i] << " ";
//
//    return 0;
//}