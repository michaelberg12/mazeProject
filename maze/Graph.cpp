#include "Graph.h"

template<typename nodeType, typename edgeType>
inline Graph<nodeType, edgeType>::Graph()
{
	this->_edges = std::vector<Edge<nodeType, edgeType>>();
}

template<typename nodeType, typename edgeType>
Graph<nodeType, edgeType>::Graph(std::vector<Edge<nodeType, edgeType>> edges)
{
	this->_edges = edges;
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






