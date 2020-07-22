#include <iostream>
using namespace std;
#include "distance.h"

int main() {

    Distance d1(-5, 30), d2(5, -31), d3(2, 5), d4(1), d5, d6;

    cout << "type two integers for d6: " << endl;
    cin >> d6;
    cout << "d1 = " << d1 << endl;

    cout << "d2 = " << d2 << endl;
    cout << "d3 = " << d3 << endl;
    cout << "d4 = " << d4 << endl;
    cout << "d5 = " << d5 << endl;
    cout << "d6 = " << d6 << endl;
    cout << "-d4 = " << -d4 << endl;
    cout << "d1 + d2 + d3 = " << d1 + d2 + d3 << endl;
    cout << "d1 - d2 - d3 = " << d1 - d2 - d3 << endl;
    cout << "Sqfeet( d1 * d2 ) = " << d1 * d2 << endl;
    cout << "Ratio ( d1 / d2 ) = " << d1 / d2 << endl;
    cout << "d1 <= d2 is " << ((d1 <= d2) ? "true" : "false") << endl;
    cout << "d2 >= d3 is " << ((d2 >= d3) ? "true" : "false") << endl;
    cout << "d3 > d4 is " << ((d3 > d4) ? "true" : "false") << endl;
    cout << "d4 < d5 is " << ((d4 < d5) ? "true" : "false") << endl;
    cout << "d1 == d1 is " << ((d1 == d1) ? "true" : "false") << endl;
    cout << "d1 != d1 is " << ((d1 != d1) ? "true" : "false") << endl;
    cout << "(d5 += d1) += d2 is " << ((d5 += d1) += d2) << endl;
    cout << "(d5 = 0 inches) is " << (d5 = 0) << endl;
    cout << "(d5 -= d1) -= d2 is " << ((d5 -= d1) -= d2) << endl;

    cout << "testing division by zero d1/d5 " << d1 / d5 << endl;
    cout << "Strings and characters are not valid and will ask for another value" << endl;
    cout << "Strings with numbers will take the first integer" << endl;
    cout << "Testing if input takes strings: " << endl;
    cin >> d6;
    cout << "d6 = " << d6 << endl;
    cout << "Testing if input takes decimals:  " << endl;
    cin >> d6;
    cout << "d6 = " << d6 << endl;
}