#ifndef TIME_H
#define TIME_H
class Time
{
    public:
        Time();
        void setTime(int ,int ,int );
        void printUniversal();
        void printStandard();
        void tick();
    private:
        int hour,minute,second;
            
};

#endif
