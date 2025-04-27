#include <iostream>
using namespace std;
class PurchasesAccount
{
private:
    double purchaseBalance;
    static double annualDiscountRate;
public:
    PurchasesAccount(double=0,double=0.2);
    ~PurchasesAccount();
    double calculateMonthlyDiscount();
    static void modifyDiscountRate(double);
    void print();
};

PurchasesAccount::PurchasesAccount(double a,double b):purchaseBalance(a)
{
    annualDiscountRate=b;
}

PurchasesAccount::~PurchasesAccount()
{
}
double PurchasesAccount::calculateMonthlyDiscount(){
    double discount=purchaseBalance*annualDiscountRate/12;
    purchaseBalance-=discount;
    return discount;
}
void PurchasesAccount::modifyDiscountRate(double n){
    annualDiscountRate=n;
}
void PurchasesAccount::print(){
    cout<<purchaseBalance<<endl;
}

int main (){
    PurchasesAccount customer1(200000,0.2);
    customer1.calculateMonthlyDiscount();
    customer1.print();

    PurchasesAccount customer2(300000,0.2);
    customer2.calculateMonthlyDiscount();
    customer2.modifyDiscountRate(0.3);
    customer2.print();
}