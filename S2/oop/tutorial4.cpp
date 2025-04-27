#include <iostream>
#include <string>
using namespace std;

class Capital
{
private:
    string name;
    float inhabitants;

public:
    Capital(string nam = "", float inh = 0.0)
    {
        setName(nam);
        setInhabitants(inh);
    }
    ~Capital();
    void setName(string nam)
    {
        name = nam;
    }
    void setInhabitants(float inh)
    {
        inhabitants = inh;
    }
    string getName() const
    {
        return name;
    }
    float getInhabitants() const
    {
        return inhabitants;
    }
    void print() const
    {
        cout << "Name of the capital: " << name << endl;
        cout << "Number of inhabitants: " << inhabitants << endl;
    }
};
class Country
{
private:
    string name;
    float population;
    static double totalPopulation;
    double area;
    Capital capitalCity;

public:
    Country(const string &nam = "", double pop = 0.0, double are = 0.0, const Capital &cap = Capital()) : name(nam), population(pop), area(are), capitalCity(cap)
    {
        totalPopulation += population;
    }

    void setName(const string &nam)
    {
        name = nam;
    }

    void setPopulation(double pop)
    {
        totalPopulation -= population;
        population = pop;
        totalPopulation += population;
    }

    void setArea(double are)
    {
        area = are;
    }

    void setCapital(const Capital &cap)
    {
        capitalCity = cap;
    }

    string getName() const
    {
        return name;
    }

    double getPopulation() const
    {
        return population;
    }

    double getArea() const
    {
        return area;
    }

    Capital getCapital() const
    {
        return capitalCity;
    }

    static double getTotalPopulation()
    {
        return totalPopulation;
    }

    double density() const
    {
        return population / area;
    }

    void print() const
    {
        cout << "Country Name: " << name << endl;
        cout << "Population: " << population << " million" << endl;
        cout << "Area: " << area << " square kilometers" << endl;
        cout << "Capital City: " << endl;
        capitalCity.print();
    }
};

int main()
{
    Capital capital1("london", 9.54);
    Country country1("UK", 67.22, 244820, capital1);

    country1.print();
}