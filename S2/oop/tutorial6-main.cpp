#include"tutorial6.h"

int main(){
    AltMoney m1(43,5);
    cout << "m1: "<<m1;
    AltMoney m2(24,24);
    cout << "m2: "<< m2;
    AltMoney m3(23,345);
    cout << "m3: "<< m3;
    AltMoney m4;
    cout << "m4: "<< m4;
    m4=m1+m3;
    cout << "m4: "<< m4;
    m1++;
    cout << "m1: "<< m1;
    m3--;
    cout << "m3: "<< m3;
    --m3;
    cout << "m3: "<< m3;
    cout <<"Enter a number:"<<endl;
    cin>>m4;
    cout <<m4;
    AltMoney *ptr=new AltMoney(2,3);
    cout <<ptr;
}