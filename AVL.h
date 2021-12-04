#pragma once
#include "BST.h"


class AVL : public BST
{
public:
	bool displayRotations = true;

	int height(IntegerNode* node);

	int difference(IntegerNode* node);

	IntegerNode* RRrotation(IntegerNode* parent);

	IntegerNode* LLrotation(IntegerNode* parent);

	IntegerNode* LRrotation(IntegerNode* parent);

	IntegerNode* RLrotation(IntegerNode* parent);

	IntegerNode* balance(IntegerNode* parent);

	IntegerNode* insertAVL(IntegerNode* parent, IntegerNode* newInteger);

	void insert(IntegerNode* newInteger);



};

