#pragma once

template<typename nodeType>
class Node
{
public:

	Node(nodeType name);
	nodeType getName();

	bool Node::operator==(const Node other);
	bool Node::operator!=(const Node other);

private:

	nodeType _name;
	
};

