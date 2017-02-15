//
//  Account.cpp
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Account.h"

Account:: Account()
{
    firstName = "";
    lastName = "";
    ID = 0;
}

Account:: ~Account()
{
    
}

Account:: Account(const string &firstName, const string &lastName, const int &ID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->ID = ID;
}

Account:: Account(const int &ID)
{
    this->firstName = "";
    this->lastName = "";
    this->ID = ID;
}

string Account::getFirstName() const
{
    return firstName;
}

string Account::getLastName() const
{
    return lastName;
}

int Account::getID() const
{
    if(ID > 9999 || ID < 1000)
    {
        cerr << "ERROR: ID NEEDS TO BE A FOUR DIGIT NUMBER" << endl;
    }
    return ID;
}

Fund* Account::getFund(int index)
{
    if(index > 9)
    {
        cout << "Fund does not exist";
    }
    
    return &funds[index];
}

void Account::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void Account::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void Account::setID(const int &ID)
{
    if(ID > 9999 || ID < 1000)
    {
        cerr << "ERROR: ID NEEDS TO BE A FOUR DIGIT NUMBER" << endl;
    }
    this->ID = ID;
}

void Account::addClientHistory(const string &history)
{
    clientHistory.push_back(history);
}

vector<string> Account::getClientHistory()
{
    return clientHistory;
}

bool Account::operator==(const Account &account) const
{
    return ID == account.ID;
}

bool Account::operator!=(const Account &account) const
{
    return ID != account.ID;
}

ostream& operator<<(ostream &outStream, const Account &account)
{
    outStream << account.getFirstName() << " " << account.getLastName() << " " << account.getID();
    return outStream;
}

