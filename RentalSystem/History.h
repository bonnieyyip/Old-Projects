//
//  History.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Outputs all the transactions of a customer found by their unique ID. Prints the history from earliest to latest
//  Outputs either by title or major actor name depending on the type of movie

#ifndef History_h
#define History_h

#include <stdio.h>
#include "Transaction.h"
#include "Customer.h"
#include "HashMap.h"

class History : public Transaction
{
    
public:
    History();
    History(Customer *c);
    virtual bool perform();
    
private:
    Customer *cust;
    
};
#endif
