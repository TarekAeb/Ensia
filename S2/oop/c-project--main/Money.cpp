// Money.cpp (Implementation file)
#include "Money.h"
#include <iostream>
using namespace std;

// Initialize the static data member (outside the class)
double Money::all_money = 0.0;

// Constructor: Dollars and cents
Money::Money(long the_dollars, int the_cents) {
    try {
        if (to_string(the_cents).size() > 2) {
            throw invalid_argument("Number of cents not valid");
        }
    } catch (const invalid_argument& e) {
        cout << "Number of cents not valid: " << e.what() << endl;
    }
    all_cents = the_dollars * 100 + the_cents;
    Money::all_money += all_cents;
}

// Constructor: Only dollars
Money::Money(long the_dollars) {
    all_cents = the_dollars * 100;
    Money::all_money += all_cents;
}

// Default constructor
Money::Money() {
    all_cents = 0;
}

// Get the value in dollars
double Money::get_value() const {
    return static_cast<double>(all_cents) / 100;
}

// Output the money amount
void Money::output() const {
    cout << '$' << all_cents / 100 << "." << all_cents % 100 << endl;
}

// Input function to read dollars and cents
void Money::input() {
    cout << "Choose options 1 or 2:\n1 - Enter only dollars\n2 - Enter dollars and cents" << endl;
    int n;
    cin >> n;
    long dollars;
    int cents;
    if (n == 1) {
        cin >> dollars;
        all_cents = dollars * 100;
    } else if (n == 2) {
        cin >> dollars >> cents;
        all_cents = dollars * 100 + cents;
    }
}

// Static member function to get the total money
double Money::get_all_money() {
    return static_cast<double>(all_money) / 100;
}
Money add1(const Money& m1,Money& m2){
    long m3=m1.all_cents+m2.all_cents;
    return Money(m3/100,m3%100);
}
bool equal(Money& m1,Money& m2){
    return (m1.all_cents==m2.all_cents);
    
}