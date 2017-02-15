//
//  main.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  This class creates a rental store and reads in three different files that first initializes
//  the movies into a tree, then initializes the customers into a hash table, then processes the
//  transactions based on certain movie and customer data

#include <iostream>
#include "BinTree.h"
#include "Store.h"

int main()
{
    Store rentalStore;
    rentalStore.storeMovies("/Users/bonnie/Desktop/data4movies.txt");
    rentalStore.storeCustomer("/Users/bonnie/Desktop/data4customers.txt");
    rentalStore.processTrans("/Users/bonnie/Desktop/data4commands.txt");
    return 0;
}
