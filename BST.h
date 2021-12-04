#pragma once
#include "IntegerNode.h"

class BST
{
public:
	IntegerNode* root = NULL;
	virtual void insert(IntegerNode* newInteger);
	IntegerNode* search(int numberNode, bool showSearchPath = false);

	//traversals
	void inOrderTraversal(IntegerNode* current);
	void preOrderTraversal(IntegerNode* current);
	void postOrderTraversal(IntegerNode* current);



};

