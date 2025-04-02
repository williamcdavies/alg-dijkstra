#include "directed_edge.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

void dijkstra(std::unique_ptr<std::vector<directed_edge>> directed_graph, unsigned int s, unsigned int t)
{	auto max = [](unsigned int uint_a, unsigned int uint_b)
	{	return uint_a > uint_b ? uint_a : uint_b;
	};
	unsigned int n = 0;
	for(unsigned int i = 0; i < directed_graph.get()->size(); ++i)
	{	unsigned int m = max(directed_graph.get()->at(i).s, directed_graph.get()->at(i).t);
		if(m > n)
		{	n = m;
		}
	}
	unsigned int p = s;
	std::vector<unsigned int> P(n, 0); // std::vector for runtime instantiation
	P.at(s - 1) = 1;
	std::vector<unsigned int> D(n, 0xFFFFFFFF); // std::vector for runtime instantiation
	D.at(s - 1) = 0;
	std::vector<unsigned int> A(n, 0xFFFFFFFF); // std::vector for runtime instantiation
	A.at(s - 1) = 0;
}
std::unique_ptr<std::vector<directed_edge>> parse(std::ifstream& in)
{	std::unique_ptr<std::vector<directed_edge>> directed_graph = std::make_unique<std::vector<directed_edge>>();
	std::string line;
	try
	{	while(std::getline(in, line))
		{	directed_edge new_edge;
			new_edge.s = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			new_edge.t = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			new_edge.d = std::stoul(line);
			directed_graph.get()->push_back(new_edge);
		}
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';
		throw;
	}
	return directed_graph;
}
int main(int argc, char* argv[])
{	if(argc != 2)
	{	return EXIT_FAILURE;
	}
	std::ifstream in(argv[1]);
	if(!in.is_open())
	{	return EXIT_FAILURE;
	}
	std::unique_ptr<std::vector<directed_edge>> directed_graph = std::make_unique<std::vector<directed_edge>>();
	try
	{	directed_graph = parse(in);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}