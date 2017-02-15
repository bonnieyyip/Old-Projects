//
//  Classic.h
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//
//  Child class of Movie (denoted as 'C')
//  Sorted by release date, then major actor

#ifndef Classic_h
#define Classic_h

#include <stdio.h>
#include "Movie.h"

class Classic : public Movie
{
public:
    //Constuctor/destructor
    Classic();
    Classic(int yearReleased, int monthReleased, string MajorFirst, string majorLast);
    ~Classic();
    
    //Methods that overrides the parent class
    virtual void display() const;
    virtual bool lessThan(const Movie &) const;
    virtual bool greaterThan(const Movie &) const;
    virtual bool equalsTo(const Movie &) const;
    virtual bool notEqualsTo(const Movie &) const;
    
    //Accessors
    int getYearReleased() const;
    int getMonthReleased() const;
    string getMajorFirst() const;
    string getMajorLast() const;
    
    //Mutators
    void setYearReleased(const int &);
    void setMonthReleased(const int &);
    void setMajorFirst(const string &);
    void setMajorLast(const string &);
    
private:
    int yearReleased;
    int monthReleased;
    string majorFirst;
    string majorLast;
    
};

#endif
