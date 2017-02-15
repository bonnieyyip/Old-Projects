//
//  BSTree.cpp
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#include "BSTree.h"

BSTree:: BSTree()
{
    root = NULL;
}

//BSTree:: ~BSTree()
//{
//    Empty();
//}

bool BSTree::insertHelper(Node* &nodePtr, Account *account)
{
    if(nodePtr == NULL)
    {
        Node *newNode = new Node;
        newNode->pAcct= account;
        newNode->left = NULL;
        newNode->right = NULL;
        nodePtr = newNode;
    }
    else if(account->getID() < nodePtr->pAcct->getID())
    {
        insertHelper(nodePtr->left, account);
    }
    else 
    {
        insertHelper(nodePtr->right, account);
    }
    return true;
}

bool BSTree::Insert(Account *account)
{
    insertHelper(root, account);
    return true;
}

//true if ID is found
bool BSTree::Retrieve(const int &ID, Account* &account) const
{
    Node *temp = root;
    
    if(isEmpty())
    {
        //        cout << "Tree is empty" << endl;
        return false;
    }
    while(true)
    {
        if(temp == NULL)
        {
            return false;
        }
        else if(temp->pAcct->getID() == ID)
        {
            account = temp->pAcct;
            //            cout << "FOUND" << endl;
            return true;
        }
        else if(temp->pAcct->getID() > ID)
        {
            temp = temp->left;
        }
        else if(temp->pAcct->getID() < ID)
        {
            temp = temp->right;
        }
        else
        {
            cout << "NOT FOUND" << endl;
            return false;
        }
    }
}

void BSTree::displayHelper(Node* tree) const
{
    if(isEmpty())
    {
        cout << "Tree is empty" << endl;
        return;
    }
    
    if(tree != NULL)
    {
        displayHelper(tree->left);
        cout << "\n";
        cout << "Client Account:" << *(tree->pAcct) << endl;
        for(int i = 0; i < 10; i++)
        {
            cout << "Fund" << i << " $" << *(tree->pAcct->getFund(i)) << endl;
        }
        displayHelper(tree->right);
        cout << "\n";
    }
}

//inorder
void BSTree::Display() const
{
    displayHelper(root);
}

//void BSTree::Empty()
//{
//    if(isEmpty())
//    {
//        cout << "Tree is empty" << endl;
//        return;
//    }
//
//    while (root != NULL)
//    {
//        deleteAll(root);
//    }
//}
//
//void BSTree::deleteAll(Node* tree)
//{
//    if(isEmpty())
//    {
//        cout << "Tree is empty" << endl;
//        return;
//    }
//
//    if(tree != NULL)
//    {
//        deleteAll(tree->left); //traverse tree all the way left
//        deleteAll(tree->right); //traverse tree all the way right from the final left
//        delete tree; //delete the final node
//    }
//}

bool BSTree::isEmpty() const
{
    return root == NULL;
}


