#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h> 
#include <string.h>

#ifndef DFSCOLOR2_HPP
#define DFSCOLOR2_HPP

//struct direction    //save direction of edge
//{
//    int from;
//    int to;
//};

struct teamNname    //record graph traversal and team name
{
    int visit;
    int done;
    std::string team;
    std::string name;
};

enum Color { WHITE, GRAY, BLACK };

// Graph class represents a directed graph using 
// adjacency list representation 
class Graph
{
    int V; // Nnumber of vertices 
    int checker;    // count the visit
    teamNname* cross;   //check team;

    std::list<int>* adj; // adjacency lists 
    std::vector<std::string> player;    //all player list

    // DFS traversal of the vertices reachable from v 
    bool DFSUtil(int v, int color[] , teamNname cross[]);
public:
    Graph(int V, std::vector<std::string>list);  // Constructor 

    // function to add an edge to graph 
    void addEdge(int v, int w);
    bool isConflict();   // check cross edges
    void printTeam();   //display team
};

#endif