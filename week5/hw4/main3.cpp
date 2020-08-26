//Sangyun Lee
//CS325
//I adopt and referred the code and idea from links below 
//https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/ 
//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/depthSearch.htm
//https://www.sanfoundry.com/cpp-program-check-bipartite-graph/

#include "dfsColor2.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring> 

//variable for vertices and edges
int n, e, i, j;
std::vector<std::vector<int> > graph;
std::vector<int> color;
bool vis[100011];

void displayTeam(std::vector<std::string>playerlist, std::vector<int> from, std::vector<int> to)
{
	//
}

bool isBipartite()
{
	color[0] = 1; // Mark color as 1 for first vertex.
	std::queue <int> q;
	q.push(0);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (i = 0; i < n; i++)
		{
			if (graph[temp][i] && color[i] == -1) //if there is an edge, and color is not assigned
			{
				color[i] = 1 - color[temp];
				//std::cout << color[i] <<" ";
				q.push(i);
			}
			else if (graph[temp][i] && color[i] == color[temp]) // if there is an edge and both vertices have the same colors
				return 0;                                   // graph is not bipartite
		}
	}
	return 1;
}

int SearchName(std::vector<std::string>Players, std::string name)
{
	for (int i = 0; i < Players.size(); i++)
	{
		if (Players[i] == name)	//if name is matched, i is the index of the player
		{
			return i;
		}
	}
	return 0;
}

int main()
{

	int x, y;
	std::string line;
	std::vector<std::string> allPlayer;
	std::vector<int> from;
	std::vector<int> to;
	std::string userInput;

	std::cout << "Please enter the file name without a file extension" << std::endl;
	std::getline(std::cin, userInput);
	userInput = userInput + ".txt";
	//std::cout << userInput;

	std::ifstream txtfile(userInput);
	int marker = 0;
	bool checkRival = 0;
	bool doubleMarker = 1;
	bool distingush = 0;
	std::string mystr;

	if (txtfile.is_open())
	{
		while (std::getline(txtfile, line))
		{
			std::istringstream iss(line);
			while (iss >> mystr)
			{
				if (marker == 0)
				{
					marker = stoi(mystr);
					if (distingush == 0)
						n = marker;
					else if (distingush == 1)
						e = marker;
				}
				else if (marker != 0 && checkRival == 0)
				{
					allPlayer.push_back(mystr);
					marker--;
					if (marker == 0)
					{
						checkRival = 1;
						distingush = 1;
					}
				}
				else if (marker != 0 && checkRival == 1)
				{
					if (doubleMarker == 1)
					{
						marker = marker * 2;
						doubleMarker = 0;
					}

					if (marker % 2 == 0)
					{
						from.push_back(SearchName(allPlayer, mystr));
						marker--;
					}

					else if (marker % 2 == 1)
					{
						to.push_back(SearchName(allPlayer, mystr));
						marker--;
					}
				}
			}
		}
	}

	txtfile.close();

	std::cout << "\n";
	graph.resize(n);
	color.resize(n, -1);
	std::memset(vis, 0, sizeof(vis));
	for (i = 0; i < n; i++)
		graph[i].resize(n);
	for (i = 0; i < e; i++)
	{

		graph[from[i]][to[i]] = 1;
		graph[to[i]][from[i]] = 1;
	}
	if (isBipartite())	//if it is bipartite graph, then make graph and allocating team with dfs
	{
		std::cout << "Yes, possible.\n";
		//displayTeam(allPlayer,from,to);

		Graph g(allPlayer.size(), allPlayer);
		for (int i = 0; i < from.size() && i < to.size(); i++)
		{
			g.addEdge(from[i], to[i]);
		}
		g.isConflict();
		g.printTeam();
	}
	else
		std::cout << "No, impossible.\n";
	return 0;
}