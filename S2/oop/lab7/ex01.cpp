#include <iostream>
#include<algorithm>
#include<vector>
#include<limits>
using namespace std;
void bubblesort(vector<float>& arr){
    bool changed=true;
    while(changed){
        changed=false;
        for (int i=1;i<arr.size();i++){
            if (arr[i-1]>arr[i]){
                swap(arr[i-1],arr[i]);
                changed=true;   
            }       
        }
    }
}
int main(){
    vector<float> arr;
    cout << "Enter the number of numbers: ";
    int n;
    while(!(std::cin >> n)) {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cout << "you should enter an integer";
    }

    for (int i=0; i<n; i++){
        cout << "Enter a float number: ";
        float j;
        while(!(std::cin >> j)) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "you should enter a floating point number.";
        }
        arr.push_back(j);
    }
    bubblesort(arr);
    // sort(arr.begin(),arr.end()-1);

    for (auto it=arr.begin();it!=arr.end();it++)
        cout << *it <<"  ";

}