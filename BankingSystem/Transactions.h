//
//  BankTransactions.h
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#ifndef __JollyBanker__BankTransactions__
#define __JollyBanker__BankTransactions__
#include "Account.h"
#include "BSTree.h"

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

class Transactions{
    
public:
    void BuildTransactionList(string FileName); //read from queue
    
    bool Deposit(Account* account, int FundType, int amount);
    
    bool Withdraw(Account* account, int FundType, int amount);
    
    bool Transfer(Account* account, int FundType, Account* account2, int FundType2, int amount);
    
private:
    queue<string> transactions;
};

#endif /* defined(__JollyBanker__BankTransactions__) */
