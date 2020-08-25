//Sangyun Lee
//CS325
//I adopt and referred the code and idea from links below 
//https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/ 
//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/depthSearch.htm

#include "dfsColor.hpp"

//search the vertax number of a player
int search(std::vector<std::string> playerlist,std::string x)
{
    for (int i = 0; i < playerlist.size(); i++)
    {
        if (playerlist[i] == x)
            return i;
    }
    return 0;   //can't find the player, then return 0;
}


int main()
{
    std::ifstream txtfile("beaverducks2.txt");
    std::string line;
    std::vector<std::string> allPlayer;
    std::vector<int> from;
    std::vector<int> to;

    int marker = 0;
    bool checkRival = 0;
    std::string mystr;

    if (txtfile.is_open())
    {
        while (std::getline(txtfile, line))
        {
            //std::istringstream iss(line);
            if (marker == 0)                //first input is size of vertices
            {
                marker = stoi(line);
            }
            else if(marker !=0 && checkRival == false)
            {
                allPlayer.push_back(line);  //add to all player list
                marker--;
                if (marker == 0)            //if market == 0
                {
                    checkRival = true;      //set true to check rival relationship input
                }
            }
            else if (marker != 0 && checkRival == true)
            {
                std::istringstream iss(line);
                std::vector<std::string> substr;
                std::string string;
                    while (std::getline(iss, string, ' '))
                    {
                        std::cout << string << std::endl;
                        substr.push_back(string);
                    }
                    for (int i = 0; i < substr.size(); i++)
                    {
                        if (i == 0)
                            from.push_back(search(allPlayer, substr[i]));
                        else
                            to.push_back(search(allPlayer, substr[i]));
                    }
                marker--;
                if (marker == 0)                                            //done
                {
                    checkRival = false;
                }
            }
        }
    }
    txtfile.close();
        

    Graph g(allPlayer.size(), allPlayer);
    for (int i = 0; i < from.size(); i++)
    {
        g.addEdge(from[i], to[i]);  //add edges
        std::cout << allPlayer[from[i]] << " to " << allPlayer[to[i]] << std::endl;
        std::cout << from[i] << " to " << to[i] << std::endl;
    }


    if (g.isConflict())
    {
        //if there is confilct (Cross edge)
        std::cout << "Impossible";
    }
     
    else
    {
        std::cout << "Yes possible" << std::endl;
        g.printTeam();
    }
     
    return 0;
}