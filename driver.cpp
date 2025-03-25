#include "objects/directed_graph.h"
#include "objects/directed_graph.h"
#include <fstream>
#include <iostream>
#include <string>

directed_graph* parse(std::ifstream& in)
{	directed_graph* dgraph = new directed_graph;
	std::string line;
	while(std::getline(in, line))
	{	directed_edge edge;
		edge.a = std::stoul(line.substr(0, line.find_first_of(':')));
		line.erase(0, line.find_first_of(':') + 1);
		edge.b = std::stoul(line.substr(0, line.find_first_of(':')));
		line.erase(0, line.find_first_of(':') + 1);
		edge.l = std::stoul(line);
		dgraph->edges.push_back(edge);
	}
	return dgraph;
}

void find_shortest_path(unsigned int a, unsigned int b, directed_graph* dgraph)
{	
}

int main(int argc, char* argv[])
{	if(argc != 2)
	{	return 1; 
	}
	std::ifstream in(argv[1]);
	if(!in.is_open())
	{	return 1;
	}
	directed_graph* dgraph = parse(in);
	
	delete dgraph;
	return 0;
}