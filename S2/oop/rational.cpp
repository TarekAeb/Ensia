#include <iostream>
#include <string>
using namespace std;
#include <stdexcept>

class rational
{
    friend ostream &operator<<(ostream &, const rational &);

private:
    int numerator, denominator;

public:
    rational(int, int);
    rational operator+(rational &);
    rational operator-(rational &);
    rational operator*(rational &);
    rational operator/(rational &);
    rational operator+=(rational &);
    rational operator-=(rational &);
    rational operator*=(rational &);
    rational operator/=(rational &);
    rational operator++();
    rational operator--();
    rational operator++(int);
    rational operator--(int);
    rational operator==(rational &);
    operator int() const;
    operator string() const;
    void setNumerator(int);
    void setDenominator(int);
    void simplify();
    int pgcd(int, int);
};

rational::rational(int const numerator = 0, int const denominator = 1)
{
    setNumerator(numerator);
    setDenominator(denominator);
    simplify();
}

void rational::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void rational::setDenominator(int denominator)  
{
    try
    {
        this->denominator = denominator != 0 ? 1 : throw invalid_argument("denominator cannot be equal to '0'");
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}
rational rational::operator+(rational &r)
{
    int num = numerator * r.denominator + r.numerator * denominator;
    int den = denominator * r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
    return *this;
}

rational rational::operator-(rational &r)
{
    int num = numerator * r.denominator - r.numerator * denominator;
    int den = denominator * r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
    return *this;
}
rational rational::operator*(rational &r)
{
    int num = numerator * r.numerator;
    int den = denominator * r.denominator;
    setNumerator(num);
    setDenominator(den);
    simplify();
    return *this;
}

rational rational::operator/(rational &r)
{
    int num = numerator * r.denominator;
    int den = denominator * r.numerator;
    setNumerator(num);
    setDenominator(den);
    simplify();
    return *this;
}
rational rational::operator*=(rational &r)
{
    this->denominator *= r.denominator;
    this->numerator *= r.numerator;
    simplify();
    return *this;
}

rational rational::operator++()
{
    this->numerator += this->denominator;
    simplify();
    return *this;
}
rational rational::operator++(int dumy)
{
    this->numerator += this->denominator;
    return *this;
}

rational rational::operator--()
{
    this->numerator -= denominator;
    simplify();
    return *this;
}
rational rational::operator+=(rational &r)
{
    this->numerator = this->numerator * r.denominator + this->denominator * r.numerator;
    this->denominator *= r.numerator;
    simplify();
    return *this;
}
ostream &operator<<(ostream &COUT, const rational &q)
{
    COUT << q.numerator << " / " << q.denominator << endl;
    return COUT;
}

void rational::simplify()
{
    int gcd = pgcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int rational::pgcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return pgcd(b, a % b);
}
rational::operator int() const
{
    return numerator / denominator;
}
rational::operator std::string() const
{
    return to_string(numerator) + to_string(denominator);
}

int main()
{
    rational fr1;
    cout << fr1;
    cout << endl;

    rational fr2(3, 8);
    cout << fr2;
    cout << endl;

    rational fr3(2, 7);
    cout << fr3;
    cout << endl;

    rational fr4(4, 2);
    cout << fr4;
    cout << endl;

    fr3 = fr1 + fr2;
    cout << fr3;
    cout << "fr3= ";
    cout << fr3;
    cout << endl;

    fr4 = fr3 / fr2;
    cout << "fr2= ";
    cout << fr3;
    cout << endl;

    fr2 = fr4 - fr1;
    cout << "fr2= ";
    cout << fr2;
    cout << endl;

    fr1 = fr4 * fr2;
    cout << "fr1= ";
    cout << fr1;
    cout << endl;

    fr3 = fr4;
    fr4 = fr4 - fr3;
    cout << "fr4= ";
    cout << fr4;
    cout << endl;

    rational fr5(0, 0);
    cout << fr5;
    rational fr6(3, 5);

    cout << fr6;

    return 0;
}