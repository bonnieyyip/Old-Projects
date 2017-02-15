//
//  Classic.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Classic.h"

Classic::Classic()
{
    yearReleased = 0;
    monthReleased = 0;
    majorFirst = "";
    majorLast = "";
}
Classic::Classic(int yearReleased, int monthReleased, string majorFirst, string majorLast)
{
    this->yearReleased = yearReleased;
    this->monthReleased = monthReleased;
    this->majorFirst = majorFirst;
    this->majorLast = majorLast;
}

Classic::~Classic()
{
    
}

int Classic::getYearReleased() const
{
    return yearReleased;
}

int Classic::getMonthReleased() const
{
    return monthReleased;
}

string Classic::getMajorFirst() const
{
    return majorFirst;
}

string Classic::getMajorLast() const
{
    return majorLast;
}

void Classic::setYearReleased(const int &yearReleased)
{
    this->yearReleased = yearReleased;
}

void Classic::setMonthReleased(const int &monthReleased)
{
    this->monthReleased = monthReleased;
}

void Classic::setMajorFirst(const string &firstName)
{
    this->majorFirst = firstName;
}

void Classic::setMajorLast(const string &lastName)
{
    this->majorLast = lastName;
}

void Classic::display() const
{
    if(stock > 0)
    {
        cout << "Release Date: " << monthReleased << " " << yearReleased << ", Major Actor: " << majorFirst << " " << majorLast << ", Stock " << stock;
    }
}

bool Classic::lessThan(const Movie &rhs) const
{
    //cast Movie to Classic
    const Classic& other = static_cast<const Classic &>(rhs);
    
    if (yearReleased < other.yearReleased)
    {
        return true;
    }
    else if(yearReleased == other.yearReleased)
    {
        if(monthReleased < other.monthReleased)
        {
            return true;
        }
        else if(monthReleased == other.monthReleased)
        {
            if(majorFirst < other.majorFirst)
            {
                return true;
            }
            else if(majorFirst == other.majorFirst)
            {
                return majorLast == other.majorLast;
            }
        }
    }
    return false;
}

bool Classic::greaterThan(const Movie &rhs) const
{
    //cast Movie to Classic
    const Classic& other = static_cast<const Classic &>(rhs);
    
    if (yearReleased > other.yearReleased)
    {
        return true;
    }
    else if(yearReleased == other.yearReleased)
    {
        if(monthReleased > other.monthReleased)
        {
            return true;
        }
        else if(monthReleased == other.monthReleased)
        {
            if(majorFirst > other.majorFirst)
            {
                return true;
            }
            else if(majorFirst == other.majorFirst)
            {
                return majorLast == other.majorLast;
            }
        }
    }
    return false;
}

bool Classic::equalsTo(const Movie &rhs) const
{
    //cast Movie to Classic
    const Classic& other = static_cast<const Classic &>(rhs);
    
    return (monthReleased == other.monthReleased && yearReleased == other.yearReleased && majorFirst == other.majorFirst && majorLast == other.majorLast);
}

bool Classic::notEqualsTo(const Movie &rhs) const
{
    //cast Movie to Classic
    const Classic& other = static_cast<const Classic &>(rhs);
    
    return (monthReleased != other.monthReleased || yearReleased != other.yearReleased || majorFirst != other.majorFirst || majorLast != other.majorLast);
}
