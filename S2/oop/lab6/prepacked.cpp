#include "prepacked.h"

PrepackedFood::PrepackedFood(long Barcode, string Name, double Unit) : Product(Barcode, Name)
{
    setUnit(Unit);
}
void PrepackedFood::setUnit(double Unit)
{
    if (Unit > 0)
    {
        unit = Unit;
    }
    else cerr << "Unit must be greater than 0" << endl;
}

double PrepackedFood::getUnit()
{
    return unit;
}

void PrepackedFood::printer()
{
    cout << getName() << "\n" << getUnit() << "\n" ;
    int n = getBarcode().length();
    for (int i = 0; i < n; i++)
    {
        cout << '|';
        if (n % 5)
            cout << '|';
        cout << ' ';
    }
    cout << "\n";
    cout << getBarcode();
}
void PrepackedFood::scanner()
{
    cout << "Enter barcode: ";
    long Barcode;
    cin >> Barcode;
    setBarcode(Barcode);
    cout << "Enter name: ";
    string Name;
    cin >> Name;
    setName(Name);
    cout << "Enter unit: ";
    double Unit;
    cin >> Unit;
    setUnit(Unit);
}