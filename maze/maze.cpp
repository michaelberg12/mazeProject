
#include <iostream>
#include "fileReader.h"
#include "Graph.h"
#include "Link.h"



int main()
{
    
    Graph<char, Link> g = Graph<char, Link>();
    FileReader fileReader = FileReader("example.txt", g);

    for (auto stations : g.dfsPath('A', 'j')) {
        std::cout << stations->getName() << " ";
    }
}


