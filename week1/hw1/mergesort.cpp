//Sangyun Lee
// I referred the code from links below for homework
//https://stackoverflow.com/questions/35611589/2d-vector-of-unknown-size
//https://www.bogotobogo.com/Algorithms/mergesort.php
//https://stackoverflow.com/questions/17807634/stringstream-duplicates-last-word

#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<vector>

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
					//since it is vector, it doesn't need to have the first number which is size.
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
		myNumber[i] = mergeSort(myNumber[i]);
	}

	std::ofstream sortedfile;
	sortedfile.open("merge.out");
	for (int i = 0; i < myNumber.size(); i++)
	{
		for (int j = 0; j < myNumber[i].size(); j++)
		{
			sortedfile << myNumber[i][j] << " ";
		}
		sortedfile << std::endl;
	}
	sortedfile.close();
}
