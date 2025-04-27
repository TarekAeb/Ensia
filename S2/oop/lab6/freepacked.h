#ifndef Freepacked_H
#define Freepacked_H
#include "product1.h"
class FreshFood : public Product {
public:
    FreshFood(long =0,string ="",double= 0.0,long= 0);
    void setWeight(double);
    void setPrice(double);
    double getWeight();
    double getPrice();
    void printer();
    void scanner();
private:
    double weight;
    double price;
};
#endif