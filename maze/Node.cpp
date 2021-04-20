#include "Node.h"

template<typename nodeType>
inline Node<nodeType>::Node(nodeType name)
{
	this->_name = name;
}

template<typename nodeType>
nodeType Node<nodeType>::getName()
{
	return this->_name;
}

template<typename nodeType>
bool Node<nodeType>::operator==(const Node other)
{
	return this->_name == other._name;
}

template<typename nodeType>
bool Node<nodeType>::operator!=(const Node other)
{
	return this->_name != other._name;
}
