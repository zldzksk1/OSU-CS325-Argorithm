#include<iostream> 
#include <list> 
#include <stack> 
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


struct direction    //save direction of edge
{
    int from;
    int to;
};

// Class to represent a graph 
class Graph
{
    // No. of vertices' 
    int V;

    // Pointer to an array containing adjacency listsList 
    std::list<int>* adj;

    // A function used by topologicalSort 
    void topologicalSortUtil(int v, bool visited[],
    std::stack<int>& Stack);
public:
    // Constructor 
    Graph(int V);

    // function to add an edge to graph 
    void addEdge(int v, int w);

    // prints a Topological Sort of  
// the complete graph 
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v¡¯s list. 
    adj[v].push_back(w);
}

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(
    int v, bool visited[],
    std::stack<int>& Stack)
{
    // Mark the current node as visited. 
    visited[v] = true;

    // Recur for all the vertices  
// adjacent to this vertex 
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack  
// which stores result 
    Stack.push(v);
}

// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
void Graph::topologicalSort()
{
    std::stack<int> Stack;

    // Mark all the vertices as not visited 
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function 
// to store Topological 
    // Sort starting from all  
// vertices one by one 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack 
    while (Stack.empty() == false)
    {
        std::cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions 

int search(std::vector<std::string> playerlist, std::string x)
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
    std::ifstream txtfile("beaverducks1.txt");
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
            if (line == "")
                break;
            if (marker == 0)                //first input is size of vertices
            {
                marker = stoi(line);
            }
            else if (marker != 0 && checkRival == false)
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
    // Create a graph given in the above diagram 

    Graph g(allPlayer.size());
    for (int i = 0; i < edges.size(); i++)
    {
        g.addEdge(edges[i].from, edges[i].to);  //add edges
        //std::cout << allPlayer[edges[i].from] << " to " << allPlayer[edges[i].to] << std::endl;
        //std::cout << edges[i].from << " to " << edges[i].to << std::endl;
    }

    std::cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}