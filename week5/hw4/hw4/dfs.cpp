#include "dfs.hpp"


Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list. 
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it 
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent to this vertex 
    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// The function to do DFS traversal. It uses recursive DFSUtil() 
void Graph::DFS()
{
    // Mark all the vertices as not visited 
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}