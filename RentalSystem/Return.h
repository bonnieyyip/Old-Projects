//
//  Return.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Customers can return a movie, which adds 1 to the Stock number

#ifndef Return_h
#define Return_h

#include <stdio.h>
#include "Movie.h"
#include "Transaction.h"

class Return : public Transaction
{
    
public:
    Return();
    Return(Movie *mov, Customer *cust);
    virtual bool perform();
    
private:
    Movie *m;
    Customer *c;
};

#endif