#include "BST.h"

void BST::insert(IntegerNode* newInteger)
{
    //IF the root is NULL(tree is empty), then make this INteger the root
    if (root == NULL)
    {
        root = newInteger;
        return; //exit function early, we are done here
    }

    //some pointers to help us navigate the tree to find where to put the new int
    IntegerNode* current = root; //current node we're pointing at
    IntegerNode* parent = NULL; //parent of current (node visitored last time)

    while (true)
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
         if (newInteger->numberNode < current->numberNode)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
             if (current == NULL)
            {
                //done, stick int here
                parent->leftChild = newInteger;
                return; //done, bail
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            //if current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newInteger;
                return;
            }
        }
    }
}

IntegerNode* BST::search(int numberNode, bool showSearchPath)
{
    if (root == NULL)
    {
        return NULL;
    }

    IntegerNode* current = root;

    while (current->numberNode != numberNode)
    {
        if (showSearchPath)
            

        if (numberNode < current->numberNode)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }

        if (current == NULL)
        {
            return NULL;
        }
    }

    return current;
    
}

void BST::inOrderTraversal(IntegerNode* current)
{
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        
        inOrderTraversal(current->rightChild);
    }
}

void BST::preOrderTraversal(IntegerNode* current)
{
    if (current != NULL)
    {
        
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }
}

void BST::postOrderTraversal(IntegerNode* current)
{
    if (current != NULL)
    {
        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
        
    }
}
