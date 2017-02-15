//
//  Store.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Store.h"

//Reads the first file, which fills the three types of binary trees with movies.
//Assumes that there is correct formatting, but codes may be invalid
void Store::storeMovies(string fileName1)
{
    string movieType;
    
    ifstream inFile;
    inFile.open(fileName1);
    
    if(inFile.is_open())
    {
        while(getline(inFile, movieType, ','))
        {
            //sorted by title, then year released
            if(movieType == "F")
            {
                string stringStock, director, title, stringYearReleased;
                int stock, yearReleased;
                
                inFile >> ws; //Removes extra white space
                getline(inFile, stringStock, ',');
                inFile >> ws;
                getline(inFile, director, ',');
                inFile >> ws;
                getline(inFile, title, ',');
                inFile >> ws;
                getline(inFile, stringYearReleased);
                
                stock = stoi(stringStock);
                yearReleased = stoi(stringYearReleased);
                
                Comedy* funny = new Comedy;
                funny->setStock(stock);
                funny->setDirector(director);
                funny->setTitle(title);
                funny->setYearReleased(yearReleased);
                comedyTree.insert(funny);
                
                funny = NULL;
                delete funny;
            }
            
            //sorted by director, then title
            else if(movieType == "D")
            {
                string stringStock, director, title, stringYearReleased;
                int stock, yearReleased;
                
                inFile >> ws;
                getline(inFile, stringStock, ',');
                inFile >> ws;
                getline(inFile, director, ',');
                inFile >> ws;
                getline(inFile, title, ',');
                inFile >> ws;
                getline(inFile, stringYearReleased);
                
                stock = stoi(stringStock);
                yearReleased = stoi(stringYearReleased);
                
                Drama* drama = new Drama;
                drama->setStock(stock);
                drama->setDirector(director);
                drama->setTitle(title);
                drama->setYearReleased(yearReleased);
                dramaTree.insert(drama);

                drama = NULL;
                delete drama;
            }
            
            //sorted by release date, then major actor
            else if(movieType == "C")
            {
                string stringStock, director, title, majorActorReleaseDate;
                string firstName, lastName, stringMonth, stringYear;
                int stock, month, year;
                
                inFile >> ws;
                getline(inFile, stringStock, ',');
                inFile >> ws;
                getline(inFile, director, ',');
                inFile >> ws;
                getline(inFile, title, ',');
                inFile >> ws;
                getline(inFile, majorActorReleaseDate);
                
                istringstream iss(majorActorReleaseDate);
                
                while(iss)
                {
                    iss >> firstName >> lastName >> stringMonth >> stringYear;
                }
                
                stock = stoi(stringStock);
                month = stoi(stringMonth);
                year = stoi(stringYear);
                
                Classic* classic = new Classic;
                classic->setStock(stock);
                classic->setDirector(director);
                classic->setTitle(title);
                classic->setMonthReleased(month);
                classic->setYearReleased(year);
                classic->setMajorFirst(firstName);
                classic->setMajorLast(lastName);
                classicTree.insert(classic);
                
                classic = NULL;
                delete classic;
            }
            else //ERROR case, wrong letter, so it discards the entire line, and isn't inserted into the tree
            {
                string stringContents, discardTwo, discardThree, discardFour, discardFive;
                
                getline(inFile, stringContents);
                
                istringstream iss(stringContents);
                
                while(iss)
                {
                    iss >> discardTwo >> discardThree >> discardFour >> discardFive;
                }
                cout << endl;
                cout << "Movie Type: " << movieType << " is invalid." << endl;
            }
        }
    
    }
}

//Stores customer information, including a unique ID, last name, and first name
//Assumes that files are formatted correctly
void Store::storeCustomer(string fileName2)
{
    string stringID, firstName, lastName, lineContents;
    int ID;
    
    ifstream inFile;
    inFile.open(fileName2);
    
    if(inFile.is_open())
    {
        while(getline(inFile, lineContents))
        {
            istringstream iss(lineContents);
            
            iss >> stringID >> lastName >> firstName;
            
            ID = stoi(stringID);
            
            bool exists = customerList.isInTable(ID);
            
            //If the customer doesn't already exist, insert them into the hash table
            if(!exists)
            {
                Customer *c = new Customer;
                c->setFirstName(firstName);
                c->setLastName(lastName);
                c->setID(ID);
                
                customerList.insert(ID, c);
                
                c = NULL;
                delete c;
            }
            //ERROR CASE, since ID is already in hash table
            else
            {
                cout << "ID: " << ID << " already exists" << endl;
            }
        }
        
    }
}

