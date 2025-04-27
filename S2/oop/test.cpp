#include<iostream>
#include<string>
#include <ostream>

using namespace std;

class Food {
private:    
    string type;
    double calories;
public:
    Food(string,double);
    ~Food();
    void setAll(string,double);
    void getAll(string &,double &);
    void print();
    friend ostream & operator<<(ostream&, const Food&);
    
};

Food::Food(string typ,double cal){
    setAll(typ,cal);
}
void Food::setAll(string _type, double _calories){
    type= (!type.empty())?_type:throw invalid_argument("Type do not much!");
    calories=(_calories>0)?_calories:throw invalid_argument("Type do not much!");
}
void Food::getAll(string &typ,double & cal){
    typ=type;
    cal=calories;
}
void Food::print(){
    cout << "Type:" << type<<endl<<"Calories"<<calories<<endl;
}
ostream & operator<<(ostream & COUT,const Food& obj){
    COUT << "Type:" << obj.type<<endl<<"Calories"<<obj.calories<<endl;
    return COUT;
}
