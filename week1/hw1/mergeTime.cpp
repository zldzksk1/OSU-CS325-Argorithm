// Sangyun Lee
//I referred the code from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ for this hw

#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> 
#include <chrono>
using namespace std::chrono;

std::vector<int> merge(std::vector<int> leftV, std::vector<int> rightV)
{
	std::vector<int> mergedV;

	while (leftV.size() > 0 || rightV.size() > 0) {
		if (leftV.size() > 0 && rightV.size() > 0) {
			if (leftV.front() >= rightV.front()) {
				mergedV.push_back(leftV.front());
				leftV.erase(leftV.begin());
			}
			else {
				mergedV.push_back(rightV.front());
				rightV.erase(rightV.begin());
			}
		}
		else if (leftV.size() > 0) {
			for (int i = 0; i < leftV.size(); i++)
			{
				mergedV.push_back(leftV[i]);
			}
			break;
		}
		else if (rightV.size() > 0) {
			for (int i = 0; i < rightV.size(); i++)
			{
				mergedV.push_back(rightV[i]);
			}
			break;
		}
	}
	return mergedV;
}

std::vector<int> mergeSort(std::vector<int> inputV)
{
	int mNum = (inputV.size() + 1) / 2;
	if (inputV.size() <= 1) {
		return inputV;
	}

	std::vector<int> leftV, rightV, result;

	for (int i = 0; i < mNum; i++)
	{
		leftV.push_back(inputV[i]);
	}

	for (int i = mNum; i < (int)inputV.size(); i++)
	{
		rightV.push_back(inputV[i]);
	}

	leftV = mergeSort(leftV);
	rightV = mergeSort(rightV);
	result = merge(leftV, rightV);

	return result;
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
		myNumber[i] = mergeSort(myNumber[i]);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "Size of vector array: " << myNumber[i].size() << std::endl;
		std::cout << "Execution time: " << duration.count() << " ms" << std::endl << std::endl;
	}
	return 0;
}