#include "product1.h"

Product::Product(long Barcode, string Name) {
    setName(Name);
    setBarcode(Barcode);
    scanner();
    printer();
}

void Product::setName(string Name) {
    if (Name != "") {
        name = Name;
    }
    else {
        cerr << "Invalid argument: Name must contain at least one character" << endl;
    }
}

void Product::setBarcode(long Barcode) {
    barcode = Barcode;
}

string Product::getName() {
    return name;
}

long Product::getBarcode() {
    return barcode;
}
