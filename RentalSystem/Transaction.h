//
//  Transaction.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Parent class for actions that customers can perform at the rental store

#ifndef Transaction_h
#define Transaction_h

#include <stdio.h>
#include "Customer.h"
#include <queue>
#include <iostream>

class Transaction
{
    
public:
    Transaction();
    virtual bool perform();
    ~Transaction();
    
protected:
    queue<string> transactions;
};
#endif
