#include"dayOfYear.h"
#include<iostream>
using namespace std;
DayOfYear::DayOfYear (int the_month , int the_day ) {
    if (check_date(the_month,the_day)){
        month=the_month;
        day=the_day;
    }
    else {month=1;
    day=1;}
}
DayOfYear::DayOfYear () {
    month=1;
    day=1;
}
int DayOfYear::get_month(){
    return month;
}
int DayOfYear::get_day(){
    return day;
}
bool  DayOfYear::check_date(int the_month , int the_day){
    if (the_month >12|the_day>31)return false;
    static const int days_of_months[13]={0,31,28,30,31,30,31,30,31,31,30,31,31};
    if (the_day>days_of_months[the_month])return false;
    return true;
}

void DayOfYear::output(){
    cout << month<<'-'<<day<<endl;
}
bool check(const DayOfYear& d1,const DayOfYear &d2){
    return d1.month>d2.month||d1.month==d2.month && d1.day>d2.day;
}
void DayOfYear::input(){
    cin>>month;
    cin>>day;
}
bool DayOfYear::isbefore(DayOfYear d) const{
    return month<d.month||month==d.month && day<d.day;
}