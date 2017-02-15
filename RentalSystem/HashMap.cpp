//
//  HashMap.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 12/13/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "HashMap.h"

HashMap::HashMap()
{
    table = new HashEntry*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}

void HashMap::insert(int ID, Customer *c)
{
    int hash = (ID % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getID() != ID)
        hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] != NULL)
        delete table[hash];
    table[hash] = new HashEntry(ID, c);
}

bool HashMap::isInTable(int ID)
{
    int hash = (ID % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getID() != ID)
        hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] == NULL)
        return false;
    else
        return true;
}

Customer* HashMap::retrieve(int ID)
{
    int hash = (ID % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getID() != ID)
        hash = (hash + 1) % TABLE_SIZE;
    if (table[hash] == NULL)
        return NULL;
    else
        return table[hash]->getCustomer();
}

void HashMap::print()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << table[i]->getCustomer();
    }
}

HashMap::~HashMap()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL)
        {
            delete table[i];
        }
    }
    delete[] table;
}
