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
    std::ifstream txtfile("beaverducks.txt");
    std::string line;
    std::vector<std::string> allPlayer;
    std::vector<direction> edges;
    struct direction dir;

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
                std::string delimiter = " ";                                //set delimiter
                size_t pos = line.find(delimiter);
                std::string from = line.substr(0, pos);                     //direction from
                std::string to = line.substr(pos + 1, line.length() - 1);   //direction to
                dir.from = search(allPlayer, from);
                dir.to = search(allPlayer, to);
                edges.push_back(dir);
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
    for (int i = 0; i < edges.size(); i++)
    {
        g.addEdge(edges[i].from, edges[i].to);  //add edges
        //std::cout << allPlayer[edges[i].from] << " to " << allPlayer[edges[i].to] << std::endl;
        //std::cout << edges[i].from << " to " << edges[i].to << std::endl;
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