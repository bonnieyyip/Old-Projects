//
//  Funds.cpp
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/29/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Fund.h"

Fund::Fund()
{
    this->balance = 0;
}

Fund::~Fund()
{
    
}

Fund::Fund(int balance)
{
    this->balance = balance;
}

int Fund::getBalance() const
{
    return this->balance;
}

void Fund::setBalance(const int &balance)
{
    this->balance = balance;
}

ostream& operator<<(ostream &outStream, const Fund &fund)
{
    outStream << fund.getBalance();
    return outStream;
}