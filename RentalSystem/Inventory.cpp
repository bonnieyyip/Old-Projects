//
//  Inventory.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->f = NULL;
    this->d = NULL;
    this->c = NULL;
}

Inventory::Inventory(BinTree *funny, BinTree *drama, BinTree *classic)
{
    this->f = funny;
    this->d = drama;
    this->c = classic;
}

bool Inventory::perform()
{
    cout << "Comedy Movies: " << endl;
    f->display();
    cout << "Drama Movies: " << endl;
    d->display();
    cout << "Classic Movies: " << endl;
    c->display();
    return true;
}