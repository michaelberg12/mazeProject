#pragma once

#include <vector>
#include <map>
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

	std::vector<std::shared_ptr<Node<nodeType>>> dfsPath(nodeType source, nodeType destination);

	std::vector<nodeType> dfs(std::vector<nodeType> discovered, nodeType nodeName, nodeType target);

private:

	std::shared_ptr<Node<nodeType>> _addNodes(std::shared_ptr<Node<nodeType>> node);
	std::vector < std::shared_ptr<Node<nodeType>>> _getAdjs(nodeType nodeName);

	std::vector<std::shared_ptr<Edge<nodeType, edgeType>>> _edges;
	std::map<nodeType, std::shared_ptr<Node<nodeType>>> _nodes;

};

template<typename nodeType, typename edgeType>
inline Graph<nodeType, edgeType>::Graph()
{
	this->_edges = std::vector<std::shared_ptr<Edge<nodeType, edgeType>>>();
	this->_nodes = std::map<nodeType, std::shared_ptr<Node<nodeType>>>();
}

template<typename nodeType, typename edgeType>
void Graph<nodeType, edgeType>::addEdge(edgeType edge, nodeType start, nodeType end)
{
	//create edge and nodes
	std::shared_ptr<Node<nodeType>> startNode(new Node<nodeType>(start));
	std::shared_ptr<Node<nodeType>> endNode(new Node<nodeType>(end));

	startNode = this->_addNodes(startNode);
	endNode = this->_addNodes(endNode);

	startNode->addAdj(endNode);
	endNode->addAdj(startNode);

	//store the edge with the unique pointers
	std::shared_ptr<Edge<nodeType, edgeType>> returnValue(new Edge<nodeType, edgeType>(edge, startNode, endNode));

	//store created data
	this->_edges.push_back(returnValue);
}

template<typename nodeType, typename edgeType>
inline std::vector<std::shared_ptr<Node<nodeType>>> Graph<nodeType, edgeType>::dfsPath(nodeType source, nodeType destination)
{
	std::vector<std::shared_ptr<Node<nodeType>>> returnValue;

	std::vector<nodeType> path = this->dfs(path, source, destination);

	if (!path.empty()) {
		for (nodeType stops : path) {
			returnValue.push_back(this->_nodes[stops]);
		}
	}

	return returnValue;
}

template<typename nodeType, typename edgeType>
inline std::vector<nodeType> Graph<nodeType, edgeType>::dfs(std::vector<nodeType> discovered, nodeType nodeName, nodeType target)
{
	
	if (nodeName == target) {
		discovered.push_back(nodeName);
		return discovered;
	}

	if (std::find(discovered.begin(), discovered.end(), nodeName) == discovered.end()) {
		//not discovered
		discovered.push_back(nodeName);
		for(std::shared_ptr<Node<nodeType>> nodeAdj : this->_getAdjs(nodeName)) {
			std::vector<nodeType> adjDiscovered = this->dfs(discovered, nodeAdj->getName(), target);
			if (!adjDiscovered.empty()){
				//found the target node
				return adjDiscovered;
			}
			//only happens if returned false
		}
	}

	return std::vector<nodeType>();

}




template<typename nodeType, typename edgeType>
std::shared_ptr<Node<nodeType>> Graph<nodeType, edgeType>::_addNodes(std::shared_ptr<Node<nodeType>> node)
{
	//ensure unique
	if (this->_nodes.count(node->getName()) > 0) {
		//found so return the one from the list and manualy delete the old one
		return this->_nodes[node->getName()];
	}
	//not found so return original

	this->_nodes[node->getName()] = (node);
	return node;
}

template<typename nodeType, typename edgeType>
inline std::vector<std::shared_ptr<Node<nodeType>>> Graph<nodeType, edgeType>::_getAdjs(nodeType nodeName)
{
	return this->_nodes[nodeName]->adj();
}


