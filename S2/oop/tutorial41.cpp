#include <iostream>
#include <string>
using namespace std;
class Capital
{
private:
    string name;
    double inhabitants;

public:
    Capital(const string &capitalName = "", double capitalInhabitants = 0.0) : name(capitalName), inhabitants(capitalInhabitants) {}

    void setName(const string &capitalName)
    {
        name = capitalName;
    }

    void setInhabitants(double capitalInhabitants)
    {
        inhabitants = capitalInhabitants;
    }

    string getName() const
    {
        return name;
    }

    double getInhabitants() const
    {
        return inhabitants;
    }

    void print() const
    {
        cout << "Capital Name: " << name << endl;
        cout << "Inhabitants: " << inhabitants << " million" << endl;
    }
};

class Country
{
private:
    string name;
    double population;
    double area;
    Capital capitalCity;
    static double totalPopulation;

public:
    Country(const string &countryName = "", double countryPopulation = 0.0, double countryArea = 0.0,
            const Capital &countryCapital = Capital()) : name(countryName), population(countryPopulation), area(countryArea), capitalCity(countryCapital)
    {
        totalPopulation += population;
    }

    void setName(const string &countryName)
    {
        name = countryName;
    }

    void setPopulation(double countryPopulation)
    {
        totalPopulation -= population;
        population = countryPopulation;
        totalPopulation += population;
    }

    void setArea(double countryArea)
    {
        area = countryArea;
    }

    void setCapital(const Capital &countryCapital)
    {
        capitalCity = countryCapital;
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

double Country::totalPopulation = 0.0; // Initialize static member

int main()
{
    Capital capital("London", 9.57);
    Country country("UK", 67.22, 224820, capital);

    country.print();

    cout << "Total Population: " << Country::getTotalPopulation() << " million" << endl;

    return 0;
}

// composition: the part is depending on the whole if the whole is destructed the part will be destructed  "filled shape"
// agreviation: the part is free from the whole ""