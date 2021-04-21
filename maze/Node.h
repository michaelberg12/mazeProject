#pragma once

#include <set>

template<typename nodeType>
class Node
{
public:

	Node(nodeType name);
	nodeType getName();

	bool operator==(const Node<nodeType>& other);

	std::vector<std::shared_ptr<Node<nodeType>>> adj();

	void addAdj(std::shared_ptr<Node<nodeType>> node);

private:

	std::vector<std::shared_ptr<Node<nodeType>>> _adjacancyList;
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

template<typename nodeType>
inline void Node<nodeType>::addAdj(std::shared_ptr<Node<nodeType>> node)
{
	for (unsigned int a1 = 0; a1 < this->_adjacancyList.size(); a1++) {
		if (*this->_adjacancyList[a1] == *node) {
			return;
		}
	}

	this->_adjacancyList.push_back(node);
}

template<typename nodeType>
inline std::vector<std::shared_ptr<Node<nodeType>>> Node<nodeType>::adj()
{
	return this->_adjacancyList;
}