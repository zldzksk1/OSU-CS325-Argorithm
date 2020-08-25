//Sangyun Lee
// For the Q4 of hw3, I adopted the code from https://www.geeksforgeeks.org/printing-items-01-knapsack/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//return the maximum value of two input
int max(int a, int b) {
    return (a > b) ? a : b;
}

void printAllsubset(std::vector<int>subset, std::vector<int>wgt, std::vector<int>val, int cap)
{
    int total_weight = 0;
    for (int i = 0; i < subset.size(); i++)
    {
        total_weight = total_weight + wgt[subset[i]-1]; //get the total weight of subset;
    }

    if (total_weight > cap) //if the total weight is bigger than given capacity
    {
        //do nothing
    }
    else //if it is less of equal to cap, print subset
    {
        std::cout << "subset" << std::endl;
        for (int i = 0; i < subset.size(); i++)
        {
            std::cout << "item " << subset[i] << "{" << wgt[subset[i] - 1] << ":" << val[subset[i] - 1] << "}" << std::endl;    
        }
    }
}

void knapsack_print(std::vector<int> wgt, std::vector<int> val, int cap, int size) {

    //set up table

    int i, w;
    int** table = new int* [size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        table[i] = new int[cap + 1];
    }

    //fill the table
    for (i = 0; i <= size; i++)
    {
        for (w = 0; w <= cap; w++)
        {
            if (i == 0 || w == 0) {
                table[i][w] = 0;
            }
            else if (wgt[i - 1] <= w)
            {
                table[i][w] = max(val[i - 1] + table[i - 1][w - wgt[i - 1]], table[i - 1][w]);
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    //get the optimal value from the table 
    int optVal = table[size][cap];
    w = cap;

    int otherSub = 1;   //assum we have one optimal value in this table
    std::cout << "Optimal Value: " << optVal << std::endl;

    for (i = size; i > 0 && optVal > 0; i--)
    {
        if (optVal == table[i - 1][w]) // check how many the same optimal values are in the table
        {
            otherSub++; 
        }
    }

    //set 2d array to store the all possible subset
    std::vector<std::vector<int>>subSetGroup;

    //Check the table from bottom up 
    while (otherSub != 0) {
        w = cap;
        optVal = table[size][cap];
        std::vector<int> subSet;

        for (i = size; i > 0 && optVal > 0; i--)
        {
            if (optVal == table[i - 1][w]) // if we found the same optimal value continue to next row
            {
                continue;
            }
            else
            {
                table[i][w] = 0;    //marking to show this cell was processed already  
                w = w - wgt[i - 1];
                optVal = optVal - val[i - 1];
                subSet.push_back(i);
            }
        }
        otherSub--;
        subSetGroup.push_back(subSet); //save the subset candidate
    }

    for (int i = 0; i < subSetGroup.size() ; i++)
    {
        printAllsubset(subSetGroup[i],wgt,val,cap); //print the subset it is meet the constraints
    }


    //free memory
    for (int i = 0; i < size + 1; i++)
    {
        delete[] table[i];
    }
    delete[] table;

    subSetGroup = std::vector<std::vector<int>>();
}

int main()
{

    int capacity;
    std::vector<int> weight;
    std::vector<int> value;

    std::cout << "Please enter the value for Capacity [Natural number only] " << std::endl;
    std::cin >> capacity;

    std::ifstream numfile("data2.txt");
    std::string line;

    if (numfile.is_open())
    {
        while (std::getline(numfile, line))
        {
            bool marker = 0;
            std::istringstream iss(line);
            int number;
            while (iss >> number)
            {
                if (marker == 0)
                {
                    weight.push_back(number);
                    marker = 1;
                }
                else if (marker == 1) {
                    value.push_back(number);
                    marker = 0;
                }
            }
        }
    }
    numfile.close();


    knapsack_print(weight, value, capacity, weight.size());

    //free memory
    weight = std::vector<int>();
    value = std::vector<int>();

    return 0;
}
