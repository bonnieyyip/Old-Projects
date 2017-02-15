//
//  Account.h
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#ifndef __JollyBanker__Account__
#define __JollyBanker__Account__

#include <stdio.h>
#include <string>
#include <iostream>
#include "Fund.h"
#include <vector>
using namespace std;

class Account{
    friend ostream& operator<<(ostream &outStream, const Account &account);
    
public:
    Account();
    Account(const string &firstName, const string &lastName, const int &ID);
    Account(const int &ID);
    ~Account();
    
    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    
    Fund* getFund(int index);
    
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setID(const int &ID);
    
    void addClientHistory(const string &history);
    vector<string> getClientHistory();
    
    bool operator==(const Account &account) const;
    bool operator!=(const Account &account) const;

private:
    string firstName;
    string lastName;
    int ID;
    Fund funds[10];
    
    vector<string> clientHistory;
};

#endif /* defined(__JollyBanker__Account__) */
