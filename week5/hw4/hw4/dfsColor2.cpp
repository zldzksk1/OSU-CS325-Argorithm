#include "dfsColor2.hpp"

Graph::Graph(int V, std::vector<std::string>list)
{
    this->V = V;
    player = list;
    checker = 0;
    adj = new std::list<int>[V];
    cross = new teamNname[V];
}

// Utility function to add an edge 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list. 
}

// Recursive function to find if there is back edge 
// in DFS subtree tree rooted with 'u' 
bool Graph::DFSUtil(int u, int color[], teamNname cross[])
{
    // GRAY :  This vertex is being processed (DFS 
    //         for this vertex has started, but not 
    //         ended (or this vertex is in function 
    //         call stack) 
    
    color[u] = GRAY;                //if visit, then gray
    checker = checker + 1;          //count the order
    cross[u].visit = checker;       //(debug purpose)
    cross[u].name = player[u];



    // Iterate through all adjacent vertices 
    std::list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;  // An adjacent of u 

        // If there is 
        if (color[v] == GRAY)
            return true;

        // If v is not processed and there is a back 
        // edge in subtree rooted with v 
        if (color[v] == WHITE && DFSUtil(v, color, cross))
            return true;
        
        //Check the foward edge
        if (color[v] == BLACK)  //if it processed, check its team
        {  
            if (cross[v].team == "Ducks")   //if it is ducks, then cross[u] should be opposite team
            {
                if (cross[u].team == cross[v].team) //but if cross[u] already have a team, and if it is same team. it is cross edge
                {
                    //color[u] = BLACK;
                    //checker = checker + 1;
                    //cross[u].done = checker;
                    //return true;                    //return true for conflict
                }

                cross[u].team = "Beavers";          //if has a no team, then allocated to team
            }

            else if(cross[v].team == "Beavers")
            {
                if (cross[u].team == cross[v].team)
                {
                    //std::cout << "hit" << std::endl;
                    //color[u] = BLACK;
                    //checker = checker + 1;
                    //cross[u].done = checker;
                    //return true;
                }

                cross[u].team = "Ducks";
            }

        }
    }

    // Mark this vertex as processed
    color[u] = BLACK;
    checker = checker + 1;
    cross[u].done = checker;
    if (cross[u].team == "Noteam")  //if it doesn't have a team and don't have opponents, then give a team
    {
        if (checker % 2 == 0)
        {
            cross[u].team = "Beavers";
        }
        else
        {
            cross[u].team = "Ducks";
        }
    }

    return false;
}

// Returns true if there is a cycle in graph 
bool Graph::isConflict()
{
    // Initialize color of all vertices as WHITE 
    int* color = new int[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = WHITE;
        cross[i].visit = 0;
        cross[i].team = "Noteam";   //set all team as noteam
    }
    cross[0].team = "Beavers";  //But, the first player's team is Beavers

    // Do a DFS traversal beginning with all 
    // vertices 
    for (int i = 0; i < V; i++)
    {
        if (color[i] == WHITE)
        {
            if (DFSUtil(i, color, cross) == true)
                return true;
        }
        //checker = 0;
    }
     
    return false;
}

void Graph::printTeam()
{

    std::cout << "Beavers : ";
    for (int i = 0; i < player.size(); i++)
    {
        if(cross[i].team == "Beavers")
        {
            std::cout << cross[i].name << " ";
        }
    }
    
    std::cout << std::endl << "Ducks : ";
    for (int i = 0; i < player.size(); i++)
    {
        if (cross[i].team == "Ducks")
        {
            std::cout << cross[i].name << " ";
        }
    }
}