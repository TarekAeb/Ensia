#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <exception>
using namespace std;

class Product {
public:
    Product(long Barcode=0, string Name="");
    void setName(string);
    void setBarcode(long);
    string getName();
    long getBarcode();
    virtual void printer();
    virtual void scanner();
private:
    long barcode;
    string name;
};

#endif
