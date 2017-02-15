//
//  HashMap.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 12/13/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  This class will hash the Customers based on their unique ID by linear probing
//  The table size is set to 211 because we assume that there is a max number of
//  customers of 200. To minimize the chance of collisions (which reduces the
//  efficiency of the hash table, the next prime number after 200 is 211.

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>
#include "HashEntry.h"

const int TABLE_SIZE = 211;

class HashMap
{
public:
    HashMap();
    void insert(int ID, Customer *c);
    bool isInTable(int ID);
    Customer* retrieve(int ID);
    void print();
    ~HashMap();
    
private:
    HashEntry **table;
};
#endif
