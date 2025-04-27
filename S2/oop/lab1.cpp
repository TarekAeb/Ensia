/*//Part 1
#include<iostream>
using std::endl;
using std::cout;

class rectangle{
    public:
    // rectangle();
    rectangle(double a=0.0,double b=0.0);
    ~rectangle(){
        cout << "this object is destroyed!"<<endl;
    }
    void setWidth(double const &);
    void setLength(double const &);
    double getWidth();
    double getLength();
    double area();
    double perimeter();
    void print();
    private:    
    double width,length;
};
// rectangle::rectangle():length(0),width(0){  
// }
rectangle::rectangle(double const w, double const l){
    setWidth(w);
    setLength(l);
}
void rectangle::setWidth(double const &w){
    width=w >=0 ? w:0;
}
void rectangle::setLength(double const &l){
    length=l >=0 ? l:0;
}
double rectangle::getWidth(){
    return width;
}
double rectangle::getLength(){
    return length;
}
void rectangle::print(){
    cout <<"the width: "<<getWidth()<<endl;
    cout <<"The length: "<<getLength()<<endl;
    cout <<"The area is: "<<area()<<endl;
    cout <<"The perimeter is: "<<perimeter()<<endl;

}
double rectangle::area(){
    return width*length;
}
double rectangle::perimeter(){
    return (width+length)*2;
}
int main (){
    //first part
    rectangle rec1;
    rec1.print();

    rec1.setWidth(4.9);
    rec1.setLength(8.2);

    rec1.print();
    
    //second Part
    rectangle rec2(3.7,8.0);
    rec2.print();
    rec2.~rectangle();

    //part three
    rectangle rect4[4];
    double i=8.9;
    for (rectangle r : rect4){
        r.setLength(i+3);
        r.setWidth(i-1);
        i/=2;
        r.print();
    }

    rectangle * rec=new rectangle(4.7,6.6);
    rec->print();
    return 0;
}*/
/*//Exercise 2

#include <iostream>
using std::cout;
using std::endl;
#include<stdexcept>
class Complex {
    public:
    Complex(double real=0.0, double imaginary=0.0);
    // default constructor
    void addition( const Complex & );
    // addition of a complex number to another
    void subtraction( const Complex & );
    // subtract a complex number from another
    void multiplication(const Complex &); // multiply a complex number by another
    void printComplex( void );
    // print a complex number
    void setComplexNumber( double ,double);
    // set the real and imaginary parts
    
    private:
        double realpart,imaginarypart;
    };

// Default Complex constructor
Complex::Complex(double real,double imaginary)
{
    setComplexNumber(real,imaginary);
}
//Definition of the member function addition
void Complex::addition( const Complex &a)
{
    double real=realpart+a.realpart;
    double imaginary=imaginarypart+a.imaginarypart;
    setComplexNumber(real,imaginary);
}
//Definition of the member function subtraction
void Complex::subtraction( const Complex &s)
{
    double real=realpart-s.realpart;
    double imaginary=imaginarypart-s.imaginarypart;
    setComplexNumber(real,imaginary);
}
//Definition of the member function multiplication
void Complex::multiplication( const Complex &m)
{
    double real=realpart*m.realpart-imaginarypart*m.imaginarypart;
    double imaginary=realpart*m.imaginarypart+m.realpart*imaginarypart;
    setComplexNumber(real,imaginary);
}
//Definition of the member function printComplex
void Complex::printComplex( )
{
    cout <<"( "<<realpart<<" , "<<imaginarypart<<" )"<<endl;
}
void Complex::setComplexNumber( double rp, double ip )
{
    realpart=rp;imaginarypart=ip;
}
// Driver to class Complex
int main()
{   
    Complex z(2.0,9.7);
    Complex w(4.2,4.0);
    
    cout <<"z = ";
    z.printComplex();
    
    cout <<"w = ";
    w.printComplex();
    
    Complex s;
    s.addition(z);
    cout <<"s = ";
    s.printComplex();

    s.multiplication(w);
    cout <<"s = ";
    s.printComplex();

    s.subtraction(z);
    cout <<"s = ";
    s.printComplex();
    
    return 0;
}*/

//Exercise 3
#include <iostream>
using std::cout;
using std::endl;
using std::invalid_argument;
#include<stdexcept>

class rational {
    private:
        int numerator, denominator;
    public:
        rational(int a=1, int b=1);
        void add(rational &);
        void subtract(rational &);
        void multiply(rational &);
        void divide(rational &);
        void printF();
        void PrintR();
        void setNumerator(int );
        void setDenominator(int );
        void simplify();
        int pgcd(int ,int);
};

rational::rational(int const numerator, int const denominator){
    setNumerator(numerator);
    setDenominator(denominator);
}

void rational::setNumerator(int numerator){
    this->numerator=numerator;
}

void rational::setDenominator(int denominator){
    this->denominator= denominator != 0?denominator : throw invalid_argument("denominator cannot be equal to '0'");
}

void rational::add(rational &r){
    int num=numerator*r.denominator+r.numerator*denominator;
    int den=denominator*r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
}

void rational::subtract(rational &r){
    int num=numerator*r.denominator-r.numerator*denominator;
    int den=denominator*r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
}

void rational::multiply(rational &r){
    int num=numerator*r.numerator;
    int den=denominator*r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
}

void rational::divide(rational &r){
    int num=numerator*r.denominator;
    int den=denominator*r.numerator;
    setNumerator(num);
    setDenominator(den);
    simplify();
}

void rational::printF(){
    cout << numerator<<" / "<<denominator<<endl;
}

void rational::PrintR(){
    cout << (double)numerator/denominator<<endl;
}

void rational::simplify(){
    int gcd=pgcd(numerator,denominator);
    numerator/=gcd;
    denominator/=gcd;
}

int rational::pgcd(int a,int b){
   if (b==0) return a;
   else return pgcd(b,a%b);
}

int main(){
    rational fr1;
    fr1.printF();
    fr1.PrintR();
    cout << endl;

    rational fr2(3,8);
    fr2.printF();
    fr2.PrintR();
    cout << endl;

    rational fr3(2,7);
    fr3.printF();
    fr3.PrintR();
    cout << endl;

    rational fr4(4,2);
    fr4.printF();
    fr4.PrintR();
    cout << endl;

    fr1.add(fr2);
    cout << "fr1= ";
    fr1.PrintR();
    cout << "fr1= ";
    fr1.printF();
    cout << endl;

    fr3.divide(fr2);
    cout << "fr3= ";
    fr3.PrintR();
    cout << "fr3= ";
    fr3.printF();
    cout << endl;

    fr4.subtract(fr1);
    cout << "fr4= ";
    fr4.PrintR();
    cout << "fr4= ";
    fr4.printF();
    cout << endl;   

    fr4.multiply(fr2);
    cout << "fr4= ";
    fr4.PrintR();
    cout << "fr4= ";
    fr4.printF();
    cout << endl;

    fr3=fr4;
    fr4.subtract(fr3);
    cout << "fr4= ";
    fr4.PrintR();
    cout << "fr4= ";
    fr4.printF();
    cout << endl;
    return 0;   
}