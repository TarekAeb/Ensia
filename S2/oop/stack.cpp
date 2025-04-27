#include<iostream>
#include<stdexcept>
#include<iomanip>
using namespace std;
class stack
{
private:
    static const int size=20;
    int stk[size];
    int top;
public:
    stack();
    ~stack();
    void pop();
    void push(int);
    int peek();
    bool isEmpty();
    void print();
};


stack::stack()
{
    for (int i=0;i<size;i++){
        stk[i]=0;
    }
    top =0;
}

stack::~stack()
{
}
void stack::push(int n){
   stk[top] =n;
   top++;
}
void stack::pop(){
    if (top>0){
        top--;
    }
}
bool stack::isEmpty(){
    if (top==0){
        return true;
    }
    return false;
}
int stack::peek(){
    if (top>0){
        return stk[top-1];
    }
    try{
        throw 'a';
    }
    
    catch(...){

        cout << "stack is empty"<<endl;
    }
    return -1;
}
void stack::print(){
    cout << "the stack:"<<endl;
    for (int i=0;i<top;i++){
        cout <<'|'<< setw(2)<<stk[i]<<'|';
        cout << endl;
    }
    cout <<"___";
    cout << endl;
}

int main(){
    stack s;
    s.push(5);
    s.push(8);
    s.push(-2);
    s.print();
    s.push(9);
    s.push(0);
    s.print();
    s.pop();
    s.peek();

    stack l;
    l.peek();
}