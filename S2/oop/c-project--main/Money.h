// Money.h (Header file)
#ifndef MONEY_H
#define MONEY_H

class Money {
private:
    long all_cents; // Private member representing total cents
    static double all_money; // Static data member to track total money
public:
    // Constructors
    Money(long the_dollars, int the_cents);
    Money(long the_dollars);
    Money();

    // Member functions
    double get_value() const;
    void output() const;
    void input();
    friend Money add1(const Money&,const Money&);
    friend bool equal (const Money&, const Money&);

    // Static member functions
    static double get_all_money();
};

#endif // MONEY_H
