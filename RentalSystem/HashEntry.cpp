//
//  HashEntry.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "HashEntry.h"

HashEntry::HashEntry(int ID, Customer *c)
{
    this->ID = ID;
    this->c = c;
}

int HashEntry::getID()
{
    return ID;
}

Customer* HashEntry::getCustomer()
{
    return c;
}