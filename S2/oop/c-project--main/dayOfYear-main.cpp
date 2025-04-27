#include<iostream>
#include"dayOfYear.h"
using namespace std;

int main (){
    DayOfYear d1(3,4);
    d1.output();
    
    DayOfYear d2;
    d2.output();

    DayOfYear d3(6,4);
    d3.output();
    
    DayOfYear d4(1,8);
    if(d4.isbefore(d3)) cout <<"Yes it is before";
    else cout <<"No, it isn't before";
    cout << endl;
    return 0;
}
