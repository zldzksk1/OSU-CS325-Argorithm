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

    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }




    ////get the optimal value from the table and print
    int optVal = table[size][cap];
    w = cap;

    int otherSub = 0;
    std::cout << "Optimal Value: " << optVal << std::endl; 

    for (i = size; i > 0 && optVal > 0; i--)
    {
        if (optVal == table[i - 1][w]) // if the table[i-1][w] == optimal value, then it is not included
        {
            otherSub++;
        }
    }
    otherSub++;
    
    while (otherSub != 0) {
        optVal = table[size][cap];
        w = cap;
        std::cout << "-Subset-" << std::endl;
        for (i = size; i > 0 && optVal > 0; i--)
        {
            if (optVal == table[i - 1][w]) // if the table[i-1][w] == optimal value, then it is not included
            {
                int optVal_check = table[i-1][w - wgt[i - 1]]+val[i-1]; //check whether the last element used or not
                if (optVal_check < optVal)  //if the last element is not used, then
                {
                    //otherSub--; //this is not a subset, so decrease the loop time.
                    continue;
                }
                else
                {
                    continue;
                }
                 
            }
            else
            {
                table[i][w] = 0;
                w = w - wgt[i - 1];
                optVal = optVal - val[i - 1];
                std::cout << "item: " << i << " {weight: " << wgt[i - 1] << " value: " << val[i - 1] << "}" << std::endl;
            }
        }
        otherSub--;
        std::cout << std::endl;
    }

    for (int i = 0; i < size + 1; i++)
    {
        delete[] table[i];
    }

 //   std::cout << "additional sub: " <<otherSub;
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
                else if(marker == 1){
                    value.push_back(number);
                    marker = 0;
                }
            }
        }
    }
    numfile.close();


   knapsack_print(weight, value, capacity, weight.size());

  /*  for (int i = 0; i < weight.size(); i++)
    {
        std::cout << "set" << i + 1 << "{" << weight[i] << " : " << value[i] << "}"<<std::endl;
    }*/

  
    return 0;
}
