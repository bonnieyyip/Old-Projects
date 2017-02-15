//
//  Customer.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Customer.h"

Customer:: Customer()
{
    firstName = "";
    lastName = "";
    ID = 0;
}

Customer:: ~Customer()
{
    
}

Customer:: Customer(const string &firstName, const string &lastName, const int &ID)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->ID = ID;
}

Customer:: Customer(const int &ID)
{
    this->firstName = "";
    this->lastName = "";
    this->ID = ID;
}

Customer::Customer(const Customer &c)
{
    this->firstName = c.firstName;
    this->lastName = c.lastName;
    this->ID = c.ID;
}

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

int Customer::getID() const
{
    if(ID > 9999 || ID < 1000)
    {
        cerr << "ERROR: ID NEEDS TO BE A FOUR DIGIT NUMBER" << endl;
    }
    return ID;
}

void Customer::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void Customer::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void Customer::setID(const int &ID)
{
    if(ID > 9999 || ID < 1000)
    {
        cerr << "ERROR: ID NEEDS TO BE A FOUR DIGIT NUMBER" << endl;
    }
    this->ID = ID;
}

void Customer::addTransactionHistory(const string &history)
{
    transactionHistory.push_back(history);
}

vector<string> Customer::getTransactionHistory()
{
    return transactionHistory;
}

void Customer::displayTransactionHistory(Customer* pointerCust) const
{
    if(!pointerCust->getTransactionHistory().empty())
    {
        cout << "Transaction History for " << pointerCust->getFirstName() << " " << pointerCust->getLastName() << " " << pointerCust->getID() << ":" << endl;

        for (auto i = transactionHistory.begin(); i != transactionHistory.end(); ++i)
        {
            cout << *i << endl;
        }
    }
    else if (pointerCust->getTransactionHistory().empty())
    {
        cout << "No transaction history for Customer ID #" << pointerCust->getID() << endl;
    }
}

bool Customer::operator==(const Customer &c) const
{
    return ID == c.ID;
}

bool Customer::operator!=(const Customer &c) const
{
    return ID != c.ID;
}

ostream& operator<<(ostream &outStream, const Customer &c)
{
    outStream << c.getFirstName() << " " << c.getLastName() << " " << c.getID();
    return outStream;
}

