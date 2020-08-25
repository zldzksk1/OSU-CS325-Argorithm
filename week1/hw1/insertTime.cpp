// Sangyun Lee
// I referred the code fromhttps://www.geeksforgeeks.org/insertion-sort/ for this homework

#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <chrono>
using namespace std::chrono;

std::vector<int> insertionSort(std::vector<int> inputV)
{
	int i, j, key;
	for (int i = 1; i < inputV.size(); i++)
	{
		key = inputV[i];
		j = i - 1;
		while (j >= 0 && inputV[j] < key)
		{
			inputV[j + 1] = inputV[j];
			j--;
		}
		inputV[j + 1] = key;
	}
	return inputV;
}


int main()
{
	std::srand(time(NULL));
	std::vector<std::vector<int> >myNumber;
	int size = 7;
	int n = 600;

	for (int i = 0; i < size; i++)
	{
		std::vector<int> temp;
		for (int j = 0; j < n; j++) {
			int num = rand() % n;
			temp.push_back(num);
		}
		myNumber.push_back(temp);
		n = n * 2;
	}


	for (int i = 0; i < myNumber.size(); i++)
	{
		auto start = high_resolution_clock::now();
		myNumber[i] = insertionSort(myNumber[i]);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "Size of vector array: " << myNumber[i].size() << std::endl;
		std::cout << "Execution time: " << duration.count() << " ms" << std::endl << std::endl;
	}
	return 0;

}
