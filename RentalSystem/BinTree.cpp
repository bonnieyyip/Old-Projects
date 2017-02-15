//
//  BinTree.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "BinTree.h"

//------------------------- BinTree ---------------------------------
// Default constructor
// Creates an empty tree
// Preconditions: NONE
// Postconditions: Tree is created and is empty, with root initialized as null
BinTree::BinTree()
{
    root = NULL;
}

//------------------------- ~BinTree ---------------------------------
// Default destructor
// Destroys a tree
// Preconditions: Tree must have data
// Postconditions: Tree is emptied and deleted every time a constructor is called
BinTree::~BinTree()
{
    makeEmpty();
}

//------------------------- isEmpty ---------------------------------
// Checks to see if tree is empty or not
// True or false is returned to show if there is data in the tree
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::isEmpty() const
{
    return root == NULL;
}

//------------------------- makeEmpty ---------------------------------
// Makes a tree empty
// Preconditions: NONE
// Postconditions: BinTree is now empty
void BinTree::makeEmpty()
{
    if(isEmpty())
    {
        return;
    }
    
    while (root != NULL)
    {
        makeEmptyHelper(root);
    }
}

//------------------------- makeEmpty Helper ---------------------------------
// Helper method for makeEmpty
// Preconditions: NONE
// Postconditions: BinTree is now empty

void BinTree::makeEmptyHelper(Node* current)
{
    if(current != NULL)
    {
        makeEmptyHelper(current->left);
        makeEmptyHelper(current->right);
        delete root;
        root = NULL;
    }
}

//------------------------- insert ---------------------------------
// Inserts a Movie object into a tree
// Preconditions: Passed in object must be a Movie
// Postconditions: BinTree now has the object inserted

bool BinTree::insert(Movie *obj)
{
    Node* ptr = new Node;
    ptr->data = obj; //set ptr's data to equal to the obj
    obj = NULL; //data is now only in the ptr
    ptr->left = NULL;
    ptr->right = NULL;
    
    if (isEmpty())
    {
        root = ptr;
    }
    else
    {
        Node* current = root;
        bool inserted = false;
        
        while (!inserted)
        {
//            if (*ptr->data == *current->data) //duplicate
//            {
//                delete ptr;
//                ptr = NULL;
//                return false;
//            }
            if (*ptr->data < *current->data)
            {
                if (current->left == NULL)
                {
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left;
            }
            else {
                if (current->right == NULL)
                {
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right;
            }
        }
    }
    return true;
}

//------------------------- retrieve ---------------------------------
// Looks for a Movie object in the tree
// Returns true or false based on if the object was found
// Does not remove the object from the tree
// Preconditions: NONE
// Postconditions: BinTree remains unchanged

bool BinTree::retrieve(const string &title, Movie* &objPtr)
{
    Node *temp = root;
    
    if(isEmpty())
    {
        return false;
    }
    
    while(true)
    {
        if(temp == NULL)
        {
            return false;
        }
        else if(temp->data->getTitle() == title)
        {
            objPtr = temp->data;
            return true;
        }
        else if(title < temp->data->getTitle())
        {
            temp = temp->left;
        }
        else if(title > temp->data->getTitle())
        {
            temp = temp->right;
        }
        else
        {
            return false;
        }
    }
}

bool BinTree::classicRetrieve(const Movie &obj, Movie* &objPtr)
{
    Node *temp = root;
    
    if(isEmpty())
    {
        return false;
    }
    
    while(true)
    {
        if(temp == NULL)
        {
            return false;
        }
        else if(*temp->data == obj)
        {
            objPtr = temp->data;
            return true;
        }
        else if(obj < *temp->data)
        {
            temp = temp->left;
        }
        else if(obj > *temp->data)
        {
            temp = temp->right;
        }
        else
        {
            return false;
        }
    }
}

//---------------------------- Equals -------------------------------------
// Checks to see if two trees are equal
// Two trees are equal if they have the same Movie objects and if each parent has the same children
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::operator==(const BinTree &rhs) const
{
    if(root == NULL && rhs.root == NULL)
    {
        return true;
    }
    
    return isEqual(root, rhs.root);
}

//---------------------------- isEqual -------------------------------------
// Helper method for Equals
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::isEqual(Node* l, Node* r) const
{
    if((l != NULL && r != NULL) && (*l->data == *r->data))
    {
        return true;
    }
    
    if(l == NULL || r == NULL)
    {
        return false;
    }
    
    return (l->data == r->data) && isEqual(l->left, r->left) && isEqual(l->right, r->right);
}

//---------------------------- Does Not Equal -------------------------------------
// Checks to see if two trees aren't equal
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::operator!=(const BinTree &rhs) const
{
    return !(*this == rhs);
}

void BinTree::displayHelper(Node* tree) const
{
    if(isEmpty())
    {
        cout << "Tree is empty" << endl;
        return;
    }
    
    if(tree != NULL)
    {
        displayHelper(tree->left);
        cout << *(tree->data) << " " << endl;
        displayHelper(tree->right);
    }
}

//inorder
void BinTree::display() const
{
    displayHelper(root);
}


