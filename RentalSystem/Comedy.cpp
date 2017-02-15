//
//  Comedy.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Comedy.h"

Comedy::Comedy()
{
    yearReleased = 0;
}

Comedy::~Comedy()
{
    
}

int Comedy::getYearReleased() const
{
    return yearReleased;
}

void Comedy::setYearReleased(const int &yearReleased)
{
    this->yearReleased = yearReleased;
}

void Comedy::display() const
{
    if(stock > 0)
    {
        cout << "Title: " << title << ", Year Released: " << yearReleased << ", Stock: " << stock;
    }
}

bool Comedy::lessThan(const Movie &rhs) const
{
    //cast Movie to Comedy
    const Comedy& other = static_cast<const Comedy &>(rhs);
    
    if (title < other.title)
    {
        return true;
    }
    else if(title == other.title)
    {
        return yearReleased < other.yearReleased;
    }
    return false;
}

bool Comedy::greaterThan(const Movie &rhs) const
{
    //cast Movie to Comedy
    const Comedy& other = static_cast<const Comedy &>(rhs);
    
    if (title > other.title)
    {
        return true;
    }
    else if(title == other.title)
    {
        return yearReleased > other.yearReleased;
    }
    return false;
}

bool Comedy::equalsTo(const Movie &rhs) const
{
    //cast Movie to Comedy
    const Comedy& other = static_cast<const Comedy &>(rhs);
    
    return (title == other.title && yearReleased == other.yearReleased);
}

bool Comedy::notEqualsTo(const Movie &rhs) const
{
    //cast Movie to Comedy
    const Comedy& other = static_cast<const Comedy &>(rhs);
    
    return (title != other.title || yearReleased != other.yearReleased);
}
