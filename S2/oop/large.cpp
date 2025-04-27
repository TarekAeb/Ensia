#include<iostream>

using namespace std;
class Integer{
    private:
    int num[40];
    int m;

    public:
    Integer(long long n=0);
    void input(long long);
    void output();
    void add(Integer);
    void substract(Integer);
    bool isEqual(Integer);
    bool isGreaterThan(Integer);
    bool isLessThan(Integer);
    bool isLessThanOrEqual(Integer);
    bool isGreaterThanOrEqual(Integer);
};
Integer::Integer(long long n){
    input(n);
}
void Integer::input(long long n){
    int i=0;
    while(n!=0){
        num[39-i]=n%10;
        n/=10;
        m=i;
        i++;
    }
}
void Integer::output(){
    for (int i=m;i<40;i++){
        cout << num[i];
    }
    cout <<endl;
}
void Integer::add(Integer n){
    for (int i=39;i>=min(this->m,n.m);i--){
        this->num[i]+=n.num[i];
        if (num[i]>10){
            num[i]=num[i]%10;
            num[i-1]++;
        }
    }
}
void Integer::substract(Integer n){
    for (int i=39;i>min(this->m,n.m);i++){
        this->num[i]-=n.num[i];
        if (num[i]<0){
            num[i]+=10;
            num[i-1]--;
        }
    }
}
bool Integer::isEqual(Integer n){
    if (this->m!=n.m)return false;
    for (int i=39;i>=m;i--){
        if (num[i]!=num[i+1])return false;
    }
    return true;
}
bool Integer::isGreaterThan(Integer n){
    if (m<n.m)return false;
    for (int i=max(m,n.m);i<40;i++){
        if (num[i]<num[i+1])return false;
    }
    return true;
}
bool Integer::isLessThan(Integer n){
    if (m>n.m)return false;
    for (int i=max(m,n.m);i<40;i++){
        if (num[i]>num[i+1])return false;
    }
    return true;   
}
bool Integer::isGreaterThanOrEqual(Integer n){
    if (isEqual(n)&&isGreaterThan(n)){
        return true;
    }
    return false;
}
bool Integer::isLessThanOrEqual(Integer n){
    if (isEqual(n)&&isLessThan(n)){
        return true;
    }
    return false;
}
int main (){
    Integer n1(123);
    Integer n2(111111111);
    Integer n3(100000);
    Integer n4;

    n4.add(n1);
    n4.output();

    n3.substract(n2);
    n3.output();

    n1.add(n3);
    n1.output();

}