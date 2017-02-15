//
//  HashEntry.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Hash Map calls this class in order to make an array

#ifndef HashEntry_h
#define HashEntry_h

#include <stdio.h>
#include <iostream>
#include "Customer.h"
using namespace std;

class HashEntry
{
public:
    HashEntry(int ID, Customer *c);
    int getID();
    Customer* getCustomer();
    
private:
    int ID;
    Customer *c;
};

#endif
