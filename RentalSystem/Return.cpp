//
//  Return.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Return.h"

Return::Return()
{
    this->m = NULL;
    this->c = NULL;
}

Return::Return(Movie *mov, Customer *cust)
{
    this->m = mov;
    this->c = cust;
}

bool Return::perform()
{
    int newStock = m->getStock() + 1;
    m->setStock(newStock);
    return true;
}
