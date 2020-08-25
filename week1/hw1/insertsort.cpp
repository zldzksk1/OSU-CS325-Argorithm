// Sangyun Lee
// I referred the code from https://www.geeksforgeeks.org/insertion-sort/ for this assignment

#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<vector>

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
	std::ifstream numfile("data.txt");
	std::string line;
	std::vector<std::vector<int> > myNumber;

	if (numfile.is_open())
	{

		while (std::getline(numfile, line))
		{
			std::vector<int> temp;
			std::istringstream iss(line);
			int number;
			int start = 0;
			while (iss >> number)
			{
				if (start == 0)
				{
					start = 1;
					//since it is vector, it doesn't need the first number which is size.
				}
				else {
					temp.push_back(number);
				}
			}
			myNumber.push_back(temp);
		}
	}
	numfile.close();


	for (int i = 0; i < myNumber.size(); i++)
	{
		myNumber[i] = insertionSort(myNumber[i]);
	}

	std::ofstream sortedfile;
	sortedfile.open("insert.out");
	for (int i = 0; i < myNumber.size(); i++)
	{
		for (int j = 0; j < myNumber[i].size(); j++)
		{
			sortedfile << myNumber[i][j] << " ";
//			std::cout << myNumber[i][j] << " ";
		}
		sortedfile << std::endl;
//		std::cout << std::endl;
	}
	sortedfile.close();
}
