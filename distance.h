//
// Created by Tony Tran on 10/10/19.
//

#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using namespace std;

class Distance {
public:
    Distance(); // Default Constructor
    Distance(int f);
    Distance(int f, int i);

    // getter functions
    int getFeet(); //return feet
    int getInch(); //return inches

    // put functions
    void putFeet(int f); // set feet part of Distance
    void putInch(int i); // set inches part of distance
    int getTotalInches();

    Distance operator+(const Distance &) const; //overload add operator to work with distance
    Distance operator-(const Distance &) const;//overload subtract operator to work with distance
    Distance operator-() const; //overload negative operator to work with distance
    float operator*(const Distance &) const;//overload multiply operator to work with distance
    float operator/(const Distance &) const; //overload division operator to work with distance

    bool operator==(const Distance &); //overload equal to operator to work with distance
    bool operator!=(const Distance &); //overload not equal to operator to work with distance
    bool operator>=(const Distance &); //overload greater than or equal to operator to work with distance
    bool operator<=(const Distance &); //overload less than or equal to operator to work with distance
    bool operator>(const Distance &); //overload greater than operator to work with distance
    bool operator<(const Distance &); //overload less than operator to work with distance

    Distance operator+=(const Distance &); //overload add and equal operator to work with distance
    Distance operator-=(const Distance &); //overload subtract and equal operator to work with distance
    Distance operator=(int newDistance); //overload equals operator to work with distance

    friend ostream &operator<<(ostream &output, const Distance &); //overload console output operator to work with distance
    friend istream &operator>>(istream &input, Distance &);// //overload console input operator to work with distance

private:
    int feet;
    int inches;

    void reduce(); // reduce distance so that inches is less than 12
    // // get total inches from feet and inches in total
};

#endif //DISTANCE_H