//void Store::processTrans(string fileName3)
//{
//    string transType;
//    
//    ifstream inFile;
//    inFile.open(fileName3);
//    
//    if(inFile.is_open())
//    {
//        while(!inFile.eof())
//        {
//            inFile >> transType;
//            
//            
//            transactions.push(transType);
//            cout << "trans" << transType[0] << endl;
//        
//        
//        string stringID, videoCode, movieType, title, year, directorName, stringReleaseMonth, stringReleaseYear, majorFirst, majorLast;
//                int ID;
//        
//            istringstream iss(lineContents);
            
//            if(transType[0] == 'B')
//            {
            
//                int releaseMonth, releaseYear;
//
//                    if(transType[9] == 'F')
//                    {
//                        getline(inFile, transType, ' ');
//                        getline(inFile, stringID, ' ');
//                        getline(inFile, videoCode, ' ');
//                        getline(inFile, movieType, ' ');
//                        getline(inFile, title, ',');
//                        inFile >> ws;
//                        getline(inFile, year);
//                        
//                        ID = atoi(stringID.c_str());
//                        
//                        Customer *pointerCustomer = customerList.retrieve(ID); //checks if ID is valid
//                        
//                        if(pointerCustomer != NULL)
//                        {
//                            Movie *pointerMovie;
//                            bool exists = comedyTree.retrieve(title, pointerMovie);
//                        
//                            if(!exists)
//                            {
//                                cout << "ERROR: Movie " << title << " not found." << endl;
//                            }
//                            
//                            trans = new Borrow(pointerMovie, pointerCustomer);
//                            trans->perform();
//                            
//                            comedyTree.display();
//                            
//                            trans = NULL;
//                            delete trans;
//                        }
//                    }
                    //currently after borrowing drama, it reads the line that comes after and says it is invalid, then continues on to next line
                    //currently needs to add extra whitespace at the end for this to work
//                    else if(movieType == "D")
//                    {
//                        getline(inFile, directorName, ',');
//                        inFile >> ws;
//                        getline(inFile, title, ',');
//                        inFile >> ws;
//                        
//                        Movie *pointerMovie;
//                        bool exists = dramaTree.retrieve(title, pointerMovie);
//                        
//                        if(!exists)
//                        {
//                            cout << "ERROR: Movie " << title << " not found." << endl;
//                        }
//                        
//                        trans = new Borrow(pointerMovie, pointerCustomer);
//                        trans->perform();
//                        
//                        dramaTree.display();
//                        
//                        trans = NULL;
//                        delete trans;
//                    }
//                    else if(movieType == "C")
//                    {
//                        string lineContents;
//                        
//                        getline(inFile, lineContents);
//                        
//                        istringstream iss(lineContents);
//                        iss >> stringReleaseMonth >> stringReleaseYear >> majorFirst >> majorLast;
//                        
//                        releaseMonth = stoi(stringReleaseMonth);
//                        releaseYear = stoi(stringReleaseYear);
//                        
//                        Classic actualMovie(releaseYear, releaseMonth, majorFirst, majorLast);
//                        Movie *pointerMovie;
//                        
//                        bool exists = classicTree.classicRetrieve(actualMovie, pointerMovie);
//                        
//                        if(!exists)
//                        {
//                            cout << "ERROR: Movie " << title << " not found." << endl;
//                        }
//                        
//                        trans = new Borrow(pointerMovie, pointerCustomer);
//                        trans->perform();
//                        
//                        classicTree.display();
//                        
//                        trans = NULL;
//                        delete trans;
//                    }
//                    else
//                    {
//                        cout << "ERROR: Invalid Movie Type " << movieType << " not allowed.";
//                        //throw exception for invalid movie type, don't crash whole system for wrong line, discard it
//                    }
//                }
//                else if(pointerCustomer == NULL)
//                {
//                    cout << "ERROR: ID " << ID << " not found. Cannot perform borrow." << endl;
//                }
//            }
        
