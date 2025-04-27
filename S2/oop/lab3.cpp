#include<iostream>
using namespace std;
//Exercise 3
/*
class Point {
public:
    Point (int abs=0, int ord=0) {
        x=abs; y=ord;
    }
    friend void display(Point&);
private:
    int x,y;
};

void display(Point& a){
    cout << "(x,y)= ("<<a.x<<','<<a.y<<')'<<endl;
}

int main (){
    Point A;
    display(A);

    Point B(2,6) ;
    display(B);
    return 0;
}*/
/*
//Exercise 04
class rational {
private:
    int numerator, denominator;
public:
    rational(int n=1,int d=1):numerator(n),denominator(d){}
    rational getnumerator()const{return numerator;}
    rational getDenumerator()const{return denominator;}
    void setNumerator(int a){numerator=a;}
    void setDenominator(int b){
        if (b!=0)denominator=b;
    }

};
class Point {
public:
    Point(int n1=1,int d1=1,int n2=1,int d2=1){
        x=rational(n1,n2);
        y=rational(n2,d2);
    }
    void set(int,int,int,int);
    const rational& getX() const{return x;}
    const rational& getY()const {return y;}
private:
    rational x,y;
};

void Point::set(int n1=1,int d1=1,int n2=1,int d2=1){
    x.setNumerator(n1);
    x.setDenominator(n2);
}

class segment {
private:
    Point A,B;
    void get(){}
public:
    segment (Point a,Point b):A(a),B(b){}
    double dimention ();
};
*/
//Exercise 4:
class IntegerSet{
public:
    IntegerSet(){
        for (int i=0;i<=100;i++){
            set[i]=0;
        }
    }
    friend int* unionOfSets(IntegerSet,IntegerSet);
    friend int* intersectionOfSets(IntegerSet,IntegerSet);
    void insertElement(int);
    void deleteElement(int);
    void inputSet();
    friend void printSet(IntegerSet);
    bool isEqualTo(IntegerSet);
private:
int set [101];
};

int* unionOfSets(IntegerSet a,IntegerSet b){
    int *arr=new int[101];
    for (int i=0;i<101;i++){
        if(a.set[i]==1 || b.set[i]==1){
            *(arr+i)=1;
        }
    }
    return arr;
}
int* intersectionOfSets(IntegerSet a,IntegerSet b){
    int *arr=new int[101];
    for (int i=0;i<101;i++){
        if(a.set[i]==1 && b.set[i]==1){
            *(arr+i)=1;
        }
    }
    return arr;
}
void IntegerSet::insertElement(int a){
    set[a]=1;
}
void IntegerSet::deleteElement(int a){
    set[a]=0;
}
void IntegerSet::inputSet(){
    cout <<"To use this method follow this guide:\n1 to enter the number\n2 to exit the function"<<endl;
    int n;
    do{
        cout <<"Enter you choice: ";
        cin >>n;
        cout <<"which number you want to insert: ";
        int j;
        cin >>j;
        if (j<=100 && j>=0)set[n]=j;
        else cout <<"Enter a number between 0 and 100 try another time"<<endl;
    }while(n==1);

}
void printSet(IntegerSet a){
    int n=0;
    for (int i=0;i<=100;i++){
        if (a.set[i]){
            cout<<i<<' ';
            n++;
        }
    }
    if (n==0)cout <<"---";
    cout<<endl;
}
void printArray(int* a){
    int n=0;
    for (int i=0;i<=100;i++){
        if (a[i]){
            cout<<i<<' ';
            n++;
        }
    }
    if (n==0)cout <<"---";
    cout<<endl;
}
bool IntegerSet::isEqualTo(IntegerSet a){
    for (int i=0;i<=100;i++){
        if (a.set[i]!=this->set[i]){
            return false;
        }
    }
    return true;
}
int main(){
    IntegerSet A;
    IntegerSet B;
    IntegerSet C;

    
    A.insertElement(6);
    A.inputSet();
    printSet(A);

    B.inputSet();
    B.deleteElement(7);
    printSet(B);

    C.inputSet();
    printSet(C);

    int* D=new int[101];
    D=unionOfSets(A,B);
    printArray(D);

    D=intersectionOfSets(B,C);
    printArray(D);
    return 0;
}