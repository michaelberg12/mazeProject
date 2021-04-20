#pragma once

template<typename nodeType>
class Node
{
public:

	Node(nodeType name);
	nodeType getName();

	bool operator==(const Node<nodeType>& other);

private:

	nodeType _name;
	
};

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
bool Node<nodeType>::operator==(const Node<nodeType>& other)
{
	return this->_name == other._name;
}