//            else if(lineContents[0] == 'R')
//            {
//                string stringID, videoCode, movieType, title, year, directorName, stringReleaseMonth, stringReleaseYear, majorFirst, majorLast;
//                int ID, releaseMonth, releaseYear;
//                
//                getline(inFile, stringID, ' ');
//                getline(inFile, videoCode, ' ');
//                getline(inFile, movieType, ' ');
//                
//                ID = atoi(stringID.c_str());
//                
//                Customer *pointerCustomer = customerList.retrieve(ID); //checks if ID is valid
//                
//                if(pointerCustomer != NULL)
//                {
//                    if(movieType == "F")
//                    {
//                        getline(inFile, title, ',');
//                        inFile >> ws;
//                        getline(inFile, year);
//                        
//                        cout << title;
//                        
//                        Movie *pointerMovie;
//                        bool exists = comedyTree.retrieve(title, pointerMovie);
//                        
//                        if(!exists)
//                        {
//                            cout << "ERROR: Movie " << title << " not found." << endl;
//                        }
//                        
//                        trans = new Return(pointerMovie, pointerCustomer);
//                        trans->perform();
//                        
//                        comedyTree.display();
//                        
//                        trans = NULL;
//                        delete trans;
//                    }
//                    //currently after returning drama, it reads the line that comes after and says it is invalid, then continues on to next line
//                    //currently needs to add extra whitespace at the end for this to work
//                    else if(movieType == "D")
//                    {
//                        getline(inFile, directorName, ',');
//                        inFile >> ws;
//                        getline(inFile, title, ',');
//                        inFile >> ws;
//                        
//                        Movie *pointerMovie;
//                        bool exists = dramaTree.retrieve(title, pointerMovie);
//                        
//                        if(!exists)
//                        {
//                            cout << "ERROR: Movie " << title << " not found." << endl;
//                        }
//                        
//                        trans = new Return(pointerMovie, pointerCustomer);
//                        trans->perform();
//                        
//                        dramaTree.display();
//                        
//                        trans = NULL;
//                        delete trans;
//                    }
//                    else if(movieType == "C")
//                    {
//                        string lineContents;
//                        
//                        getline(inFile, lineContents);
//                        
//                        istringstream iss(lineContents);
//                        iss >> stringReleaseMonth >> stringReleaseYear >> majorFirst >> majorLast;
//                        
//                        releaseMonth = stoi(stringReleaseMonth);
//                        releaseYear = stoi(stringReleaseYear);
//                        
//                        Classic actualMovie(releaseYear, releaseMonth, majorFirst, majorLast);
//                        Movie *pointerMovie;
//                        
//                        bool exists = classicTree.classicRetrieve(actualMovie, pointerMovie);
//                        
//                        if(!exists)
//                        {
//                            cout << "ERROR: Movie " << title << " not found." << endl;
//                        }
//                        
//                        trans = new Return(pointerMovie, pointerCustomer);
//                        trans->perform();
//                        
//                        classicTree.display();
//                        
//                        trans = NULL;
//                        delete trans;
//                    }
//                    else
//                    {
//                        cout << "ERROR: Invalid Movie Type. " << movieType << " not allowed.";
//                        //throw exception for invalid movie type, don't crash whole system for wrong line, discard it
//                    }
//                }
//                else if(pointerCustomer == NULL)
//                {
//                    cout << "ERROR: ID " << ID << " not found. Cannot perform return." << endl;
//                }
//            }
//            
//            else if(lineContents[0] == 'I')
//            {
//                trans = new Inventory(&comedyTree, &dramaTree, &classicTree);
//                trans->perform();
//                
//                trans = NULL;
//                delete trans;
//            }
//            
//            else if(lineContents[0] == 'H')
//            {
//                string stringID;
//                int ID;
//                
//                getline(inFile, stringID, ' ');
//                
//                ID = stoi(stringID);
//                
//                //                Customer *pointerCustomer = customerList.retrieve(ID);
//                
//                //                trans = new History(pointerCustomer, customerList);
//                //                trans->perform();
//                
//                Customer *pointerCust = customerList.retrieve(ID);
//                
//                if (pointerCust!= NULL) //id exists
//                {
//                    vector<string> clientHistory = pointerCust->getTransactionHistory();
//                    
//                    cout << "Transaction History for " << pointerCust->getFirstName() << " " << pointerCust->getLastName() << " " << pointerCust->getID() << ":" << endl;
//                    
//                    for (auto i = clientHistory.begin(); i != clientHistory.end(); ++i)
//                    {
//                        cout << *i << endl;
//                    }
//                }
//                else
//                {
//                    cout << "No history available" << endl;
//                }
//                
//            }
//            
//            //currently works for X 5000 but not just X
//            else //throw invalid transType here
//            {
//                char next;
//                while(inFile.get(next))
//                {
//                    if (next == '\n')
//                    {
//                        break;
//                    }
//                }
//                cout << "Invalid Transaction Type " << next << endl;
//                
//                //must handle:
//                //1. invalid action code
//                //2. invalid video code
//                //3. incorrect customer ID
//                //4. invalid movie
//                //5. bad data, discard line and notify users
//            }
//        }
//
//    }
//    
//}

