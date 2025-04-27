#include <iostream>
#include<iomanip>
using namespace std;
class Complex{
public:
    Complex( double = 0.0, double = 0.0 ); 
    Complex operator+( const Complex & ) const; 
    Complex operator-( const Complex & ) const; 
    Complex operator*( const Complex & ) const; 
    bool operator==( const Complex & ) const; 
    bool operator!=( const Complex & ) const; 
    friend ostream& operator<<(ostream&,Complex&); 
    friend istream& operator>>(istream&,Complex&); 
private:
    double real; 
    double imaginary; 
};

Complex::Complex( double realPart, double imaginaryPart ): real( realPart ),imaginary( imaginaryPart ){} 

Complex Complex::operator+( const Complex &operand2 ) const{
    return Complex( real + operand2.real,imaginary + operand2.imaginary );
}

Complex Complex::operator-( const Complex &operand2 ) const{
    return Complex( real - operand2.real,    imaginary - operand2.imaginary );
} 

Complex Complex::operator*( const Complex &operand2 ) const{
    return Complex( real * operand2.real - imaginary * operand2.imaginary, real* operand2.imaginary+imaginary*operand2.real );
} 

bool Complex::operator==( const Complex &operand2 ) const{
    return ( real==operand2.real&& imaginary == operand2.imaginary );
} 
bool Complex::operator==( const Complex &operand2 ) const{
    return !(operand2==*this);
}

ostream& operator<<(ostream& COUT, Complex& z){
    COUT << '(' << z.real << ", " << z.imaginary << ')';
    return COUT;
}

istream& operator>>(istream& CIN, Complex& z){
    cin>>setw(2)>>z.real;
    cin.ignore();
    cin>>setw(2)>>z.imaginary;
    return CIN;
}