#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Person{
private:
    string name;
public:
    Person(string ="tarek");
    string getName();
};

Person::Person(string na): name(na){

}
string Person::getName(){
    return name;
}
int main(){

    Person* p1 = new Person("Alice");
    Person* p2 = new Person("Bob");
    Person* p3 = new Person("Charlie");
    Person* p4 = new Person("Alice"); // Duplicate name
    Person* p5 = new Person("Eve");
    Person* p6 = new Person("Dave");

    vector<string> p;

    p.push_back(p1->getName());
    p.push_back(p2->getName());
    p.push_back(p3->getName());
    p.push_back(p4->getName());
    p.push_back(p5->getName());
    p.push_back(p6->getName());

    sort(p.begin(),p.end());

    for (auto a : p)
        cout << a << "\n";
}
