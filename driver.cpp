#include "dedge.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::unique_ptr<std::vector<dedge>> parse(std::ifstream& in)
{	std::unique_ptr<std::vector<dedge>> dgraph = std::make_unique<std::vector<dedge>>();
	std::string line;
	try
	{	while(std::getline(in, line))
		{	dedge dedge;
			dedge.a = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			dedge.b = std::stoul(line.substr(0, line.find_first_of(',')));
			line.erase(0, line.find_first_of(',') + 1);
			dedge.d = std::stoul(line);
			dgraph.get()->push_back(dedge);
		}
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';
		throw;
	}
	return dgraph;
}
int main(int argc, char* argv[])
{	if(argc != 2)
	{	return EXIT_FAILURE;
	}
	std::ifstream in(argv[1]);
	if(!in.is_open())
	{	return EXIT_FAILURE;
	}
	std::unique_ptr<std::vector<dedge>> dgraph = std::make_unique<std::vector<dedge>>();
	try
	{	dgraph = parse(in);
	}
	catch(const std::exception& e)
	{	std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}