#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "Edge.h"
#include "Node.h"

template<typename nodeType, typename edgeType>
class Graph
{
public:

	Graph();
	Graph(std::vector<Edge<nodeType, edgeType>> edges);

	void addEdge(edgeType edge, nodeType start, nodeType end);
	
private:

	std::shared_ptr<Node<nodeType>> _addNodes(std::shared_ptr<Node<nodeType>> node);

	std::vector<std::shared_ptr<Edge<nodeType, edgeType>>> _edges;
	std::vector<std::shared_ptr<Node<nodeType>>> _nodes;

};


