class Polynomial
{
private:
    int exponents[100];
    int coefficients[100];
    void Polynomial_combine(Polynomial &);

public:
    ~Polynomial();
    Polynomial(const Polynomial&);
    Polynomial();

    Polynomial operator+(const Polynomial &);

    Polynomial operator-(const Polynomial &);

    Polynomial operator*(const Polynomial &);

    const Polynomial operator=(const Polynomial &);
    Polynomial &operator+=(const Polynomial &);
    Polynomial &operator-=(const Polynomial &);
    Polynomial &operator*=(const Polynomial &);
    void enterTerms(void); // input terms of polynomial
    void printPolynomial(void);
};

Polynomial::Polynomial(/* args */)
{
    for (int i=0;i<100;i++)coefficients[i]=0;
    for (int i=0;i<100;i++)exponents[i]=0;

}

Polynomial::Polynomial(const Polynomial& a)
{
    for (int i=0;i<100;i++){
        exponents[i]=a.exponents[i];
        coefficients[i]=a.coefficients[i];
    }
}
Polynomial Polynomial::operator+(const Polynomial & a){
    Polynomial p(*this);
    for (int i=0;i<100;i++){
        p.coefficients[i]=this->coefficients[i]+a.coefficients[i];
    }
    return p;
}
Polynomial Polynomial::operator-(const Polynomial& a){
    Polynomial p(*this);
    for (int i=0;i<100;i++){
        p.coefficients[i]=this->coefficients[i]-a.coefficients[i];
    }
    return p;
}
Polynomial Polynomial::operator*(const Polynomial&a){
    Polynomial p(*this);
    for (int i=0;i<100;i++){
        for (int j=i;j>0;j--){
            p.coefficients[i]+=this->coefficients[i]*a.coefficients[j]+this->coefficients[j]*a.coefficients[i];
        }
    }
    return p;
}
const Polynomial Polynomial::operator=(const Polynomial &p){
    for (int i=0;i<100;i++){
        coefficients[i]=p.coefficients[i];
        exponents[i]=p.exponents[i];
    }
    return *this;
}   
