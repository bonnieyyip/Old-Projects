//
//  Borrow.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Borrow.h"

Borrow::Borrow()
{
    this->m = NULL;
    this->c = NULL;
}

Borrow::Borrow(Movie *mov, Customer *cust)
{
    this->m = mov;
    this->c = cust;
}

bool Borrow::perform()
{
    if(m->getStock() < 0)
    {
        return false;
    }
    int newStock = m->getStock() - 1;
    m->setStock(newStock);
    return true;
}
