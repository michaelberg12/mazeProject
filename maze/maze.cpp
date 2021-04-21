
#include <iostream>
#include "fileReader.h"
#include "Graph.h"
#include "Link.h"


bool trainRules(char last, char now, char next, Graph<char, Link>* g, std::vector<char> discovered) {

    g->biDirectional = true;

    //check if that sequence has happened
        //this should be in tie breaker
    for (int a1 = 0; discovered.size() == 2 && a1 < (discovered.size() - 1); a1++) {
        if (discovered[a1] == now && discovered[a1 + 1] == next) {
            return false;
        }
    }

    auto lastEdge = g->getEdge(last, now);
    auto nextEdge = g->getEdge(now, next);
    
    if (lastEdge == nullptr) {
        return true;
    }

    Color lastColor = lastEdge->info.color;
    Transport lastTransport = lastEdge->info.transport;

    Color nextColor = nextEdge->info.color;
    Transport nextTransport = nextEdge->info.transport;

    return (lastColor == nextColor || lastTransport == nextTransport) && last != next;

}

bool tradDfs(char last, char now, char next, Graph<char, Link>* g, std::vector<char> discovered) {

    return std::find(discovered.begin(), discovered.end(), next) == discovered.end();
}

int main()
{
    
    Graph<char, Link> g = Graph<char, Link>();
    FileReader fileReader = FileReader("example.txt", g);

    for (auto stations : g.dfsPath('A', 'j', 100, tradDfs, true)) {
        std::cout << stations->getName() << " ";
    }

    return 0;
}


