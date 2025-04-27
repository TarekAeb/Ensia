#include"ex3.h"
student::student(string Name,string Branch,int num,double Mark1,double Mark2,double Mark3,double Mark4,double Mark5) : name(Name),branch(Branch),roll(num)
{   
    mark.push_back(Mark1);
    mark.push_back(Mark2);
    mark.push_back(Mark3);
    mark.push_back(Mark4);
    mark.push_back(Mark5);
    print();

}
double student::getAverage()const{
    double result=0;
    for (auto a:mark)
        result+=a;
    return result/5;
}

void student::print(){
    double average= getAverage();
    if (average> 70.0)
    {
        cout << name << ' '<<average << "\n";
    }
    
}

student::~student(){
    delete this;
}