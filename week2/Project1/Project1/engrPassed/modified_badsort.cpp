// Sangyun Lee
// I refered the stoogesort algorithm from https://www.geeksforgeeks.org/cpp-program-for-stooge-sort/

#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>   
#include <time.h>   
#include <chrono>
#include <algorithm>

using namespace std::chrono;

void badsort(int arr[], int beg, int n, double checeker)
{
    int subSize = n - beg + 1;
    int m;
    if (beg == n)
        return;

    // If first element is smaller than last, 
    // swap them 
    if ((subSize == 2) && (arr[beg] > arr[n]))
    {
        std::swap(arr[beg], arr[n]);
    }

    // If there are more than 2 elements in 
    // the array 
    else if (subSize > 2) {
        if (checeker >= 0.55 && checeker <= 0.67) {
            double t = subSize * checeker;
            m = ceil(t);
        }
        else if (checeker > 0.71 && checeker <= 0.99) {
            double t = subSize * checeker;
            m = floor(t);
        }
        else {
            std::cout << "with the given alpha value, this program would not be sorted" << std::endl;
        }

        // Recursively sort first 2/3 elements 
        badsort(arr, beg, beg + m - 1, checeker);

        // Recursively sort last 2/3 elements 
        badsort(arr, n + 1 - m, n, checeker);

        // Recursively sort first 2/3 elements 
        // again to confirm 
        badsort(arr, beg, beg + m - 1, checeker);
    }
}

int main()
{
    srand(time(NULL));

    double twoThree = 2.0 / 3.0;
    double threeFour = 3.0 / 4.0;


    //Sort and get time duration with alpha value of 2/3
    int count = 7;
    int arrSize = 10;
    std::cout << "alpha value: 2/3" << std::endl;

    while (count >= 1) {

        //repeatedly define single dynamic array
        int* arrSort = new int[arrSize]; 
        for (int i = 0; i < arrSize; i++)
        {
            arrSort[i] = rand() % arrSize;                         
        }

        //sort and measure the execution time
        auto start = high_resolution_clock::now();                 //set time start
        badsort(arrSort, 0, arrSize - 1, twoThree);
        auto stop = high_resolution_clock::now();                  //set time stop
        auto duration = duration_cast<microseconds>(stop - start);

        //display result
        std::cout << "Array size: " << arrSize << " / time taken by function: " << duration.count() << " microseconds" << std::endl;
        arrSize = arrSize * 2;
        count--;
	delete[] arrSort;
    }

    //Sort and get time duration with alpha value of 3/4
    count = 7;
    arrSize = 10;
    std::cout << "alpha value: 3/4" << std::endl;

    while (count >= 1) {

        //repeatedly define single dynamic array
        int* arrSort = new int[arrSize];

        for (int i = 0; i < arrSize; i++)
        {
            arrSort[i] = rand() % arrSize;                           //since it doesn't need to save to file, simply use single dynamic array
        }

        //sort and measure the execution time
        auto start = high_resolution_clock::now();                   //set time start
        badsort(arrSort, 0, arrSize - 1, threeFour);
        auto stop = high_resolution_clock::now();                    //set time stop
        auto duration = duration_cast<microseconds>(stop - start);

        //display result
        std::cout << "Array size: " << arrSize << " / time taken by function: " << duration.count() << " microseconds" << std::endl;
        arrSize = arrSize * 2;
        count--;
	delete[] arrSort;
    }

    return 0;
}
