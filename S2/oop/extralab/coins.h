#ifndef COINS_H
#define COINS_H
# include < iostream >
# include < cstdlib >
# include < ctime >

using namespace std;

class Coin
{
public:
    Coin();
    ~Coin();
    virtual bool toss () const = 0; // head or tails
    virtual double getValue () const = 0;
};

class coins10: public Coin
{   
public:
    coins10();
    ~coins10();
    bool toss();
    double getValue();
};

class coins20: public Coin
{
public:
    coins20();
    ~coins20();
    bool toss();
    double getValue();
};

class coins50
{
public:
    coins50(/* args */);
    ~coins50();
    bool toss();
    double getValue();
};




#endif
