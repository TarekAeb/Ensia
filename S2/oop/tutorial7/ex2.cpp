#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool containDigit(string s){
    for (char c : s){
        if (isdigit(c))return true;
    }
    return false;
}

vector<string> function(vector<string> w){
    vector<string> s;
    for (auto u : w)
        if (containDigit(u)) 
            s.push_back(u);
    return s;
}

void print(vector<string> s){
    cout << "{";
    for (auto a : s)
        cout << a << ", ";
    cout << "}\n";
}

int main (){
    vector<string> words={"red" ,"green23", "1black", "white"};
    words=function(words);
    print(words);
}