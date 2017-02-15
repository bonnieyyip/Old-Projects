//
//  Drama.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Child class of Movie (denoted as 'D')
//  Sorted by director, then title

#ifndef Drama_h
#define Drama_h

#include <stdio.h>
#include "Movie.h"

class Drama : public Movie
{
    
public:
    //Constuctor/destructor
    Drama();
    ~Drama();
    
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
