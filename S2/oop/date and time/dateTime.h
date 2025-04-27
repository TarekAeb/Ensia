#ifndef dateTime_H
#define dateTime_H
class dateTime
{
private:
    int second,minute,hour,day,month,year;
    int daysInmonth(int,int);
    bool isLeapYear(int)const;
public:
    dateTime(int second=0,int minute=0, int hour=0,int day=1,int month=1,int year=2006);
    ~dateTime();
    void setTime(int ,int ,int,int,int,int);
    void printUniversal();
    void printStandard();
    void tick();
    
};

#endif