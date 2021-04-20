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
	void addEdge(edgeType edge, nodeType start, nodeType end);
	
private:

	std::shared_ptr<Node<nodeType>> _addNodes(std::shared_ptr<Node<nodeType>> node);

	std::vector<std::shared_ptr<Edge<nodeType, edgeType>>> _edges;
	std::vector<std::shared_ptr<Node<nodeType>>> _nodes;

};

template<typename nodeType, typename edgeType>
inline Graph<nodeType, edgeType>::Graph()
{
	this->_edges = std::vector<std::shared_ptr<Edge<nodeType, edgeType>>>();
	this->_nodes = std::vector<std::shared_ptr<Node<nodeType>>>();
}

template<typename nodeType, typename edgeType>
void Graph<nodeType, edgeType>::addEdge(edgeType edge, nodeType start, nodeType end)
{
	//create edge and nodes
	std::shared_ptr<Node<nodeType>> startNode = std::make_shared(new Node(start));
	std::shared_ptr<Node<nodeType>> endNode = std::make_shared(new Node(end));

	startNode = this->_addNodes(startNode);
	endNode = this->_addNodes(endNode);

	//store the edge with the unique pointers
	std::shared_ptr<Edge<nodeType, edgeType>> endNode = std::make_shared(new Edge(startNode, endNode));

	//store created data
	this->_edges.push_back(endNode);
}

template<typename nodeType, typename edgeType>
std::shared_ptr<Node<nodeType>> Graph<nodeType, edgeType>::_addNodes(std::shared_ptr<Node<nodeType>> node)
{
	//ensure unique

	//check if it exists
	std::vector<Node<nodeType>>::iterator<Node<nodeType>> foundNode = std::find(this->_nodes.begin(), this->_nodes.end(), node->getName());
	if (foundNode != this->_nodes.end()) {
		//found so return the one from the list and manualy delete the old one
		delete node;
		return this->_nodes.at(foundNode);
	}
	//not found so return original
	return node;
}


