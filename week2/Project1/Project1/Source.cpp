// Sangyun Lee
// I resued the code from previous assignment (hw1)
// I refered the stoogesort algorithm from https://www.geeksforgeeks.org/cpp-program-for-stooge-sort/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void badsort(std::vector<int>& arr, int beg, int n, double checeker)
{
    int subSize = n - beg + 1;
    int m=0;
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
        //if (checeker >= 0.55 && checeker <= 0.67) {
        //    double t = subSize * checeker;
        //    m = ceil(t);
        //}
        //else if (checeker > 0.71 && checeker <= 0.99) {
        //    double t = subSize * checeker;
        //    m = floor(t);
        //}
        double t = subSize * checeker;
        if (t <= m) {
            m = ceil(t);
        }
        else if (t >= m) {
            m = floor(t);
        }
        else {
            m = ceil(t);
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

    int input;
    double numer, denom, result;
    std::vector<std::vector<int> > myNumber;

    std::cout << "Please enter the alpha value" << std::endl;
    std::cout << "Please enter the numerator of alpha value" << std::endl;
    std::cin >> numer;
    std::cout << "Please enter the denominator of alpha value" << std::endl;
    std::cin >> denom;
    std::cout << "Your alpha value is" << numer << "/" << denom << std::endl;
    result = numer / denom;
    //std::cout << result;

    std::ifstream numfile("data.txt");
    std::string line;

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
        badsort(myNumber[i], 0, myNumber[i].size() - 1, result);
    }

    for (int i = 0; i < myNumber.size(); i++)
    {
        for (int j = 0; j < myNumber[i].size(); j++)
        {
            std::cout << myNumber[i][j] << " ";
        }
        std::cout << std::endl;
     }

    //std::ofstream sortedfile;
    //sortedfile.open("bad.out");
    //for (int i = 0; i < myNumber.size(); i++)
    //{
    //    for (int j = 0; j < myNumber[i].size(); j++)
    //    {
    //        sortedfile << myNumber[i][j] << " ";
    //    }
    //    sortedfile << std::endl;
    //}
    //sortedfile.close();

    return 0;
}
