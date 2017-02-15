//
//  Drama.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Drama.h"

Drama::Drama()
{
    yearReleased = 0;
}

Drama::~Drama()
{
    
}

int Drama::getYearReleased() const
{
    return yearReleased;
}

void Drama::setYearReleased(const int &yearReleased)
{
    this->yearReleased = yearReleased;
}

void Drama::display() const
{
    if(stock > 0)
    {
        cout << "Director: " << director << ", Title: " << title << ", Stock:" << stock;
    }
}

bool Drama::lessThan(const Movie &rhs) const
{
    //cast Movie to Drama
    const Drama& other = static_cast<const Drama &>(rhs);
    
    if (director < other.director)
    {
        return true;
    }
    else if(director == other.director)
    {
        return title < other.title;
    }
    return false;
}

bool Drama::greaterThan(const Movie &rhs) const
{
    //cast Movie to Drama
    const Drama& other = static_cast<const Drama &>(rhs);
    
    if (director > other.director)
    {
        return true;
    }
    else if(director == other.director)
    {
        return title > other.title;
    }
    return false;
}

bool Drama::equalsTo(const Movie &rhs) const
{
    //cast Movie to Drama
    const Drama& other = static_cast<const Drama &>(rhs);
    
    return (director == other.director && title == other.title);
}

bool Drama::notEqualsTo(const Movie &rhs) const
{
    //cast Movie to Drama
    const Drama& other = static_cast<const Drama &>(rhs);
    
    return (director != other.director || title != other.title);
}