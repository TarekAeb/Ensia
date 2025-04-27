#include <iostream>
#include <iomanip>
using namespace std ;
class AltMoney {
public :
    AltMoney (int d =0 , int c =0) ;
    void setAll ( int d , int c ) ;
    int getDollars () const ;
    int getCents () const ;
    AltMoney operator+(const AltMoney&);
    AltMoney operator-(const AltMoney&);
    bool operator<(const AltMoney&);
    bool operator==(const AltMoney&);
    bool operator<=(const AltMoney&);
    AltMoney & operator++();
    AltMoney operator++(int);
    AltMoney & operator--();
    AltMoney  operator--(int );
    friend ostream & operator<<(ostream&,const AltMoney &);
    friend istream & operator>>(istream&,AltMoney &);
    operator double();
    operator int();
private :
    int dollars ;
    int cents ;
};