#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <vector>

struct direction
{
    int from;
    int to;
};

class Graph
{
    int V;    // No. of vertices 
    std::list<int>* adj;    // Pointer to an array containing adjacency lists 
    void DFSUtil(int v, bool visited[]);  // A function used by DFS 
public:
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    void DFS();    // prints DFS traversal of the complete graph 
};
