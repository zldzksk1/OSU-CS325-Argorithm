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

// build knapsack table and display the optimal subset
void knapsack_print(std::vector<int> wgt, std::vector<int> val, int cap, int size) {

    //set up table
    int i, w;
    int** table = new int* [size+1];
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
                table[i][w] = max(val[i - 1] + table[i-1][w - wgt[i-1]], table[i-1][w]);
            }
            else 
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }

    //get the optimal value from the table and print
    int optVal = table[size][cap];
    std::cout << "Optimal Value: " << optVal << std::endl;
    std::cout << "-Subset-" << std::endl;
    w = cap;

    //
    for (i = size; i > 0 && optVal > 0; i--)
    {
        if (optVal == table[i - 1][w]) // if the table[i-1][w] == optimal value, then it is not included
            continue;
        else {
            std::cout << "item: " << i << " {weight: " << wgt[i - 1] << " value: "<< val[i-1] << "}" << std::endl;

            optVal = optVal - val[i - 1];
            w = w - wgt[i - 1];
        }
    }

    //free memory
    for (int i = 0; i < size + 1; i++)
    {
        delete[] table[i];
    }
    delete[] table;
}

int main()
{

    int capacity;
    std::vector<int> weight;
    std::vector<int> value;

    std::cout << "Please enter the value for Capacity [Natural number only] " << std::endl;
    std::cin >> capacity;

    std::ifstream numfile("data.txt");
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
                else if(marker == 1){
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
