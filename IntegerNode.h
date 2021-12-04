#pragma once
#include <iostream>
#include <string>


using namespace std;


class IntegerNode
{
public:
	int numberNode;
	string name;

	IntegerNode* leftChild;
	IntegerNode* rightChild;

	IntegerNode(int numberNode);

};

