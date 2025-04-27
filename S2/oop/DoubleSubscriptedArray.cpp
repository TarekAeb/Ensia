#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class DoubleSubscriptedArray {
public:
    DoubleSubscriptedArray(int=0, int=0);
    ~DoubleSubscriptedArray();
    int* operator()(int, int);
    bool operator==(DoubleSubscriptedArray&);
    bool operator!=(DoubleSubscriptedArray&);
    void operator=(DoubleSubscriptedArray&);
    friend ostream& operator<<(ostream&, DoubleSubscriptedArray&);
private:
    int* array;
    int i, j;
};

DoubleSubscriptedArray::DoubleSubscriptedArray(int i, int j) {
    array = new int[i * j];
    this->i = i;
    this->j = j;
    for (int n = 0; n < i * j; n++) {
        array[n] = 0;
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] array;
}

int* DoubleSubscriptedArray::operator()(int a, int b) {
    return &array[a * j + b];
}

bool DoubleSubscriptedArray::operator==(DoubleSubscriptedArray& arr) {
    if (i * j != arr.i * arr.j) {
        return false;
    }
    for (int n = 0; n < i * j; n++) {
        if (array[n] != arr.array[n]) {
            return false;
        }
    }
    return true;
}

bool DoubleSubscriptedArray::operator!=(DoubleSubscriptedArray& arr) {
    if (i * j != arr.i * arr.j) {
        return true;
    }
    for (int n = 0; n < i * j; n++) {
        if (array[n] != arr.array[n]) {
            return true;
        }
    }
    return false;
}

void DoubleSubscriptedArray::operator=(DoubleSubscriptedArray& arr) {
    if (array == arr.array) {
        return;
    }
    delete[] arr.array;
    arr.array = new int[i * j];
    for (int n = 0; n < i * j; n++) {
        arr.array[n] = arr.array[n];
    }
}

ostream& operator<<(ostream& os,DoubleSubscriptedArray& arr) {
    for (int n = 0; n < arr.i * arr.j; n++) {
        os << arr.array[n];
    }
    return os;
}