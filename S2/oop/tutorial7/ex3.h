#ifndef STUDENT_H
#define STUDENT_H
#include<vector>
#include<iostream>
using std::string;
using std::vector;
using std::cout;
class student
{
private:
    string name, branch;
    int roll;
    vector<double> mark;
public:
    student(string ="tarek",string ="AI",int =10000,double =10,double =10,double =10,double =10,double =10);
    ~student();
    double getAverage()const;
    void print();
};


#endif