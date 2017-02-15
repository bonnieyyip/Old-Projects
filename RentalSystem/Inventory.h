//
//  Inventory.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Outputs the current inventory of all the items in the store

#ifndef Inventory_h
#define Inventory_h

#include <stdio.h>
#include "BinTree.h"
#include "Transaction.h"

class Inventory : public Transaction
{
    
public:
    Inventory();
    Inventory(BinTree *f, BinTree *d, BinTree *c);
    virtual bool perform();
    
private:
    BinTree *f;
    BinTree *d;
    BinTree *c;
};
#endif 
