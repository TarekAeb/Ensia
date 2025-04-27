#include <iostream>
#include <math.h>
using namespace std;
// /*
// double distance(double , double,double,double );
// int main()
// {
// double xa,xb,ya,yb;
// cout<<"enter xA and yA"<<endl;
//     cin>> xa>> ya;
//   cout<< "enter xB and yB "<<endl;
//   cin>> xb >>yb;
//   cout<< "AB= " <<distance(xa,xb,ya,yb);
//     return 0;
// }

// double distance(double xa, double xb,double ya, double yb){
//  double result = sqrt((xa-xb)* (xa-xb) +(ya-yb)*(ya-yb));
//  return result;}
// */
// #include <string>
// #include <array>
// int nb_occ(string s,char c){
//   int occurence=0;
//   for (char w:s){
//     if (w==c){
//       occurence++;
//     }
//   }
//   return occurence;
// }
// int nb_occ (char s[],char c){
//   int occurence=0,size=sizeof(s)/sizeof(s[0]);
//   for (int i=0;i<size;i++){
//     if (s[i]==c){
//       occurence++;
//     }
//   }
//   return occurence;
// }
// int nb_occ(char * s,int size,char c){
//   int occurence;
//   for (int i=0; i<size;i++){
//     if (*(s+i)==c){
//       occurence++;
//     }
//   }
//   return occurence;
// }
// int main (){
//   string sentence="Hello bro, It has been a long time for the last time I meet you, where were you?";
//   char s[]={'h','d','f','w','e','e','d','z','t','q','a'};
//   char * S =new char[10];
//   *S='e';
//   *(S+1)='r';
//   *(S+2)='t';
//   *(S+3)='e';
//   *(S+4)='p';
//   *(S+5)='i';
//   *(S+6)='u';
//   *(S+7)='e';
//   *(S+8)='q';
//   *(S+9)='w';
//   cout << "the occurence of the char 'e' is: "<<nb_occ(s,'e');
//   cout << "the occurence of the char 'e' is: "<<nb_occ(s,'e');
//   cout << "the occurence of the char 'e' is: "<<nb_occ(S,10,'e');
//   return 0;
// }

/*
#include <iostream>
using namespace std;
bool InvOpp (int a,int b){
  if (a*b==1 || a+b==0){
    return true;
  }
  return false;
}

bool InvOpp_consecutive(int A[],int n){
  for (int i=0; i<n-1;i++){
    if (InvOpp(A[i],A[i+1]))return true;
  }
  return false;
}

bool exist_InvOOp(int A[],int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n ;j++){
      if (InvOpp(A[i],A[j]) && i!=j) return true;
    }
  }
  return false;
}

bool nbInvOpp(int A[],int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n ;j++){
      if (InvOpp(A[i],A[j]) && i<j) return true;
    }
  }
  return false;
}

int main(){
  int A[]={1,2,4,6,-1};
  cout<<"Consecutive opposite or inverse: " << InvOpp_consecutive(A,6)<<endl;
  cout <<"Exist opposite or inverse: " << exist_InvOOp(A,6)<<endl;
  cout <<"Nb opposite or inverse: " << nbInvOpp(A,6);
  return 0;
}*//*
//Test cour1 Strings 
#include<iostream>
#include<string.h>
using namespace std;
void delet1e(string &str,string &substr){
  int index=str.find(substr);
  if (index!= string::npos){
    str.erase(index,substr.size());
  }
}
int main(){
  string str="HI I am the one that you were searching for him.",subsrt="that";
  delet1e(str,subsrt);
  cout << "The string after the pass in the function is: "<<str<<endl;
}*/
/*
//Worksheet 5 Exercise 3
#
bool prime(long n){
  for( int i=2; i<n/2;i++){
    if (n%i==0){
      cout << i<<endl;
      return false;
    }
  }
  return true;
}
int main (){
  long n=1998237431;
  cout << prime(n);
}
//Worksheet 5 Exercise 13
int binary_search (int value,int a[], int first,int last){
  int mid=(first+last)/2;
  if (first<=last){
    if (a[mid]==value) return mid;
    else if (a[mid]>value) return binary_search(value,a,first,mid-1);
    else return binary_search(value,a,mid+1,last);
  }
  return -1;
}
int main(){
  int a[9]={2,3,4,5,7,12,21,29,30},value=3;
  cout << binary_search(value,a,0,8)<<endl;
}

void put (int mat[][9],int arr[9],int n){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i==j){
        arr[i]=mat[i][j];
        arr[i+n]=mat[i][n-1-j];
      } 
    }
  }
}
int main (){
  int mat[9][9]={{1,2,3,4,5,6,7,8,9},{1,2,5,6,4,3,3,6,67},{2,35,6,7,8,5,35,68,8},{2,234,56,6,7,8,5,4,43},{2,234,56,6,7,8,5,4,43},{23,245,545,78,97,34,37,56,34},{23,34,345,64,76787,57,45,34,34},{23,34,56,76,78,976,45,3,434},{24,64,7,8,3,63,3,356,46}};
  int arr[18];
  int *p1=mat[9],*p2=arr;
  put(mat,arr,9);
  for ( int i=0; i<18;i++){
    cout << arr[i]<<' ';
  }
}*/