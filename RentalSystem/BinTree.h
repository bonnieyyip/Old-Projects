//
//  BinTree.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  This class will sort the movies from “smallest” to “biggest” depending on the type of movie

#ifndef BinTree_h
#define BinTree_h

#include <stdio.h>
#include <iostream>
#include "Movie.h"
#include "Classic.h"

class BinTree
{
    
public:
    //Constructors/ Destructor
    BinTree();
    ~BinTree();
    
    //Functions
    bool isEmpty() const;
    void makeEmpty();
    bool insert(Movie* obj);
    bool retrieve(const string &title, Movie* &objPtr);
    bool classicRetrieve(const Movie &obj, Movie* &objPtr);
    
    //Displays the contents of a tree to cout
    void display() const;
    
    //Overloaded Operators
    bool operator==(const BinTree &rhs) const;
    bool operator!=(const BinTree &rhs) const;
    
private:
    struct Node
    {
        Movie* data;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    void displayHelper(Node* tree) const;
    void makeEmptyHelper(Node* current);
    bool isEqual(Node* l, Node* r) const;

};
#endif
