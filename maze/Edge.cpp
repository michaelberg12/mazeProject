#include "Edge.h"

template<typename nodeType, typename edgeType>
inline Edge<nodeType, edgeType>::Edge(std::shared_ptr<Node<nodeType>> start, std::shared_ptr<Node<nodeType>> end)
{
	this->_start = start;
	this->_end = end;
}