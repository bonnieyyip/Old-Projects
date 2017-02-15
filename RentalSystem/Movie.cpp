//
//  Movie.cpp
//  RentalStore
//
//  Created by Bonnie Y. Yip on 11/25/15.
//  Copyright © 2015 Bonnie Y. Yip. All rights reserved.
//

#include "Movie.h"

Movie::Movie()
{
    stock = 0;
    title = "";
    director = "";
}

Movie::~Movie()
{
    
}

void Movie::display() const
{
    cout << "Calling Movie's display() "; 
}

bool Movie::lessThan(const Movie &rhs) const
{
    return title < rhs.title;
}

bool Movie::greaterThan(const Movie &rhs) const
{
    return title > rhs.title;
}

bool Movie::equalsTo(const Movie &rhs) const
{
    return title == rhs.title;
}

bool Movie::notEqualsTo(const Movie &rhs) const
{
    return title != rhs.title;
}

int Movie::getStock() const
{
    return stock;
}

string Movie::getDirector() const
{
    return director;
}

string Movie::getTitle() const
{
    return title;
}

void Movie::setStock(const int &stock)
{
    this->stock = stock;
}

void Movie::setDirector(const string &director)
{
    this->director = director;
}

void Movie::setTitle(const string &title)
{
    this->title = title;
}

bool Movie::operator<(const Movie& rhs) const
{
    return lessThan(rhs);
}

bool Movie::operator>(const Movie& rhs) const
{
    return greaterThan(rhs);
}

bool Movie::operator==(const Movie& rhs) const
{
    return equalsTo(rhs);
}

bool Movie::operator!=(const Movie& rhs) const
{
    return notEqualsTo(rhs);
}

ostream& operator<<(ostream& output, const Movie& m)
{
    m.display();
    return output;
}