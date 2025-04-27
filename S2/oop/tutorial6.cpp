#include"tutorial6.h"
#include <string>
AltMoney::AltMoney(int d,int c){
    setAll(d,c);
}
void AltMoney::setAll(int d,int c){
    dollars=d;
    try
    {
        if (c>99)throw invalid_argument("cents contains only two digits");
        else cents=c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cents=0;
    }
}
int AltMoney::getDollars()const {
    return dollars;
}
int AltMoney::getCents()const {
    return cents;
}
AltMoney AltMoney::operator+(const AltMoney& m){
    AltMoney m3;
    m3.dollars=this->dollars+=m.dollars;
    m3.cents=this->cents+=m.cents;
    if (m3.cents>100){
        m3.cents-=100;
        m3.dollars++;
    }
    return m3;
}
AltMoney AltMoney::operator-(const AltMoney & m){
    AltMoney m1;
    if (dollars<m.dollars || dollars==m.dollars && cents<m.cents){
        cerr << "can't perform the operation";
        return AltMoney();
    }
    else {
        m1.cents=cents-m.cents;
        m1.dollars=dollars-m.dollars;
        if (m1.cents<0){
            m1.cents%100;
            m1.dollars--;
        }
    }
    return m1;
}
bool AltMoney::operator<(const AltMoney & m){
    return dollars<m.dollars|| (dollars==m.dollars && cents<m.cents);
}
bool AltMoney::operator==(const AltMoney & m){
    return dollars == m.dollars && cents == m.cents;
}
bool AltMoney::operator<=(const AltMoney & m){
    return *this<m && *this==m;
}
AltMoney & AltMoney::operator++(){ //pre incrementation
    cents++;
    return *this;
}
AltMoney AltMoney::operator++(int){ 
    AltMoney m1=*this;
    ++(*this); 
    return m1;
}
AltMoney & AltMoney::operator--(){
    cents--;
    if (cents<0){dollars--;cents+=100;}
    return *this;
}
AltMoney AltMoney::operator--(int){
    AltMoney m=*this;
    --(*this);
    return m;
}
ostream & operator<<(ostream & COUT, const AltMoney& m){
    COUT << '$'<<m.dollars<<'.'<<setfill('0')<<setw(2)<<m.cents<<endl;
    return COUT;
}
istream & operator>>(istream & CIN, AltMoney& m){
    int dollars;
    int cents;
    CIN.ignore();
    CIN>>dollars;
    CIN.ignore();
    CIN>>setw(2)>>cents;
    if (to_string(cents).size()<2){
        cents*=10;
    }
    m.setAll(dollars,cents);
    return CIN;
}
AltMoney::operator int(){
    return dollars*100+cents;
}
AltMoney::operator double(){
    return (double)cents/100+dollars;
}