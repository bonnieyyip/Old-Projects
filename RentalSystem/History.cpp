//
//  History.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "History.h"

History:: History(Customer *c)
{
    this->cust = c;
}

bool History:: perform()
{
    cust->displayTransactionHistory(cust);
    return true;
}

