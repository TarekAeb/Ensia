#include<iostream>
#include"SavingsAccount.h"

SavingsAccount::SavingsAccount(double s):savingsBalance(s){}
double SavingsAccount::calculateMonthlyInterest(){
    
    return savingsBalance+=(savingsBalance*annualInterestRate/12);
}
void SavingsAccount::modifyInterestRate(double a){
    annualInterestRate=a;
}