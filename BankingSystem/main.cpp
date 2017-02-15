//
//  main.cpp
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#include <iostream>
#include "Transactions.h"

int main(int argc, const char * argv[]) {
    //reads in list, executes transactions, and displays active accounts
    Transactions jollyBank;
    jollyBank.BuildTransactionList("/Users/bonnie/Desktop/BankTransIn.txt");
    return 0;
}
