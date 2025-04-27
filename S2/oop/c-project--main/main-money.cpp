// main.cpp

#include <iostream>
#include "Money.h" // Include the Money class header

int main() {
    // Create Money objects
    Money m1(10, 50); // 10 dollars and 50 cents
    Money m2(5);      // 5 dollars
    Money m3;         // Default constructor (0 dollars)

    // Display the values
    std::cout << "m1: ";
    m1.output();
    std::cout << "m2: ";
    m2.output();
    std::cout << "m3: ";
    m3.output();

    // Add m1 and m2
    Money sum = add1(m1, m2);
    std::cout << "Sum of m1 and m2: ";
    sum.output();

    // Check if m1 and m2 are equal
    if (equal(m1, m2)) {
        std::cout << "m1 and m2 are equal." << std::endl;
    } else {
        std::cout << "m1 and m2 are not equal." << std::endl;
    }

    // Get the total money
    std::cout << "Total money: $" << Money::get_all_money() << std::endl;

    return 0;
}
