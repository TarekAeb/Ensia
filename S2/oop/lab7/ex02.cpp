#include <iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<string>
using namespace std;

int main (){
    vector<string> words;
    cout << "Enter the number of words: ";
    int n;
    while(!(cin >> n)) {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "you should enter an integer";
    }

    for (int i=0; i<n; i++){
        cout << "Enter a word: ";
        string j;
        cin>> j;
        words.push_back(j);
    }
    
    cout << "***********************\n";
    cout << "vector before being sorted\n";
    for (auto it=words.begin();it!=words.end();it++)
        cout << *it <<' ';

    sort(words.begin(),words.end());
    
    cout << "\n***********************\n";
    cout << "vector after being sorted\n";
    for (auto it=words.begin();it!=words.end();it++)
        cout << *it <<' ';
    
    cout << "\nwords[2]" << words[2];
    cout << "\nwords.size()" << words.size();
}