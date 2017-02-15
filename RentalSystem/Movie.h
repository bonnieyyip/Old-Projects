//
//  Movie.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Parent class for different types of movies

#ifndef Movie_h
#define Movie_h

#include <stdio.h>
#include <iostream>
using namespace std;

class Movie
{
    friend ostream & operator<<(ostream &, const Movie &);
    
public:
    //Constructor/Destructor
    Movie();
    ~Movie();
    
    //Methods that the child class with override
    virtual void display() const;
    virtual bool lessThan(const Movie &) const;
    virtual bool greaterThan(const Movie &) const;
    virtual bool equalsTo(const Movie &) const;
    virtual bool notEqualsTo(const Movie &) const;
    
    //Accessors
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    
    //Mutators
    void setStock(const int &);
    void setDirector(const string &);
    void setTitle(const string &);
    
    //Overloaded operators
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    
protected:
    int stock;
    string director;
    string title;
};
#endif
