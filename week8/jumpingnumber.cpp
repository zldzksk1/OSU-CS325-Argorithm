//Sangyun Lee
//Extracredit Assignment
//I referred and adopted code from https://www.geeksforgeeks.org/print-all-jumping-numbers-smaller-than-or-equal-to-a-given-value/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


void jumpingNumber(int n, int num, std::vector<int>* vAry)
{
	std::queue<int> q;
	q.push(num);

	while (!q.empty())
	{
		int numQ = q.front();
		q.pop();
		
		if (numQ <= n)
		{
			vAry->push_back(numQ);

			int lastNum = numQ % 10;

			if (lastNum == 0)	//if the last poistion number is eqaul to 0, then + 1
			{
				int Newnum = (numQ * 10) + (lastNum + 1);
				q.push(Newnum);
			}

			else if (lastNum == 9) //if the last poistion number is eqaul to 9, then - 1 (since 9 -> 0 is not counted, only substract)
			{
				int Newnum = (numQ * 10) + (lastNum - 1);
				q.push(Newnum);
			}

			else	//else add one or subtract one 
			{
				int NewnumLeft = (numQ * 10) + (lastNum - 1);
				int NewnumRight = (numQ * 10) + (lastNum + 1);
				q.push(NewnumLeft);
				q.push(NewnumRight);
			}

		}

	}
}

int main()
{
	std::vector<int> result;	//vector to save the jumping numbers
	int inputSize;
	int i = 1;

	std::cout << "Enter the size of N" << std::endl;	//size of N from a user
	std::cin >> inputSize;

	while (i <= 9 && i <= inputSize)
	{
		jumpingNumber(inputSize, i, &result);	//check jumping number
		i++;
	}

	std::sort(result.begin(), result.end());	//sort the number

	std::cout << 0 << " ";								//start from 0;
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";			//print
	}
}