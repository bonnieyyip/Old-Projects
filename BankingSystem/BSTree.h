//
//  BSTree.h
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#ifndef JollyBanker_BSTree_h
#define JollyBanker_BSTree_h
#include "Account.h"

class BSTree
{
    
public:
    BSTree();
    //    ~BSTree();
    
    bool Insert(Account *account);
    
    // retrieve object, first parameter is the ID of the account
    // second parameter holds pointer to found object, NULL if not found
    bool Retrieve(const int &ID, Account* &account) const;
    
    // displays the contents of a tree to cout
    void Display() const;
    
    //    void Empty();
    bool isEmpty() const;
    
private:
    struct Node
    {
        Account *pAcct;
        Node *right = NULL;
        Node *left = NULL;
    };
    
    Node *root;
    
    bool insertHelper(Node *&nodePtr, Account *account);
    void displayHelper(Node* tree) const;
    void deleteAll(Node* tree);
};
#endif
