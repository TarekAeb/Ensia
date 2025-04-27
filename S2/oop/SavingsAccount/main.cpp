#include<iostream>
#include"SavingsAccount.h"
using namespace std;
int main (){
    SavingsAccount saver1(20000.0);
    SavingsAccount saver2(3000.0);
    SavingsAccount::modifyInterestRate(0.3);
    
    cout <<"Monthly Interest for saver1: "<<saver1.calculateMonthlyInterest()<<endl;
    cout <<"Monthly Interest for saver2: "<<saver2.calculateMonthlyInterest()<<endl;

    SavingsAccount::modifyInterestRate(0.4);
    cout <<"Monthly Interest for saver1: "<<saver1.calculateMonthlyInterest()<<endl;
    cout <<"Monthly Interest for saver2: "<<saver2.calculateMonthlyInterest()<<endl;

    return 0;
}