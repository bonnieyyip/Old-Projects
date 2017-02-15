//
//  Store.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  The store class reads all the files and stores them in the correct spot. It assumes that
//  the file is formatted correctly with no extra lines after the last written text line.
//  However, performing borrow or return for a drama movie currently doesn't work for all drama
//  movies. Calling the Inventory also requires an extra blank space following the "I"

#ifndef Store_h
#define Store_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "Customer.h"
#include "BinTree.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "HashMap.h"
#include "HashEntry.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
#include "Inventory.h"

using namespace std;

class Store
{
    
public:
    void storeMovies(string fileName1);
    void storeCustomer(string fileName2);
    void processTrans(string fileName3);
    
private:
    HashMap customerList;
    BinTree comedyTree;
    BinTree dramaTree;
    BinTree classicTree;
    Transaction *trans;
    queue<string> transactions;
};
#endif
