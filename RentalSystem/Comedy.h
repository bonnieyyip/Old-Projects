//
//  Comedy.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Child class of Movie (denoted as 'F')
//  Sorted by title, then year released

#ifndef Comedy_h
#define Comedy_h

#include <stdio.h>
#include "Movie.h"

class Comedy : public Movie
{
    
public:
    //Constuctor/destructor
    Comedy();
    ~Comedy();
    
    //Methods that overrides the parent class
    virtual void display() const;
    virtual bool lessThan(const Movie &) const;
    virtual bool greaterThan(const Movie &) const;
    virtual bool equalsTo(const Movie &) const;
    virtual bool notEqualsTo(const Movie &) const;
    
    //Accessors/Mutators
    int getYearReleased() const;
    void setYearReleased(const int &);
    
private:
    int yearReleased;
};

#endif
