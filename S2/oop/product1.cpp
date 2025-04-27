#include "product1.h"
using namespace std;

Product::Product(long Barcode, string Name){
    setName(Name);
    setBarcode(Barcode);
    scanner();
    printer();
}
Product::setName(string Name){
    try {
        if (Name!=""){
            name=Name;
        }
        else throw invalid_argument("Name must at least contains one character");
    }
    catch(invalid_argument& e){
        cerr<<"Invalid argument"<<e.what()<<endl;
    }
}
