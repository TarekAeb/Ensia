#ifndef date_H
#define date_H
class date{
    public:
    date();
    void print1();
    void print2();
    void print3();
    void nextDay();
    void setDate(const int,const int,const int);
    
    private:
    int day,month,year;
    void isLeaper(int);
};
#endif