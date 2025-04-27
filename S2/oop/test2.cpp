#include<iostream>
#include<string>
using namespace std;
class Animal{
private: 
    static double monthly_cons,daily_cons,cons;
    string name;
    double weight,consumption;
public:
    Animal(string ="animal",double =0.0,double =0.0);
    void setAll(string ,double,double);
    void getAll(string &,double &,double &);
    void print();
    static double monthlyCals();
    static double dailyCals();
    static double avgAnimalCons();
};

Animal::Animal(string nam,double consump,double weight){
    setAll(nam,consump,weight);
}

void Animal::setAll(string name,double consumption,double weight){
    this->name=(!name.empty())?name:throw invalid_argument("argument do not much");
}

void Animal::getAll(string & name,double & cons,double & weight){
    name=this->name;
    cons=this->consumption;
    weight=this->weight;
}
void print(){

}

double Animal::monthlyCals(){
    return monthlyCals;
}
