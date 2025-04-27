#include<iostream>
#include<fstream>
using namespace std;
ofstream Outfile("hi.txt", ios::out);
ifstream Inputfile("client.txt",ios::in);
int main (){
// if (!Outfile){
//     cerr<< "Error happens no file detected"<<endl;
//     exit(1);
// }
if (!Inputfile){
    cerr<< "Error happens no file detected"<<endl;
    exit(1);
}

int account, balance;
while (Inputfile >> account>>balance){
    
    cout << account << ' '<< balance<<endl;
}
return 0;
}