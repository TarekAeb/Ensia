#include<iostream>
#include<ctime>
#include<iomanip>
#include"date.h"
using namespace std;
date::date(){
    time_t currentTime=time(nullptr);
    struct tm* localTime=localtime(&currentTime);
    day=localTime->tm_mday;
    month=localTime->tm_mon;
    year=localTime->tm_year;
}
void date::print1(){
    cout << day<<"/"<<month<<"/"<<year<<endl;
}
void date::print2(){
    cout <<setw(2)<< day<<' '<<year;
}
void date::print3(){
    string months[12]={"January","February","March","April","May","June","July","August","september","October","November","December"};
    cout << months[month+1]<<' '<<day<<', '<<year<<endl;
}
void date::nextDay(){
    setDate(day++,month,year);
}
void date::setDate(const int d,const int m, const int y){
    if (day<1||month<1||year<1){std::cerr<<"invalid day/month or/and year";}
    else{day=d;
    month=m;
    year=y;
    if (day==31&&(month==4||month==6||month==9||month==11)||day>31){
        day=1;
        month++;
        if (month>12){
            month=1;
            year++;
        }
    }}
}