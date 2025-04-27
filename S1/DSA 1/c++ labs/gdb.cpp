#include<iostream>
using namespace std;
int main(){
    int x=12;
    int* ptr = &x;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr<< endl;
    *ptr = 99;
    cout << "New value of x: " << x << endl;
    return 0;
}
