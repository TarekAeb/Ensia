#include"prepacked.h"
#include"freepacked.h"
int main()
{
    PrepackedFood p1(123456789, "Apple", 0.5);
    FreshFood f1(987654321, "Banana", 0.3, 0.5);
    p1.printer();
    f1.printer();
    return 0;
}