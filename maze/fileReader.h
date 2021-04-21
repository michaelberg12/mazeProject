#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Graph.h"
#include "Link.h"

class FileReader
{
public:
	FileReader(std::string file, Graph<char, Link> &graph);

	unsigned int long long satC();
	unsigned int long long conC();

private:
	unsigned int long long stationCount;
	unsigned int long long connectionCount;
};

