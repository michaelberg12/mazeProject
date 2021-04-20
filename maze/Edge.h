#pragma once

#include <memory>
#include "Node.h"

template<typename nodeType, typename edgeType>
class Edge
{
public:

	Edge(std::shared_ptr<Node<nodeType>> start, std::shared_ptr<Node<nodeType>> end);

	edgeType info;

private:

	//smart pointers so we don't have to worry about deleting the memory
	std::shared_ptr<Node<nodeType>> _start;
	std::shared_ptr<Node<nodeType>> _end;

};

template<typename nodeType, typename edgeType>
inline Edge<nodeType, edgeType>::Edge(std::shared_ptr<Node<nodeType>> start, std::shared_ptr<Node<nodeType>> end)
{
	this->_start = start;
	this->_end = end;
}


