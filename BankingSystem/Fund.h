//
//  Funds.h
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/29/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#ifndef __JollyBanker__Funds__
#define __JollyBanker__Funds__

#include <stdio.h>
#include <iostream>
using namespace std;

class Fund
{
    friend ostream& operator<<(ostream &outStream, const Fund &fund);
    
public:
    Fund();
    ~Fund();
    Fund(int balance);
    
    int getBalance() const;
    void setBalance(const int &balance);
    
private:
    int balance;
};
#endif /* defined(__JollyBanker__Funds__) */
