#include<iostream>
#include<new>
using namespace std;

class product
{
private:
    string name;
    float price;
    int quantity;
public:
    product(string,float,int);
    ~product();
};

product::product(string Productname="",float num=0.0,int quant=0.0)
{
    name=Productname;
    price=num;
    quantity=quant;
}

product::~product()
{
}
class store
{
private:
    int capacity,nbproducts;
    products = new product[nbproducts];
public:
    store(int,product* product1,int );
    ~store();
};

store::store(int cap=0,product *pro,int )
{   

}

store::~store()
{
}
