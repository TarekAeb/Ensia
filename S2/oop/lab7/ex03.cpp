#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main (){
    vector<int> list={1,244,8,9,332,12,342,4,8,9};
    auto it1=list.begin();
    auto it2=list.end()-1;
    while (it2>=it1)
    {
        swap(*it1,*it2);
        it1++;
        it2--;
    }
    for (auto i: list)
    cout <<i<<' ';
    list.reverse();
    
}