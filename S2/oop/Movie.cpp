#include<iostream>
#include<string>
using namespace std;

class Movie
{
private:
    string name,MPAA;
    int numberRating,terrible,bad,ok,good,great;

public:
    Movie();
    ~Movie();
    void AddRating(int);
    void SetNAme(string);
    void SetMpaa(string);
    string GetName();
    string GetMpaa();
    float GetAverge();
};

Movie::Movie(/* args */)
{
}

Movie::~Movie()
{
}

void Movie::AddRating(int rating){
    switch (rating)
    {
    case 1:
        terrible++;
        break;
    case 2:
        bad++;
    case 3:
        ok++;
    case 4:
        good++;
    case 5:
        great++;
    default:
        break;
    }
    numberRating++;
}
void Movie::SetMpaa(string m){
    MPAA=m;
}
void Movie::SetNAme(string name){
    this->name=name;
}
string Movie::GetMpaa(){
    return MPAA;
}
string Movie::GetName(){
    return name;
}

void Movie::AddRating(int n){
    switch (n)
    {
    case 1:
        terrible++;
        break;
    case 2:
        bad++;
        break;
    case 3:
        ok++;
        break;
    case 4:
        good++;
        break;
    case 5:
        great++;
        break;
    default:
        break;
    }
}
float Movie::GetAverge(){
    return(numberRating!=0? (float)(terrible+2*bad+3*ok+4*good+5*great)/numberRating :throw ("devision by zero"));
}