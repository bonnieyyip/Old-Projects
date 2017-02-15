//
//  Customer.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  The person that wants to perform a transaction at the store.
//  Every customer has a unique ID number, followed by their last name then their first name

#ifndef Customer_h
#define Customer_h

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Customer
{
    friend ostream& operator<<(ostream &outStream, const Customer &c);
    
public:
    //Constructors/ Destructor
    Customer();
    Customer(const string &firstName, const string &lastName, const int &ID);
    Customer(const int &ID);
    Customer(const Customer &c);
    ~Customer();

    //Mutators
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setID(const int &ID);
    void addTransactionHistory(const string &history);
    
    //Accessors
    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    void displayTransactionHistory(Customer* pointerCust) const;
    vector<string> getTransactionHistory();
    
    //Overloaded operators
    bool operator==(const Customer &c) const;
    bool operator!=(const Customer &c) const;
    
private:
    int ID;
    string firstName;
    string lastName;
    vector<string> transactionHistory; //Customer's history of returns and borrows
    
};
#endif
