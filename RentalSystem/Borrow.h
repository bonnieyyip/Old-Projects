//
//  Borrow.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Customers can borrow a movie, which subtracts 1 from the Stock number

#ifndef Borrow_h
#define Borrow_h

#include <stdio.h>
#include "Movie.h"
#include "Transaction.h"

class Borrow : public Transaction
{

public:
    Borrow();
    Borrow(Movie *mov, Customer *cust);
    virtual bool perform();
    
private:
    Movie *m;
    Customer *c;
    
};
#endif
