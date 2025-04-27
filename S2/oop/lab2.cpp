#include<iostream>
#include<cmath>
#include<stdexcept>
using std::cout;
using std::endl;

class date2
{
private:
    int day,month,year;
    bool validate(int,int,int);
    bool isLeapYear(int );
public:
    date2(int day=1,int month=1,int year=2000);
    ~date2();
    void setDate(int,int,int);
    void nextDay();
    void print();
};

date2::date2(int day,int month,int year)
{
    setDate(day,month,year);
}

date2::~date2()
{
}

void date2::setDate(int day,int month, int year){
    if (validate(day,month,day)){
        this->day=day;
        this->month=month;
        this->year=year;
    }
    else std::cerr << "invalid arguments!"<<endl;
}

bool date2::validate(int day,int month,int year){
    static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDay=days[month-1];
    if (month==2&& isLeapYear(year)){
        maxDay=29;
    }
    if (day<maxDay&& month<12)return true;
    return false;
}

bool date2::isLeapYear(int year){
    if(year%400==0||( year % 4 && year % 100 != 0 ))return true;
    return false;
}

void date2::nextDay(){
    day++;
    if (validate(day,month,year))return;
    day=1;
    month++;
    if (month>12){
        month=1;
        year++;
    }
}

void date2::print(){
    cout << day<<'-'<<month<<'-'<<year<<endl<<endl;
}

int main(){
    int max=40;
    
    date2 d1;
    d1.print();
    
    date2 d2(6,7,2006);
    d2.print();

    for (int i=0;i<max;i++){
        d2.nextDay();
        d2.print();
    }
    return 0;
}