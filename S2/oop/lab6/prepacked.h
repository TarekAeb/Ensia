#ifndef Prepacked_H
#define Prepacked_H

#include"product1.h"

class PrepackedFood : public Product {
public:
    PrepackedFood(long Barcode=0,string Name="",double unit=0.0);
    void setUnit(double);
    double getUnit();
    void printer();
    void scanner();
private:
    double unit;
};
#endif 