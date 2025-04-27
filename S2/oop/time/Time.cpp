#include<iostream>
#include<iomanip>
#include<stdexcept>
#include"Time.h"
#include <ctime>

using namespace std;
Time::Time(){
    time_t currentTime= time(nullptr);
    struct tm* localTime=localtime(&currentTime);
    hour=localTime->tm_hour;
    minute=localTime->tm_min;
    second=localTime->tm_sec;
}
void Time::setTime(int h,int m,int s){
    if (h<=24 && h>0 && m>0 && m<=60 &&s>0 &&s<=60){
        hour=h;
        minute=m;
        second=s;
    }else throw invalid_argument("hour, minute and/or second was out of range");
}
void Time::printStandard(){
    cout << ((hour==0 || hour==12)?12:hour%12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour<12)?"AM":"PM";
}
void Time::tick(){
    second++;
    if (second>60){
        second=0;
        minute++;
    }
    if (minute>60){
        minute=0;
        hour++;
    }
    if (hour>60){
        hour=0;
    }
}



