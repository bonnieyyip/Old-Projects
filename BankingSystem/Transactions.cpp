//
//  BankTransactions.cpp
//  JollyBanker
//
//  Created by Bonnie Y. Yip on 5/26/15.
//  Copyright (c) 2015 Bonnie Y. Yip. All rights reserved.
//


#include "Transactions.h"

void Transactions::BuildTransactionList(string FileName)
{
    ifstream inFile;
    inFile.open(FileName);
    string lineContents;
    BSTree activeAccounts;
    
    if(inFile.is_open())
    {
        while(getline(inFile, lineContents))
        {
            transactions.push(lineContents);
            
            istringstream iss(lineContents);
            
            //prints out all the transaction lines
//            while(!transactions.empty())
//            {
//                cout << transactions.front() << endl;
//                transactions.pop();
//            }
            
            //Opens a new account
            if(lineContents[0] == 'O')
            {
                string action, lastName, firstName, stringID;
                iss >> action >> lastName >> firstName >> stringID;
                
                int ID = stoi(stringID);
                
                Account* pointerAccount;
                bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                
                if(!exists)
                {
                    Account* account = new Account;
                    account->setID(ID);
                    account->setFirstName(firstName);
                    account->setLastName(lastName);
                    activeAccounts.Insert(account);
                }
                else
                {
                    cerr << "ERROR: Account " << ID << " is already open. Find a different ID." << endl;
                }
            }
            //Deposits into an account
            else if(lineContents[0] == 'D')
            {
                string action, stringID, stringAmount;
                
                iss >> action >> stringID >> stringAmount;
            
                int intFundType = stoi(stringID);
                int fundType = intFundType % 10; //last digit
                
                stringID = stringID.substr(0, 4); //gets first four digits of account
                int ID = stoi(stringID);
                
                int amount = stoi(stringAmount);
                
                Account* pointerAccount;
                bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                
                if(!exists)
                {
                    cerr << "ERROR: Account " << ID << " not found." << endl;
                }
                
                Deposit(pointerAccount, fundType, amount);
            }
            //Withdraws from an account
            else if(lineContents[0] == 'W')
            {
                string action, stringID, stringAmount;
                
                iss >> action >> stringID >> stringAmount;
                
                int intFundType = stoi(stringID);
                int fundType = intFundType % 10; //last digit
                
                stringID = stringID.substr(0, 4); //gets first four digits of account
                int ID = stoi(stringID);
                
                int amount = stoi(stringAmount);
                
                Account *pointerAccount;
                bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                
                if(!exists)
                {
                    cerr << "ERROR: Account " << ID << "not found." << endl;
                }
                
                Withdraw(pointerAccount, fundType, amount);
            }
            //Transfers between accounts
            else if(lineContents[0] == 'T')
            {
                string action, stringID, stringAmount, stringID2;
                
                iss >> action >> stringID >> stringAmount >> stringID2;
                
                //first account
                int intFundType = stoi(stringID);
                int fundType = intFundType % 10; //last digit
                
                stringID = stringID.substr(0, 4); //gets first four digits of account
                int ID = stoi(stringID);
                
                int amount = stoi(stringAmount);

                Account *pointerAccount;
                bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                
                if(!exists)
                {
                    cerr << "ERROR: Account " << ID << " not found." << endl;
                }
                
                //second account
                int intFundType2 = stoi(stringID2);
                int fundType2 = intFundType2 % 10; //last digit
                
                stringID2 = stringID2.substr(0, 4); //gets first four digits of account
                int ID2 = stoi(stringID2);
                
                Account *pointerAccount2;
                bool ret2 = activeAccounts.Retrieve(ID2, pointerAccount2);
                
                if(!ret2)
                {
                    cerr << "ERROR: Account " << ID2 << " not found." << endl;
                }
                
                Transfer(pointerAccount, fundType, pointerAccount2, fundType2, amount);
            }
            //History of an account
            else if(lineContents[0] == 'H')
            {
                int ID,fundType;
                string action, stringID;
                
                iss >> action >> stringID;
                
                //client's total history
                if(stringID.length() == 4)
                {
                    ID = stoi(stringID);
                    
                    Account* pointerAccount;
                    bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                    
                    if(exists)
                    {
                        vector<string> clientHistory = pointerAccount->getClientHistory();
                        
                        cout << "Transaction History for " << pointerAccount->getFirstName() << " " << pointerAccount->getLastName() << " " << pointerAccount->getID() << ":" << endl;
                        
                        for (auto i = clientHistory.begin(); i != clientHistory.end(); ++i)
                        {
                            cout << *i << endl;
                        }
                    }
                    else
                    {
                        cout << "No history available" << endl;
                    }
                    
                }
                //client's specific fund history
                else if(stringID.length() == 5)
                {
                    ID = stoi(stringID); //converts string to int
                    fundType = ID % 10; //last digit
                    
                    stringID = stringID.substr(0, 4); //gets first four digits of account
                    ID = stoi(stringID);
                    
                    Account *pointerAccount;
                    bool exists = activeAccounts.Retrieve(ID, pointerAccount);
                    if(exists)
                    {
                        vector<string> clientHistory = pointerAccount->getClientHistory();
                        
                        cout << "Transaction History for " << pointerAccount->getFirstName() << " " << pointerAccount->getLastName() << " " << pointerAccount->getID() << " by Fund" << fundType << ":" << endl;
                        
                        for (auto i = clientHistory.begin(); i != clientHistory.end(); ++i)
                        {
                            string stringFundHistoryNumber = i->substr(6);
                            int FundHistoryNumber = stoi(stringFundHistoryNumber);
                            if(fundType == FundHistoryNumber)
                            {
                                cout << *i << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "No history available. " << endl;
                    }
                    
                }
            }
            else
            {
                cout<< "Not an option in this bank. " << endl;
            }
        }
    }
    else
    {
        cout << "File is not open " << endl;
    }
    
    cout << "\n";
    cout << "Processing Done. Final Balances" << endl;
    //Displays all active accounts
    activeAccounts.Display();
}

bool Transactions::Deposit(Account* account, int FundType, int amount)
{
    Fund* fund = account->getFund(FundType);
    int balance = fund->getBalance() + amount;
    fund->setBalance(balance);

//    cout << "Fund" << FundType << " Balance: $" << fund->getBalance() << endl;
//    cout << "\n";
    
    string line = transactions.back();
    account->addClientHistory(line);
    return true;
}

bool Transactions::Withdraw(Account* account, int FundType, int amount)
{
    Fund* fund = account->getFund(FundType);

    int balance = fund->getBalance() - amount;;
    
    //if you subtract and it ends up being less than zero, then add back what you subtracted
    if(balance < 0) //negative balance
    {
        balance += amount;
        fund->setBalance(balance);
        cerr << "ERROR: Not enough funds to withdraw " << amount << " from Account " << account->getID() << " Fund" << FundType << endl;
    }
    else
    {
        fund->setBalance(balance);
    }
    
//    cout << "Fund" << FundType << " Balance: $" << fund->getBalance() << endl;
//    cout << "\n";
    
    string line = transactions.back();
    account->addClientHistory(line);
    return true;
}

bool Transactions::Transfer(Account* account1, int FundType1, Account* account2, int FundType2, int amount)
{
    Fund* fund1 = account1->getFund(FundType1);
    Fund* fund2 = account2->getFund(FundType2);
    
    int balanceOfFund1 = fund1->getBalance() - amount;;
    int balanceOfFund2 = fund2->getBalance() + amount;
    
    if(balanceOfFund1 < 0) //negative balance
    {
        balanceOfFund1 += amount;
        balanceOfFund2 -= amount;
        fund1->setBalance(balanceOfFund1);
        fund2->setBalance(balanceOfFund2);
        cerr << "ERROR: not enough in Fund" << FundType1 << endl;
    }
    else
    {
        fund1->setBalance(balanceOfFund1);
        fund2->setBalance(balanceOfFund2);
    }
    
//    cout << "Fund" << FundType1 << " Balance: $" << fund1->getBalance() << endl;
//    cout << "Fund" << FundType2 << " Balance: $" << fund2->getBalance() << endl;
//    cout << "\n";
    
    string line = transactions.back();
    account1->addClientHistory(line);
    account2->addClientHistory(line);
    return true;
}