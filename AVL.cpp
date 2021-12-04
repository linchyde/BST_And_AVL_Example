#include "AVL.h"

int AVL::height(IntegerNode* node)
{
    int h = 0;
     if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        //max gets biggest of the 2 and discards the smaller
        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    return h;
}

int AVL::difference(IntegerNode* node)
{
    //if empty tree, well its balanced, its 0
    if (node == NULL)
        return 0;

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

IntegerNode* AVL::RRrotation(IntegerNode* parent)
{
    IntegerNode* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    

    return temp;
}

IntegerNode* AVL::LLrotation(IntegerNode* parent)
{
    IntegerNode* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
   

    return temp;
}

IntegerNode* AVL::LRrotation(IntegerNode* parent)
{
    IntegerNode* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    
    return LLrotation(parent);
}

IntegerNode* AVL::RLrotation(IntegerNode* parent)
{
    IntegerNode* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
  
    return RRrotation(parent);
}

IntegerNode* AVL::balance(IntegerNode* parent)
{
    //get balance factor
    int balanceFactor = difference(parent);

    //IF balanceFactor not within -1,0,1, then lets work out what rotations to do
    if (balanceFactor > 1)
    {
        //left branch is heavy, now work out is left or right child heavy
        if (difference(parent->leftChild) > 0)
        {
            //left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            //right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        //right branch is heavy, but which child
        if (difference(parent->rightChild) > 0)
        {
            //left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            //right child heavy
            parent = RRrotation(parent);
        }
    }


    return parent;
}

IntegerNode* AVL::insertAVL(IntegerNode* parent, IntegerNode* newInteger)
{
    //if sub tree empty, this becomes the parent
    if (parent == NULL)
    {
        parent = newInteger;
        return parent;
    }

    //parent not null, so we haven't found an empty space to stick new Integer yet
    //so we need to go down either left or right path
    if (newInteger->numberNode < parent->numberNode)
    {
        parent->leftChild = insertAVL(parent->leftChild, newInteger);
        parent = balance(parent);
    }
    else //assume id >= parent's id
    {
        parent->rightChild = insertAVL(parent->rightChild, newInteger);
        parent = balance(parent);
    }
}

void AVL::insert(IntegerNode* newInteger)
{
    root = insertAVL(root, newInteger);
 }
