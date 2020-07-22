//
// Created by Tony Tran on 10/10/19.
//

#include "distance.h"

Distance::Distance(){ // default constructor
    feet = 0;
    inches = 0;
}

Distance::Distance(int f){ // single parameter constructor
    feet = f;
    inches = 0;
    reduce();
}

Distance::Distance(int f, int i){ // 2 parameter constructor
    feet = f;
    inches = i;
    reduce();
}

int Distance::getFeet(){ //return feet
    return feet;
}
int Distance::getInch(){ //return inches
    return inches;
}
void Distance::putFeet(int f){ // set feet part of Distance
    feet = f;
}
void Distance::putInch(int i){ // set inches part of distance
    inches = i;
}
//
Distance Distance::operator+(const Distance &d) const { //overload add operator to work with distance
    int newFeet, newInches;
    newFeet = feet + d.feet;
    newInches = inches + d.inches;
    Distance t(newFeet, newInches);
    return t;
}
Distance Distance::operator-(const Distance &d) const {//overload subtract operator to work with distance
    int newFeet, newInches;
    newFeet = feet - d.feet;
    newInches = inches - d.inches;
    Distance t(newFeet, newInches);
    return t;
}
Distance Distance::operator-() const {//overload negative operator to work with distance

    Distance d(-feet, -inches);
    return d;
}
float Distance::operator*(const Distance &d) const {//overload multiply operator to work with distance
    float newD1, newD2, sqfeet;
    newD1 = float(feet) + float(inches) / 12;
    newD2 = float(d.feet) + float(d.inches) / 12;
    sqfeet = float(newD1) * float(newD2);
    return sqfeet;
}
float Distance::operator/(const Distance &d) const {//overload division operator to work with distance
    float newD1, newD2, ratio;
    newD1 = float(feet) + float(inches) / 12;
    newD2 = float(d.feet) + float(d.inches) / 12;
    if (newD2 == 0){
        cout << "Cannot divide by zero!" << endl;
        return 0.0;
    }
    ratio = float(newD1) / float(newD2);
    return ratio;
}

bool Distance::operator==(const Distance &d){ //overload equal to operator to work with distance
    if ((feet * 12 + inches) == (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
bool Distance::operator!=(const Distance &d){ //overload not equal to operator to work with distance
    if ((feet * 12 + inches) != (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
bool Distance::operator>=(const Distance &d){ //overload greater than or equal to operator to work with distance
    if ((feet * 12 + inches) >= (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
bool Distance::operator<=(const Distance &d){//overload less than or equal to operator to work with distance
    if ((feet * 12 + inches) <= (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
bool Distance::operator>(const Distance &d){//overload greater than operator to work with distance
    if ((feet * 12 + inches) > (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
bool Distance::operator<(const Distance &d){ //overload less than operator to work with distance
    if ((feet * 12 + inches) < (d.feet * 12 + d.inches))
        return true;
    else
        return false;
}
Distance Distance::operator+=(const Distance &d){
    Distance temp((feet + d.feet), (inches + d.inches));
    return temp;
}
Distance Distance::operator-=(const Distance &d){
    Distance temp((feet - d.feet), (inches - d.inches));
    return temp;
}
Distance Distance::operator=(int newDistance){
    Distance temp(0, newDistance);
    return temp;
}
//overload console output operator to work with distance
// if inches or feet is singular change to inch or foot
ostream& operator<<(ostream& out, const Distance &d){
    if (d.feet == 1 || d.feet == -1)
        out << d.feet << " Foot ";
    else if (d.feet != 0)
        out << d.feet << " Feet ";
    if (d.inches == 1 || d.inches == 0 || d.inches == -1){
        if (d.feet != 0 && d.inches == 0)
            return out;
        out << d.inches << " Inch";
    }
    else
        out << d.inches << " Inches";
    return out;

}
istream& operator>>(istream &input, Distance &d){ //overload console input operator to work with distance
    bool isInteger = false;
    string newInput;
    while(!isInteger) {
        cout << "Enter Feet ";
        input >> newInput;
        for (int i = 0; i < newInput.length(); i++) {
            if (isdigit(newInput[i]) == false) {
                cout << "Please input integer, Doubles will convert to integers" << endl;
                break;
            } else {
                d.feet = stoi(newInput);
                isInteger = true;
            }
        }
    }
    isInteger = false;
    while(!isInteger){
        cout << "Enter Inches ";
        input >> newInput;
        for (int i = 0; i < newInput.length(); i++)
            if (isdigit(newInput[i]) == false) {
                cout << "Please input integer, Doubles will convert to integers" << endl;
                break;
            }
            else {
                d.inches = stoi(newInput);
                isInteger = true;
            }
    }
    d.reduce();
    return input;
}
//reduces distance to smallest inches and feet
// if inches is larger than or equal to 12 convert to feet else do nothing
// feet = orginal feet + inches/12
// inches mod is the remainder that is the new inches
// if feet and inches are not the same signs substract inches from feet to get same signs
void Distance::reduce(){
    if (inches >= 12){
        feet = feet + inches / 12;
        inches = inches % 12;
    }
    if (inches <= -12){
        feet = feet + inches / 12;
        inches = inches % 12;
    }
    if ( feet > 0 && inches < 0){
        feet = feet - 1;
        inches = 12 + inches;
    }
    if ( feet < 0 && inches > 0){
        feet = feet + 1;
        inches = -12 + inches;
    }
}