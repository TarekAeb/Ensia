#ifndef SavingsAccount_H
#define SavingsAccount_H
class SavingsAccount{
public:
    SavingsAccount(double =0);
    static double annualInterestRate;
    double calculateMonthlyInterest();
    static void modifyInterestRate(double);
private:
    double savingsBalance;

};

#endif