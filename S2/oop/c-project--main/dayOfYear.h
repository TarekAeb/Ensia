#ifndef DayOfYear_H
#define DayOfYear_H

class DayOfYear
{
public :
    DayOfYear (int the_month , int the_day ) ; // Initializes the date
    DayOfYear () ; // Initializes the date to January first .
    void input () ; // get the date from the user .
    void output () ; // display the date .
    int get_month () ; // Returns the month , 1 for January , 2 for February , etc.
    int get_day () ; // Returns the day of the month .
    friend bool check(const DayOfYear&,const DayOfYear&);
    bool isbefore(DayOfYear)const;

private :
    bool check_date (int, int) ;
    int month ;
    int day ;   
};
#endif 
