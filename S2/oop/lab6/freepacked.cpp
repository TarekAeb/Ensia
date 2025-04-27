#include "freepacked.h"
#include <iostream>

FreshFood::FreshFood(long Barcode, string name, double Weight, double Price) : Product(Barcode, name) {
    setWeight(Weight);
    setPrice(Price);
}

void FreshFood::setWeight(double Weight) {
    if (Weight >= 0)
        weight = Weight;
    else {
        weight = 0;
        cerr << "Invalid weight. Set to 0.\n";
    }
}

double FreshFood::getWeight() {
    return weight;
}

void FreshFood::setPrice(double Price) { 
    if (Price >= 0)
        price = Price;
    else
        cerr << "Invalid price. Set to 0.\n";
}

double FreshFood::getPrice() {
    return price;
}

void FreshFood::printer() {
    cout << getName() << "\nWeight: " << getWeight() << " Price: " << getPrice() << "\n";
    int n = getIntegerLength(getBarcode());
    for (int i = 0; i < n; i++) {
        cout << '|';
        if ((i + 1) % 5 == 0)
            cout << '|';
        cout << ' ';
    }
    cout << "\n";
    cout << getBarcode();
}