void Store::processTrans(string fileName3)
{
    string transType;
    
    ifstream inFile;
    inFile.open(fileName3);
    
    if(inFile.is_open())
    {
        while(getline(inFile, transType, ' '))
        {
            transactions.push(transType);
            
            //Borrow-- Subtracts 1 from the stock
            if(transType == "B")
            {
                string stringID, videoCode, movieType, title, year, directorName, stringReleaseMonth, stringReleaseYear, majorFirst, majorLast;
                int ID, releaseMonth, releaseYear;
                
                getline(inFile, stringID, ' ');
                getline(inFile, videoCode, ' ');
                getline(inFile, movieType, ' ');

                ID = atoi(stringID.c_str());
                Customer *pointerCustomer = customerList.retrieve(ID); //checks if ID is valid
                
                if(pointerCustomer != NULL) //If ID is in the hashtable, then proceed
                {
                    //Comedy
                    if(movieType == "F")
                    {
                        getline(inFile, title, ',');
                        inFile >> ws;
                        getline(inFile, year);
                        
                        //Checks if a movie exists in the tree already
                        Movie *pointerMovie;
                        bool exists = comedyTree.retrieve(title, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }

                        //if it exists, then perform the transaction
                        trans = new Borrow(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        //insert the transaction into the queue for calling transaction history
                        string line = transactions.back();
                        string insertTitle = title;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertTitle);
                        
                        //pointer no longer needed
                        trans = NULL;
                        delete trans;
                    }
                    //Drama -- currently not functioning like it's supposed to
                    else if(movieType == "D")
                    {
                        getline(inFile, directorName, ',');
                        inFile >> ws;
                        getline(inFile, title, ',');
//                        inFile >> ws;
                        
                        Movie *pointerMovie;
                        bool exists = dramaTree.retrieve(title, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }
                        
                        trans = new Borrow(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        string line = transactions.back();
                        string insertTitle = title;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertTitle);
                        
                        trans = NULL;
                        delete trans;
                    }
                    //Classic
                    else if(movieType == "C")
                    {
                        string lineContents;
                        
                        getline(inFile, lineContents);
                        
                        istringstream iss(lineContents);
                        iss >> stringReleaseMonth >> stringReleaseYear >> majorFirst >> majorLast;
                        
                        releaseMonth = stoi(stringReleaseMonth);
                        releaseYear = stoi(stringReleaseYear);

                        Classic actualMovie(releaseYear, releaseMonth, majorFirst, majorLast);
                        Movie *pointerMovie;
                        
                        bool exists = classicTree.classicRetrieve(actualMovie, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }
                        
                        trans = new Borrow(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        string line = transactions.back();
                        string insertMajorFirst = majorFirst;
                        string insertMajorLast = majorLast;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertMajorFirst);
                        pointerCustomer->addTransactionHistory(insertMajorLast);
                        
                        trans = NULL;
                        delete trans;
                    }
                    else
                    {
                        cout << "ERROR: Invalid Movie Type " << movieType << " not allowed.";
                    }
                }
                else if(pointerCustomer == NULL)
                {
                    cout << "ERROR: ID " << ID << " not found. Cannot perform borrow." << endl;
                }
            }
            
            //Return-- Adds 1 to the stock
            else if(transType == "R")
            {
                string stringID, videoCode, movieType, title, year, directorName, stringReleaseMonth, stringReleaseYear, majorFirst, majorLast;
                int ID, releaseMonth, releaseYear;
                
                getline(inFile, stringID, ' ');
                getline(inFile, videoCode, ' ');
                getline(inFile, movieType, ' ');
                
                ID = atoi(stringID.c_str());
                
                Customer *pointerCustomer = customerList.retrieve(ID); //checks if ID is valid
                
                if(pointerCustomer != NULL)
                {
                    //Comedy
                    if(movieType == "F")
                    {
                        getline(inFile, title, ',');
                        inFile >> ws;
                        getline(inFile, year);
                        
                        cout << title;
                        
                        Movie *pointerMovie;
                        bool exists = comedyTree.retrieve(title, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }
                        
                        trans = new Return(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        string line = transactions.back();
                        string insertTitle = title;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertTitle);
                        
                        trans = NULL;
                        delete trans;
                    }

                    //Drama-- not functioning like it's supposed to
                    else if(movieType == "D")
                    {
                        getline(inFile, directorName, ',');
                        inFile >> ws;
                        getline(inFile, title, ',');
//                        inFile >> ws;
                        
                        Movie *pointerMovie;
                        bool exists = dramaTree.retrieve(title, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }
                        
                        trans = new Return(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        string line = transactions.back();
                        string insertTitle = title;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertTitle);
                        
                        trans = NULL;
                        delete trans;
                    }
                    //Classic
                    else if(movieType == "C")
                    {
                        string lineContents;
                        
                        getline(inFile, lineContents);
                        
                        istringstream iss(lineContents);
                        iss >> stringReleaseMonth >> stringReleaseYear >> majorFirst >> majorLast;
                        
                        releaseMonth = stoi(stringReleaseMonth);
                        releaseYear = stoi(stringReleaseYear);
                        
                        Classic actualMovie(releaseYear, releaseMonth, majorFirst, majorLast);
                        Movie *pointerMovie;
                        
                        bool exists = classicTree.classicRetrieve(actualMovie, pointerMovie);
                        
                        if(!exists)
                        {
                            cout << "ERROR: Movie " << title << " not found." << endl;
                        }
                        
                        trans = new Return(pointerMovie, pointerCustomer);
                        trans->perform();
                        
                        string line = transactions.back();
                        string insertMajorFirst = majorFirst;
                        string insertMajorLast = majorLast;
                        pointerCustomer->addTransactionHistory(line);
                        pointerCustomer->addTransactionHistory(insertMajorFirst);
                        pointerCustomer->addTransactionHistory(insertMajorLast);
                        
                        trans = NULL;
                        delete trans;
                    }
                    else
                    {
                        cout << "ERROR: Invalid Movie Type " << movieType << " not allowed.";
                    }
                }
                else if(pointerCustomer == NULL)
                {
                    cout << "ERROR: ID " << ID << " not found. Cannot perform return." << endl;
                }
            }
            
            //currently needs extra whitespace at the end to work
            else if(transType == "I")
            {
                inFile >> ws;
                
                //prints out the movie in the order of Comedy, Drama, then Classic
                trans = new Inventory(&comedyTree, &dramaTree, &classicTree);
                trans->perform();
                
                trans = NULL;
                delete trans;
            }

            //Prints out the history of a certain customer, from earliest to latest
            else if(transType == "H")
            {
                string stringID;
                int ID;
                
                getline(inFile, stringID);
                
                ID = stoi(stringID);
                
                Customer *pointerCust = customerList.retrieve(ID);
                
                if (pointerCust!= NULL) //id does exist
                {
                    trans = new History(pointerCust);
                    trans->perform();
                    
                    trans = NULL;
                    delete trans;
                }
            }
        
            else
            {
                char next;
                while(inFile.get(next))
                {
                    if (next == '\n')
                    {
                        break;
                    }
                }
                cout << "Invalid Transaction " << endl;
            }
        }
        
    }

}