#include <iostream>
#include <vector>
using namespace std;

// the first function will reverse the the vector passed as an argument.

vector<int> mystere(vector<int> t)
{
    int n = t.size();
    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        r[i] = t[n - 1 - i];
    }
    return r;
}
// Function that checks if a array is a palindorme
bool palindrome(vector<int>& t){
    return t==mystere(t);
}

bool palindromeIndependant(vector<int> t){
    auto it1=t.begin();
    auto it2=t.end()-1;
    while(it1<=it2){
        if (*it1!=*it2)
            return false;
        it1++;
        it2--;
    }
    return true;
}
void print(vector<int>& t){
    cout << "array={";
    for (auto a : t)
        cout << a << ",";
    cout << "}\n";
}
void check(vector<int>& t){
    print(t);
    cout <<"Palindrome function: "<< (palindrome(t) ? "yes it is a palindrome!" : "No it is not a palidrome") <<"\n";
    cout <<"PalindromeIndependent function: "<< (palindromeIndependant(t)? "yes it is a palindrome!" : "No it is not a palidrome")<<"\n\n";
}
int main (){
    vector<int> t={2,8,1,6,1,8,2};
    check(t);

    t.push_back(2);
    check(t);

    t.insert(t.begin()+2,6);
    check(t);

    t.erase(t.begin());
    check(t);
}