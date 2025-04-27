#include<iostream>
#include"dateTime.h"
#include<stdexcept>
#include<iomanip>
using namespace std;
dateTime::dateTime(int second,int minute,int hour,int day,int month,int year){
    setTime(second,minute,hour,day,month,year);
}
void dateTime::setTime(int second,int minute,int hour,int day,int month,int year ){
    int maxDay=daysInmonth(month,year);
    if (second<60 && minute <60 && hour <24 && day <maxDay && month<12){
            this->second=second;
            this->month=month;
            this->hour=hour;
            this->day=day;
            this->month=month;
            this->year=year;
        }
        else throw invalid_argument("second/minute/hour/day/month and/or year out of range");
}
int dateTime::daysInmonth(int month,int year){
    static const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
            return 29;
        }
}
bool dateTime::isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void dateTime::printStandard(){
    cout <<day<<"/"<<month<<"/"<<year<<"  "<<((hour==0||hour==12)?12:hour%12) <<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<((hour<12)?"AM":"PM")<<endl;
}
void dateTime::printUniversal(){
    cout <<day<<"/"<<month<<"/"<<year<<"  "<<hour<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<endl;
}
void dateTime::tick(){
    int maxDay=daysInmonth(month,year);
    second++;
    if (second>60){
        second=0;
        minute++;
        if (minute>60){
            minute=0;
            hour++;
            if (hour>24){
                hour=0;
                day++;
                if (day>maxDay){
                    day=1;
                    month++;
                    if (month>12){
                        month=1;
                        year++;
                    }
                }
            }
        }
    }
}