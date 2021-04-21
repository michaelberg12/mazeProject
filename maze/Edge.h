#pragma once

#include <memory>
#include "Node.h"

template<typename nodeType, typename edgeType>
struct Edge
{
	Edge();
	Edge(edgeType edgeInfo, std::shared_ptr<Node<nodeType>> edgeStart, std::shared_ptr<Node<nodeType>> edgeEnd);

	edgeType info;
	std::shared_ptr<Node<nodeType>> start;
	std::shared_ptr<Node<nodeType>> end;
};


template<typename nodeType, typename edgeType>
Edge<nodeType, edgeType>::Edge() {
	//do nothing
};

template<typename nodeType, typename edgeType>
inline Edge<nodeType, edgeType>::Edge(edgeType edgeInfo, 
	std::shared_ptr<Node<nodeType>> edgeStart, 
	std::shared_ptr<Node<nodeType>> edgeEnd)
{
	info = edgeInfo;
	start = edgeStart;
	end = edgeEnd;
};


