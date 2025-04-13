#define UINT_MAX 0xFFFFFFFF

#include "directed_edge.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

void dijkstra(std::unique_ptr<std::vector<directed_edge>> directed_graph, unsigned int s, unsigned int t) // output is defined if and only if nodes are indexed consecutively from '0' to 'n - 1', where 'n' is the number of nodes
{	auto max = [](unsigned int uint_a, unsigned int uint_b)
	{	return uint_a > uint_b ? uint_a : uint_b;
	};
	auto print = [](const std::vector<unsigned int>& vector)
	{	for(unsigned int i = 0; i < vector.size(); ++i)
		{	std::cout << vector.at(i);
			if(i < vector.size() - 1)
			{	std::cout << ' ';
			}
		}
	};
	unsigned int n = 0;
	for(const directed_edge& edge : *directed_graph)
	{	n = max(n, max(edge.p, edge.q));
	}
	n += 1;
	unsigned int p = s;
	std::vector<unsigned int> P(n, 0); // std::vector for runtime instantiation
	P.at(s) = 1;
	std::vector<unsigned int> D(n, UINT_MAX); // std::vector for runtime instantiation
	D.at(s) = 0;
	std::vector<unsigned int> A(n, UINT_MAX); // std::vector for runtime instantiation
	A.at(s) = 0;
	while(P.at(t) == 0)
	{	for(const directed_edge& edge : *directed_graph)
		{	if(edge.p == p &&
				P.at(edge.q) == 0 &&
				D.at(edge.q) > D.at(edge.p) + edge.d)
			{	D.at(edge.q) = D.at(edge.p) + edge.d;
				A.at(edge.q) = p;
			}
		}
		unsigned int min_dist = UINT_MAX;
		unsigned int min_index = 0;
		for(unsigned int i = 0; i < n; ++i)
		{	if(P.at(i) == 0 && 
				D.at(i) < min_dist)
			{	min_dist = D.at(i);
				min_index = i;
			}
		}
		if(min_dist == UINT_MAX)
		{	throw std::runtime_error("dijkstra: target is unreachable");
		}
		p = min_index;
		P.at(p) = 1;
	}
	std::cout << "I: ";
	for(unsigned int i = 0; i < n; ++i)
	{	std::cout << i;
		if(i < n - 1)
		{	std::cout << ' ';
		}
	}
	std::cout << '\n';
	std::cout << "---";
	for(unsigned int i = 0; i < n; ++i)
	{	std::cout << '-';
		if(i < n - 1)
		{	std::cout << '-';
		}
	}
	std::cout << '\n';
	std::cout << "P: ";
	print(P);
	std::cout << '\n';
	std::cout << "D: ";
	print(D);
	std::cout << '\n';
	std::cout << "A: ";
	print(A);
	std::cout << '\n';
}
std::unique_ptr<std::vector<directed_edge>> parse(std::ifstream& in)
{	std::unique_ptr<std::vector<directed_edge>> directed_graph = std::make_unique<std::vector<directed_edge>>();
	std::string line;
	try
	{	while(std::getline(in, line))
		{	directed_edge new_edge;
			new_edge.p = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			new_edge.q = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			new_edge.d = std::stoul(line);
			directed_graph->push_back(new_edge);
		}
	}
	catch(const std::exception& e)
	{	throw std::runtime_error(std::string("parse: ") + e.what());
	}
	return directed_graph;
}
int main(int argc, char* argv[])
{	if(argc != 4)
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
	{	std::cerr << "error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	try
	{	dijkstra(std::move(directed_graph), std::stoul(argv[2]), std::stoul(argv[3]));
	}
	catch(const std::exception& e)
	{	std::cerr << "error: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}