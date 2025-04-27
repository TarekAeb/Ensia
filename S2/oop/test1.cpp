#include<iostream>
#include<unordered_map>

using namespace std;

int romanToInt(string s) {
int ans=0;
unordered_map<int,char> m;
m[1]='I';
m[5]='V';
m[10]='X';
m[50]='L';
m[100]='C';
m[500]='D';
m[1000]='M';
for (int i=0; i<s.length();i++){
if (m[s[i]]<m[s[i+1]]){
ans-= m[s[i]];
}
else {
ans+=m[s[i]];
}
}
// ans+=m[s[s.length()-2]];
return ans;
}
int main(){
string s="MCMXCIV";
cout<<romanToInt(s);
}