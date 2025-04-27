#include <iostream>
#include <iomanip>
using namespace std;
/*LAB 3
//EXERCISE 2
int main()
{float length,width,perimeter;
    cout << "enter the length and width of the rectangle" << endl;
    cin>>length>>width;
    perimeter=(length+width)*2;
    cout << "the perimeter is "<< perimeter;
    return 0;
}
//EXERCISE 3
int main()
{
    const float pi=3.14;
    double r, area, circumference;
    cout << "enter the radius of a circle " << endl;
    cin>> r;
    area=r*r*pi;
    circumference =2*r*pi;
    cout<< "the area is ="<<area<< "the circumenference is "<< circumference;
    return 0;
}
//EXERCISE 4
int main()
{
    const int l=10,d=10,h=10;
    cout << "the volume of cube is" <<l*d*h << endl;
    return 0;
}
//EXERCISE 5
int main()
{
    int days,d,y,w;
    float days1,weeks,years;
    cout<<"enter a number of days";
    cin>> days;
    years=days/365;
    weeks=days%365/7;
    days1=days%365%7;
d=int (days1);
y=int (years);
w=int (weeks);
    cout <<"years: "<<years<<" weeks: "<<weeks<<" days: "<<days1  << endl;
    return 0;
}
//EXERCISE 6
int main()
{
    int n;
    cout << "enter a number n" << endl;
    cin>> n;
    cout<< "n^10= "<< n * n * n * n * n * n * n * n * n * n;
    return 0;
}
//EXERCISE 7
int main()
{
    cout << sizeof(bool) << endl;
        cout << sizeof( char) << endl;
            cout << sizeof(short) << endl;

                cout << sizeof(int) << endl;

                  cout << sizeof(long) << endl;

                        cout << sizeof(float) << endl;

                            cout << sizeof( double)<< endl;



    return 0;
}
//EXERCISE 8
int main()
{      float a,b;
    cout << "This program compare between two numbers" << endl;
    cout << " please enter a number 'a'";
    cin>> a;
    cout<< "please enter a number 'b' ";
    cin >>b;
    if ( a<=b){cout<< "the maximum of the two values is "<<b;  }
    else{cout<< "the maximum of the two values is "<<a; }
    return 0;
}
//EXERCISE 9
int test(int x, int y)
        {if (x == 30 || x+y==30){
            return true; }
            else{return false;}
        }


int main()
 {
  cout << test(30, 0) << endl;
  cout << test(25, 5) << endl;
  cout << test(20, 30) << endl;
  cout << test(20, 25) << endl;

  return 0;
}
//EXERCISE 10
int main()
{
    int A;
    cout<<"enter two digits "<<endl;
    cin>>A;
    if(A %2 ==0){
        cout<<A<<" is even"<<endl;
        }else{
            cout<<A<<" is odd";
        }

    cout << "Hello world!" << endl;
    return 0;
}
//EXERCISE 11
#include <cmath>
int main()
{
    int x;
    cout << "enter the value of x " << endl;
    cin>> x;
    cout<< "the absolute value of x= "<< abs(x) <<endl;
    cout<< "the expential of x= " <<exp(x) <<endl;
    cout<< "the root of x= "<< sqrt(x) <<endl;
    if(x>0){
    cout<< "the logarithm of x= "<< log(x) <<endl;
    }return 0;
}
//EXERCISE 12
#include <cmath>
int main()
{double a,b;
cin>>a>>b;
   cout<<pow(a,b);

    return 0;
}
//EXERCISE 13
int main()
{
    cout << "enter a character " << endl;
    char character;
    cin>> character;
    int ASCII_value=static_cast<int>(character);
    cout<<"the ASCI of "<<character<<" is: "<<ASCII_value;
    return 0;
}
//EXERCISE 14
int main()
{char character;
    cout << "enter an alphabet" << endl;
    cin>>character;
    character= tolower(character);
    if(character == 'a'||character == 'e'||character == 'i'||character == 'o'||character == 'u'||character == 'y'){cout<<character<<" is a vowel";}
    else cout<< character<< " is a consonant";
    return 0;
}
//EXERCISE 15
int main()
{string name;
    cout << "enter your name ";
getline(cin, name);

    double mrk1,mrk2,mrk3,mrk4,mrk5;
     cout<<"enter the first subject's mark ";cin>>mrk1;
     cout<<"enter the second subject's mark";cin>>mrk2;
     cout<<"enter the third subject's mark";cin>>mrk3;
     cout<<"enter the fourth subject's mark";cin>>mrk4;
     cout<<"enter the fifth subject's mark";cin>>mrk5;

     cout<<"\n Name: "<<name<<endl;
      cout<<" first subject's mark score: "<<mrk1<<endl;
       cout<<" second subject's mark score: "<<mrk2<<endl;
       cout<<" third subject's mark score: "<<mrk3<<endl;
       cout<<" fourth subject's mark score: "<<mrk4<<endl;
       cout<<" fifth subject's mark score: "<<mrk5<<endl;

       cout<<" Average=  "<<(mrk1+mrk2+mrk3+mrk4+mrk5)/5<<endl;       cout<<"Percentage scored= "<<(mrk1+mrk2+mrk3+mrk4+mrk5)<<"%";


    return 0;
}*/
#include <cmath>
#include <cstdlib>
#include <ctime>
/*Lab 4
//exercise 1
int main (){
int angle1, angle2, angle3;
cout << "enter the first angle";
cin>>angle1;
cout << "enter the second angle";
cin>>angle2;
cout << "enter the first angle";
cin>> angle3;
if (angle1<=0 || angle2<=0 || angle3<=0){cout<< "enter a valid angles"; }
else if (angle1+angle2+angle3==180){cout << "the shape is triangle"; }
else cout<<"the shape is not a triangle";
return 0;}
//exercise 2
int main (){
float a,b,c,delta,x,x1,x2;
cout << "the quadric equation is written like a*x^2+ b*x +c,so please enter a then b then c";
cin >>a>>b>>c;
delta= b*b - 4*a*c;
if (delta<0) cout<< "the equation has no solutions in R";
else if (delta =0){
        x=-b/(2*a);
        cout <<"the equation has one solution x= "<<x;}
else{ x1=(-b+ sqrt(delta) )/(2*a);
x2=(-b- sqrt(delta) )/(2*a);
cout <<"the equation has two solutions x1= "<<x1<<" x2= "<<x2;
}}
//exercise 3
int main()
{
    double average,quiz,mid_term,final_score;
    cout << "enter your quiz, mid-term, and final scores "<<endl;
cin >>quiz>>mid_term>>final_score;

    average=( quiz + mid_term + final_score )/3;
    if ( average>100 || quiz>100 || mid_term>100 || final_score>100 ) {cout <<"Enter a valid scores";
    return 1;
     }

    if (average>=90) {cout << "your grade is A";}
    if (average>=70&& average <90 ) {cout << "your grade is B";}
   if (average>=50 && average<70)
{cout << "your grade is C";}
   if (average<50) {cout << "your grade is F";}
   return 0;
}
//exercise 4
int main() {
   srand(static_cast<unsigned int>(std::time(nullptr)));

    int numbers= rand ()%16 + 1,i,sum,num;


    for(i=1;i<=numbers;i++){
            num =rand() % 16 +8;
            sum +=num;
    cout<< num<<"+ ";}

    cout << "Find the sum of random numbers between 8 and 23:" <<endl;
    int playerAnswer;
    std::cout << "Enter your answer: ";
    std::cin >> playerAnswer;


    if (playerAnswer ==sum) {
       cout << "Congratulations! You are the winner!" << endl;
    } else {
     cout << "Sorry, that's incorrect. The correct sum is: " << sum << endl;
    }

    return 0;
}
//exercise 5
int main(){
    int i,num,sum=0;
    for (i=11;i<=10;i++){
    cout << "ENTER the"<<i <<"'th NUMBER   "<< endl;
    cin>> num;
   sum+=num;

    } cout<< "sum=num1+num2+num3+num4+num5+num6+num7+num8+num9+num10= "<<sum;
     return 0;}
//EXERCISE 6
int main (){
int N,num,i=1,sum=0;
cout << "enter the number N";
cin >>N;
for (i=1;i<=N;i++){
    X:
    cout << "enter an odd number";
    cin >>num;
        if (num%2!=0){
        sum+=num;}
else goto X;
                  }
cout << "the sum of N odd numbers is sum= "<<sum;

}
//EXERCISE 6
while (i<=N){
    cout<< "enter an odd number";
    cin >>num;
    if (num%2!=0){sum+=num;
    i++;}
    else cout<< "enter an odd number";
cout << "the sum of N odd numbers is sum= "<<sum;
}
//exercise 7
int main (){
int n,sum=0, count=0;
float average;
cout << "type strictly positive integers and I will display their mean";
do{
    cin >>n;
    if (n<0){cout << "ERROR";}
    else  {  sum+=n;
            count++;
           }
       }while (n!=0);
    average=sum/count;
cout << "average is "<< average;
}
//EXRECISE
int main (){
int high=0,i=1,num,accurence=0;
for (i=1;i<=10;i++){
    cout << "enter 10 numbers";
    cin>> num;
    if (num>high) {high=num;}
    else if (num==high){accurence++;}
}
cout << "the highest number is "<< high << "and it appear "<< accurence<< " time";
}
//EXERCISE
int main (){
int d=0,N1=0,N,position=1;
cout <<"Enter a number N and I will invert aLl of its digits. "<<endl;
cin>> N;
while (N>0)
{
    d = N % 10;
    N1 += d * position;
    N /= 10;
 position *= 10;
}
cout << "The inverse of "<< N << " is "<< N1;
}
//EXERCISE 10
#include<string>
void spaceF(int n,string &space){
    space="";
    for (int i=0;i<n;i++){
        space+=' ';
    }
}
int main(){
    int h,num_space;
    bool rev;
    char symbol, space= ' ';
    cout << "Enter the height of the pyramid: ";
    cin>> h;
    cout << "Enter the symbol to use for the pyramid: ";
    cin >> symbol;
    cout <<  "Enter the number of spaces to use for padding: ";
    cin>> num_space;
    string spac="";
    spaceF(num_space,spac);
    cout << "Reverse the pyramid (1 for yes and 0 for no): ";
    cin>> rev;
    if (rev==1){
        int ispace=0,i=h;
        string spac1="";
        spaceF(ispace,spac1);
        while (ispace<=(h-1)*(1+num_space) &&i>0){
            cout <<spac1;
            for(int j=0;j<2*i-1;j++){
                cout << symbol<< spac;
            }
            cout <<endl;
            i--;
            ispace+=1+num_space;
            spaceF(ispace,spac1);
        }
    }

    else if(rev==0) {
    int ispace=(h-1)*(1+num_space),i=0;
        string spac1="";
        spaceF(ispace,spac1);
        while (ispace>0 &&i<h){
            cout <<spac1;
            for(int j=0;j<2*i+1;j++){
                cout << symbol<< spac;
            }
            cout <<endl;
            i++;
            ispace-=1+num_space;
            spaceF(ispace,spac1);
        }

    }
    return 0;
}
*/
/*LAB 6
//Exercise 01
double function (double x, bool isDefined){
if(x>=2){
    double result= sqrt((x-1)(x-2));
    isDefined= true;
    return result;
}
else {
    isDefined= false;
}
}
int main (){
}
//EXERCISE 2
int swap(int x, int y){
int c;
c=x;
x=y;
y=c;
cout << "x= "<<x<< "  y="<<y;
return x,y;
}
int main()
{
   int x,y;
   cout << "enter two numbers";
   cin >> x>>y;
   swap (x,y);
    return 0;
}
// EXERCISE 3
double euclideien (double x1, double y1, double x2, double y2){
double AB= sqrt ((x1+x1)*(x1+x1)+(x2+y2)*(x2+y2));
return AB;
}
int main()
{
   double distance,x1,y1,x2,y2;
   cout << "Enter the coordinates (x,y) of two points A and B and I will display the distance AB"<<endl;
   cin >> x1>>y1>>x2>>y2;
   distance=euclideien(x1,y1,y2,y2);
   cout << "the distance AB = "<< distance;
    return 0;
}
//EXERCSE 5
bool prime (int n){
int i,t=0;
for (i=1;i<=(n/2);i++){
    if (n%i==0){t++;}

}
if (t==1){return true;}
else return false;
}
int main(){
    int n;
cout << "Enter an integer n ";
cin >>n;
cout<< prime(n);
return 0;
}
//EXERCISE 6
bool prime (int n){
int i,t=0;
for (i=1;i<=(n/2);i++){
    if (n%i==0){t++;}

}
if (t==1){return true;}
else return false;
}
int main(){
    int m,n;
cout << "Enter an interval [m,n]\n m=";
cin >>m;
cout<< " n=";
cin >>n;
for (int i=m; i<=n;i++){
  if(prime(i)==1){cout <<i<< " " ;}
}

return 0;
}
*/
/*LAb7
//exercise 02:
int swap(int x, int y){
   int c=x;
    x=y;
    y=c;
    return x,y;
}
int main (){
    cout<< "enter two numbers x and y"<<endl;
    cin>> x>>y;
    int res=swap (x,y);
    cout <<res;
}
//exercise 03
int monthly_loden(int loan_amount, int interest_rate, int loan_term){
 interest_rate=0,035;
 loan_term=5*12;
int mpa=loan_amount*(1+interest_rate)/loan_term; //monthly(m) payment(p) amount(a)
return mpa;
}
int main (){
    int mpa,loan_amount,interest_rate, loan_term;
    cout << "Enter the loaden amount and the interest rate and the loden term"<<endl;
    cin >>loan_amount>>interest_rate>> loan_term;
    mpa=monthly_loden(loan_amount,interest_rate, loan_term);
    cout << "the monthly payment amount is="<<mpa<<"$";
    return 0;
}*/
// Exercise 04:

/*
//Lab 9
void scanArray (int A[], int n){
    for (int i= 0; i<n; i++){
       cout << "Enter the element number "<<i+1<< ": ";
        cin >> A[i];
    }
}
int printArray(int A[], int n){
for (int i=0; i<n; i++){
    cout << A[i] << " ";
}
}
int main()
{
    cout << "Enter the size of the array n: ";
int n;
cin >> n;
int A[n];
scanArray(A,n);
cout << "A=[ ";
printArray(A,n);
cout << "]";
    return 0;
}
//Exercise 02:
int minArray (int A[],int n ){
int index=0,min=A[0];
for (int i=1; i<n; i++){
    if (A[i]< min){
        index=i;
        min = A[i];
    }
}return index;
}
int main (){
    cout << "Enter the size of the array n: ";
int n;
cin >> n;
int A[n];
scanArray(A, n);
cout << minArray(A,n);
}
//Exercise 03:
bool F(int A[], int n){
bool indicate=false;
for (int i=0; i<n; i++){
    if (A[i]<=10 && A[i]>=0){
    indicate=true;
    break;}

}
return indicate;}
int main (){
    cout << "Enter the size of the array n: ";
int n;
cin >> n;
int A[n];
scanArray(A, n);
bool indicate ;
indicate=F(A,n);
if(indicate==true){
    cout << "yes there is a number between 0 and 10 in the array";
}
else { cout << "No there is a no number between 0 and 10 in the array";}
}
//Exercise 04:
void scanArray (int A[], int n){
    for (int i= 0; i<n; i++){
       cout << "Enter a number between 0 and 20 :";
       int n;
        cin >> n;
        if (n<=20 && n>=0){
            A[i]=n;
        }
        else {
       cout << " you must enter a number between 0 and 20 :";
        }
    }}
    void printOccurrence(int A[], int n){
        int B[21]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i=0; i<=n; i++){
            for (int j=0; j<=20; j++){
                if (A[i]==j){
                    B[j]++;
                            }
                                    }
        }for (int j=0; j<=20; j++){cout << "the occurence of "<<j<< "is " << B[j]<<endl;   }

        }

    int main (){
         cout << "Enter the size of the array n: ";
    int n;
    cin >> n;
    int A[n];
    scanArray(A,n);
    printOccurrence(A,n);
        }
    //Exercise 05:
    void removeElementArray(int v, int &n, int A[]){
    int i;
    for (i=0; i<=n;i++){
        if (A[i]==v){

            break;
        }
    }
    for (int j=i; j<n; j++){
        A[j]=A[j+1];
    }
    A[n-1]=0;
    for (int i=0; i<n; i++){
        cout << "A["<<i<< "]="<< A[i]<<endl;
    }
    }
    int main (){
        int v,n;
        cout <<"Enter the number of elements: ";
        cin >>n;
        int A[n];
        for (int i=0; i<n; i++){
            cout <<"enter the element number "<< i<< ": " ;
            cin>> A[i];
        }
        cout <<  "enter the element that you want to remove it: ";
        cin >>v;
        removeElementArray(v,n,A);
    }
//Exercise 06
void InsertElementArray(int e, int p, int &n, int A[]){
int i;
    n++;
    for (int j=n-1; j>=p; j--){
        A[j]=A[j-1];
    }
 A[p]=e;
}
int main (){
        int p,e,n;
        cout <<"Enter the number of elements: ";
        cin >>n;
        int A[n];
        for (int i=0; i<n; i++){
            cout <<"enter the element number "<< i<< ": " ;
            cin>> A[i];
        }
        cout <<"Enter the element that you want to insert it and it position";
        cin>> e>>p;
        InsertElementArray(e,p,n,A);
        for (int j=0; j<n; j++)
            {cout << "A["<<j+1<< "]=" << A[j]<<endl;   }
}
//Exercise 07
void checkElementsInSubmatrix (int board[9][9],int subN, int subM, int n, int m ){
    for (int i=0;i<subN; i++){
        for (int j=0; j<subM; j++){
            int A[subN*subM],k=0;
            if (A[k]==0){A[k]=board[i][j];}
            k++;
        }
    }
    for (int i=0; i<subN*subM; i++){
        if (A[i]=)
    }
}
//Exercise 08
void reversearray(int A[], int n){
for (int i=0;i<n/2;i++){
    int s;
    s=A[i];
    A[i]=A[n-1-i]   ;
    A[n-1-i]=s;
}
}
int main (){
    int n;
    cout <<"Enter the number of elements: ";
    cin >>n;
    int A[n];
    for (int i=0; i<n; i++){
            cout <<"enter the element number "<< i<< ": " ;
            cin>> A[i];
        }
    reversearray(A,n);
    for(int i=0;i<n;i++){
            cout << "A["<< i+1<< "]= "<<A[i] <<endl;

    }
    return 0;
}
//Exercise 09
void initializeSpace(char A[], int n){
for (int i=0; i<n; i++){
    A[i]=' ';
}
}
void printArray(char A[], int n){
for (int i=0; i<n; i++){
    cout << A[i]<< " ";
}
}
int main (){
const int size=10;
char A[size];
initializeSpace(A,size);
printArray(A,size);
}
//exercise 09:
bool placeMark(char A[], int n, char Mark, int position){
if (A[position]==' '){
    A[position]=Mark;
    return true;
}
else return false ;}
int main (){
cout << "Enter the size of the array";
int n,position;
char A[n],Mark;
cin>> n;
for (int i=0; i<n; i++){
    cout << "enter the element number "<<i<<": ";
    cin >>A[i];
}

cout <<"the mark and its position"<<endl;
cin >>Mark>>position;
cout << placeMark(A,n,Mark,position);
return 0;
}
//Exercise 10;
bool fullArray(char A[], int n){
for (int i=0; i<n; i++){
    if (A[i]==' '){
        return true;
        break;
    }
    else return false;
}
}
int main (){
cout << "Enter the size of the array";
int n;
cin>> n;
char A[n];
for (int i=0; i<n; i++){
    cout << "enter the element number "<<i<<": ";
    cin >>A[i];
}
if (fullArray(A,n)==true){cout<< "the array is no full"; }
else cout << "the array is full";
}
void printArrayIn2D(char A[], int n, int rows, int columns) {
    if (n != rows * columns) {
        std::cout << "Error: Array size does not match 2D dimensions." << std::endl;
        return;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int index = i * columns + j;
            std::cout << A[index] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    char myArray[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int rows = 2;
    int columns = 3;
    printArrayIn2D(myArray, size, rows, columns);

    return 0;
}
*/
// Exercise 11
// LAB 10
// Exercise 01:
/*
const int col=100;
void scanMatrix (int M[][col],int n, int m){
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<< "M["<<i<<","<<j<<"]:";
        cin >> M[i][j];
    }
}
}
void printMatrix (int M[][col], int n, int m){
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<<setw(4)<< M[i][j]<< " ";
    }
    cout <<endl;
}
}
//Exercise 2
void separateEvenOdd (int M[][col], int n, int m, int &size1, int &size2){
size1=0;size2=0;int A[100],B[100];
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      if (M[i][j]%2==0){A[size1]=M[i][j]; size1++;}
      else {B[size2]=M[i][j];size2++;}
    }
    cout <<endl;
}
cout << "A[]={ ";
for (int i=0; i<size1; i++){
    cout << A[i]<< " , ";
}
cout <<"}"<<endl<< "B[]={ ";
for (int i=0; i<size1; i++){
    cout << B[i]<< " , ";
}
cout <<"}"<<endl;
}
//Exercise 3
int i=0,j=0;
void read_Matrix (int M[][100],int n ){
    for ( i=0; i<n; i++){
    for ( j=0; j<n; j++){
        cout<< "M["<<i<<","<<j<<"]:";
        cin >> M[i][j];}}

int sumDiagonal=0,sum_ab=0,sum_be=0;
for (i=0; i<n; i++){
sumDiagonal+=M[i][i];
}//end for
cout << "sum of diagonal ="<< sumDiagonal<<endl;
i=0;
j=0;
while (i<n){
    while (j<n){
        sum_ab+=M[i][j];
        j++;
    }
    i++;
    j=i;
}
sum_ab=sum_ab- sumDiagonal;
cout <<"the sum above = "<< sum_ab<<endl;
i=0,j=0;
while (i<n){
    while(j<=i){
        sum_be+=M[i][j];
        j++;
    }
    i++;
    j=0;
}
sum_be=sum_be-sumDiagonal;
cout <<"the sum below = "<< sum_be<<endl;

}

//Exercise 4
int sum_row (int M[][col],int n, int m){
    int sum =0;
    for (int j=0; j<m; j++){sum+=M[n][j];}
    return sum;}
int sum_col (int M[][col], int n, int m){
    int sum =0;
    for (int j=0; j<n; j++){sum+=M[j][m];}
    return sum;}
bool checkSum (int M[][col], int n, int m){
    for (int  i=0; i<n; i++){if (sum_row(M[i][m],n,m)!=sum_row(M[i+1][m],n,m)){return false;}}
    for (int  i=0; i<m; i++){if (sum_row(M[n][i],n,m)!=sum_row(M[n][i+1],n,m)){return false;}}
    return true;
}
//Exercise 5
bool CheckElementsInRow(int M[][COL], int n, int m, int row){
int A [],size =0;
for (int i=0; i<m; i++){
    for (int j=0; j<size; j++){
        if (M[row][i]==A[j]){return false;}
        else {A[size]=M[row][i];size ++; }
    }
}
return true;}
bool CheckElementsInColumn(int M[][COL], int n, int m, int col){
int A [],size =0;
for (int i=0; i<m; i++){
    for (int j=0; j<size; j++){
        if (M[i][col]==A[j]){return false;}
        else {A[size]=M[i][col];size ++; }
    }
}
return true;}
//Exercise 6;
//Exercise 7
//Exercise 8
int multiply_two_matrix(int M1[][col],M2[][col],int n, int m , int k){
int C [m][k];
for (int j=0; j<m; j++){
    for (int z=0; z<k; z++){
        for (int i=0; i<n; i++){
        sum=+ M1[j][n] * M2[n][z];
        }
    C[j][z]=sum;
    sum=0;
    }
}
}
//Exercise 9
void transposedMatrix (int n, int m){
int B[m][n];
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<< "M["<<i<<","<<j<<"]:";
        cin >> M[i][j];
        B[j][i]=M[i][j];
    }
}
printMatrix(B,m,n);
}
//Exercise 10
void print_half (int M[][col], int n){
    int i=0,j=0;
    while (i<n){
        while (j<n){
            cout<< setw(5)<< A[i][j];
            j++;}i++;j=i;
    }
     for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<< setw(5)<< A[i][j];
            }
    }
}
int main (){
cout << "enter the number of exercise"<<endl;
int n;
cin >>n;
switch (n){
case 1:{
cout << "enter the number of rows";
int n,m,M[col][col];
cin >>n;
cout << "enter the number of columns";
cin >> m;
scanMatrix(M,n,m);
printMatrix(M,n,m);
}
case 2:{

cout <<"enter the size of the matrix: ";
int n,M[100][100];
cin >>n;
read_Matrix(M,n);
}
case 3:{}
case 4:{}
case 5:{}
case 6:{}
case 7:{}
case 8:{}
case 9:{}
case 10:{}

}
}*/
#include <string>
#include <array>
#include <vector>
/*
//LAB 11
//Exercise 01
string concatenate(int day, int month, int year){
    return to_string(year)+"-"+to_string(month)+"-"+to_string(day);
}
int main (){
    int year,month,day;
    cout << "Enter a year: ";
    cin >> year;
    cout << "Enter a the month: ";
    cin >> month;
    if (month>12){cout <<"enter a valid month!";return 0;}
    cout << "Enter a day: ";
    cin >> day;
    if (day>31 || day <0){cout <<"not valid day!";return 0;}
    cout <<"Date: "<< concatenate(day,month,year)<<endl;
}
//Exercise 02
void textStatistic(string sentence, int &CountVowel, int &CountConsonant,int &CountDigit, int &CountWhiteSpace){
    CountConsonant=0;CountVowel=0;CountDigit=0;CountWhiteSpace=0;
    for (char c: sentence ){
        if (isalpha(c)!=0){
            if (c=='a'||c=='e'||c=='i'||c=='u'||c=='o'||c=='y'){
            CountVowel++;
            }
            else CountConsonant++;
        }
        if (isspace(c)!=0){CountWhiteSpace++;}
        if (isdigit(c)!=0){CountDigit++;}
    }
}
int main (){
    cout <<"Enter a sentence"<<endl;
    string sentence;
    getline(cin,sentence);
    int CountVowel=0,CountConsonant=0,CountDigit=0,CountWhiteSpace=0;
    textStatistic(sentence,CountVowel,CountConsonant,CountDigit,CountWhiteSpace);
    cout << "There exist in the sentence above: \n"<<CountConsonant<< " consonant.\n"<<CountVowel<<" vowel.\n"<<CountDigit<< " digit.\n"<< CountWhiteSpace<<" white space"<<endl;
    return 0;}
    //Exercise 03
    void removeNonAlphabetic(string &str){
        int len=str.size();
        string word="";
        for (int i=0; i<len;i++){
            if (isalpha(str[i])){
                word=word+str[i];
            }
        }
        str =word;
    }
    int main (){
        string ph;
        cout <<"enter a sentences"<<endl;
        getline(cin,ph);
        removeNonAlphabetic(ph);
        cout << ph<<endl;
    }
    //Exercse 04
   void textSplit(string text, vector<string> &segments, char delimiter = ' '){
    int len =text.size(),start=0,i=0;

    //tosplit the sentences into words
    for (int i=0; i<len;i++){
        if (text[i]==delimiter){
            segments.push_back(text.substr(start,i-start+1));
            start=i+1;
        }
    }
    segments.push_back(text.substr(start,i-start+1));
   }
   int main (){
    string ph;
    vector<string> segments;
    char delimiter=' ';
    cout <<"enter a phrase: ";
    getline(cin, ph);
    textSplit(ph,segments,delimiter);
    int number_segments;
    number_segments=segments.size();
    cout << "The number of words: "<<number_segments<<endl;
    for (int i=0 ; i<20; i++){
        cout << segments[i] <<endl;
    }
    return 0;
   }

    //Exercise 05
    void capitalizingFirstLetter(string &sentence){
        int len=sentence.size();
        sentence[0]=toupper(sentence[0]);
        for (int i=1; i<len-1; i++){
            if (isspace(sentence[i])!=0){
                sentence[i+1]=toupper(sentence[i+1]);
            }
        }
    }
    int main (){
        string ph;
        cout << "enter a phrase"<< endl;
        getline(cin,ph);
        capitalizingFirstLetter(ph);
        cout << ph<<endl;
    }

   //Exercise 06
//function to lower the sentence
string lower(string& word){
    string temp = "";
    for (int i = 0; i < word.size(); i++)
    {
        temp += tolower(word[i]);
    }
    return temp;
}
int countConsecutive(string& sentence , string word) {
    vector<string> words ;
    int count = 0;
    int index = 0;
    for (int i = 0 ; i < sentence.size(); ++i){
        if (sentence[i] == ' ')
        {
            words.push_back(sentence.substr(index,i-index));
            index = i + 1;
        }

    }
    for(auto w : words){
        cout << w << endl;
        if (w == word)
        {
            count++;
        }
    }
    return count;
}

int main(){
    string sentence = "is is is am are you";
    string word = "is";
    cout << countConsecutive(sentence,word) << endl;
}
//Exercise 07
#include <iostream>
#include <string>

using namespace std;

void removeFirstSpace(string &sentence) {
    if (sentence[0] == ' ') {
        int i = 0;
        for (i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ') {
                break;
            }
        }
        sentence.erase(0, i);
    }
}

void removeConsecutiveRepetitions(string &sentence) {
    sentence+=' ';
    string new_sentence = "";
    string word = "";
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] != ' ') {
            word += sentence[i];
        }
        if (sentence[i] == ' ' && new_sentence.find(' ' + word + ' ') != string::npos) {
            word.erase();
            continue;
        }
        if (sentence[i] == ' ' && new_sentence.find(' ' + word + ' ') == string::npos) {
            new_sentence += ' '+word+' ';
            word.erase();
        }
    }
    sentence = new_sentence;
}

int main() {
    string sentence ;
    cout << "enter the sentence"<<endl;
    getline (cin ,sentence);
    removeFirstSpace(sentence);
    cout << sentence << endl;
    removeConsecutiveRepetitions(sentence);
    cout << sentence << endl;

    return 0;
}


//Exercise 08
void removeStopWord(string arrayOfWord[],int size){
    int i=0;
    string stop_word[]={"a", "an", "and", "are", "as","at", "be", "but", "by", "for", "if", "in", "into", "is", "it", "no", "not", "of", "on","or", "such", "that", "the", "their", "then", "there", "these", "they", "this", "to", "was","will" , "with"};
    bool exist=false;
    int s =0;
    string arrayOfWord1[size];
    for (int j=0; j<size;j++){
        for (int i=0; i<33;i++){
            if (arrayOfWord[j]==stop_word[i]){
                exist=true;
                break;
            }
        }
        if (!exist){
            arrayOfWord1[s++]=arrayOfWord[j];
        }
        exist =false;
    }
    for (int i=0;i<s;i++){
        arrayOfWord[i]=arrayOfWord1[i];
    }
    for (int j=s;j<size;j++){
        arrayOfWord[j]="";
    }
}
int main (){
    int size=0;
    string word;
    cout <<"enter the number of words stored in the array"<<": ";
    cin >> size;
    string arrayOfWord[size];
    for (int i=0;i<size;i++){
        cout << "enter the element of index "<<i<<": ";
        cin>>word;
        arrayOfWord[i]=word;
    }
    removeStopWord(arrayOfWord,size);
    for (int i=0; i<size;i++){
        cout << arrayOfWord[i]<<" | ";
    }
}

//Exercie 09
#include <algorithm>  // for std::min
vector<string> split_sentence(string sentence) {
    sentence += ' ';
    vector<string> words;
    int index = 0;
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' '&& find(words.begin(),words.end(),sentence.substr(index, i - index)) !=words.end()) {
            words.push_back(sentence.substr(index, i - index));
            index = i + 1;
        }
    }
    return words;
}

double Similarity(string &Sentence1, string &Sentence2) {
    Sentence1 += ' ';
    Sentence2 += ' ';
    vector<string> words1 = split_sentence(Sentence1);
    vector<string> words2 = split_sentence(Sentence2);
    double size = min(words1.size(), words2.size()), similarity = 0;
    words1=split_sentence(Sentence1);
    words2 = split_sentence(Sentence2);
    for (int i = 0; i < words1.size(); i++) {
        // Check if the word from Sentence1 is found in Sentence2
        if (find(words2.begin(), words2.end(), words1[i]) != words2.end()) {
            similarity++;
        }
    }
    return similarity / size;
}

int main() {
    cout << "Enter the first sentence: " << endl;
    string sentence1, sentence2;
    getline(cin, sentence1);

    cout << "Enter the second sentence: " << endl;
    getline(cin, sentence2);

    cout << "Similarity: " << Similarity(sentence1, sentence2) << endl;

    return 0;
}
/*
//Exercise 10
string MostRelevantSentenceStopWord(string arrayOfSentence[], string question){
    double s=Similarity(arrayOfSentence[0],question);
    string sentence=arrayOfSentence[0];
    int j=0,size=0;
    while (arrayOfSentence[j]==""){
        size++;
    }
    for (int i=1;i<size;i++){
        if (s<Similarity(arrayOfSentence[i],question)){
            s=Similarity(arrayOfSentence[i],question);
            sentence=arrayOfSentence[i];
        }
    }return sentence;
}
int main (){
    string question;
    int num;
    cout <<"Enter the question: ";
    getline(cin,question);
    cout << " how many sentences you want to enter: ";
    cin >> num;
    string arrayOfSentence[num];
    for (int i=0;i<num; i++ ){
    cout <<"Enter the sentence: ";
    getline(cin,arrayOfSentence[i]);
    }
    cout << "the most semilar sentence is "<<MostRelevantSentenceStopWord(arrayOfSentence,question);
}

//stuct exercise
/*
struct Employee
{
    string name;
    string departement;
    float salary;
};
Employee highSalaryEmployee ( Employee A[],int n){
    int max =A[0].salary,h=0;
    for (int i=0; i<n; i++){
        if (max<A[i].salary){
            max=A[i].salary;
            h=i;
        }
    }
    return A[h];
}
int main (){
    cout << "enter the number of employees: ";
    int n;
    cin >>n;
    Employee A[n];
    string name;
    for (int i=0;i<n;i++){
        cout <<"enter the name of the employee "<<i<<" : ";
        getline(cin>>ws , A[i].name);
        cout <<"enter the departement of the employee "<<i<<" : ";
        cin >> A[i].departement;
        cout <<"enter the salary of the employee "<<i<<" : ";
        cin >> A[i].salary;
    }
    cout <<"the person whohas the highest salary is "<< highSalaryEmployee (A,n).name <<endl;

}
//LAB 13
//Exercise 1
// #include "sorting.h"
void insert (string &A,int size){
    for (int  i = 0; i < size; i++)
    {
        char key =A[i];
        int j=i-1;
        while(j>=0&& A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

}
void insert (int A[],int size){
    for (int  i = 0; i < size; i++)
    {
        int key =A[i];
        int j=i-1;
        while(j>=0&& A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

}
int main (){
    string str;
    cout <<"Enter a word:"<<endl;
    getline(cin,str);
    insert(str,str.size());
    cout <<"the word after the sorting"<<str<<endl;
    cout <<"how many numbers do you want to enter?"<<endl;
    int num;
    cin >>num;
    int A[num];
    for (int i=0;i<num;i++){
        cout << " enter the number "<<i+1<<": ";
        cin >>A[i];
    }
    cout <<"The array before sorting:";
    for(int i=0; i<num;i++){
        cout <<A[i]<<", ";
    }
    cout << endl;
    insert(A,num);
    cout <<"the array after the sorting:";
    for(int i=0; i<num;i++){
        cout <<A[i]<<", ";
    }
    cout << endl;
    return 0;
}

//Exercise 2
#include <iomanip>
void insert (int A[],int size){
    for (int  i = 1; i < size; i++)
    {
        int key =A[i];
        int j=i-1;
        while(j>=0&& A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

}
//function to sort two dimentional array
void insert (int A[][2],int size){
    for (int  i = 1; i < size; i++)
    {
        int key1 =A[i][1];
        int key0 =A[i][0];
        int j=i-1;
        while(j>=0&& A[j][1]>key1){
            A[j+1][1]=A[j][1];
            A[j+1][0]=A[j][0];
            j--;
        }
        A[j+1][1]=key1;
        A[j+1][0]=key0;
    }

}
void accurency(int A[],int size){
    //to know how many numbers in the array
    insert(A,size);
    for (int i=0; i< size; i++){
        cout << A[i]<<' ';
    }cout<<endl;
    int sizeB = 1;
    for (int i = 1; i < size; i++) {
        if (A[i] != A[i - 1]) {
            sizeB++;
        }
    }

    // Create a 2D array to store the unique elements and their occurrences
    int B[sizeB][2];
    int j = 0; // Initialize j to 0

    // Initialize occurrence for the first element
    int occurrence = 1;

    // Iterate through the array to count occurrences
    for (int i = 1; i < size; i++) {
        if (A[i] == A[i - 1]) {
            occurrence++;
        } else {
            // Store the unique element and its occurrence in the 2D array
            B[j][0] = A[i - 1];
            B[j][1] = occurrence;

            // Reset occurrence for the next unique element
            occurrence = 1;

            // Move to the next row in the 2D array
            j++;
        }
    }

    // Handle the last element in the array
    B[j][0] = A[size - 1];
    B[j][1] = occurrence;
    insert(B,sizeB);
    // Display the sorted 2D array
    for (int i = 0; i < sizeB; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << std::setw(4) << B[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}


int main (){
    int A[]={6,7,2,234,23,98,0,3,8,6,6};
    accurency(A,11);
    return 0;
}
//Exercise 3
struct timee{
    int hour,minutes,seconds;
};
timee calc (timee t1,timee t2){
    timee t3;
    t1.seconds+=t1.minutes*60+t1.hour*3600;
    t2.seconds+=t2.minutes*60+t2.hour*3600;
    t3.seconds=t1.seconds-t2.seconds;
    t3.hour=t3.seconds/3600;
    t3.seconds-=t3.hour*3600;
    t3.minutes=t3.seconds/60;
    t3.seconds-=t3.minutes*60;
    return t3;
}
int main (){
    timee t1,t2;
    t1.hour=23;
    t1.minutes=23;
    t1.seconds=54;
    t2.hour=12;
    t2.minutes=48;
    t2.seconds=38;
    timee t3=calc (t1,t2);
    cout <<t3.hour<<':'<<t3.minutes<<':'<<t3.seconds<<endl;

}
//Exercise 4
struct complex{
    int real,imagin;
};
complex addition(complex z1,complex z2){
    complex z3;
    z3.real =z2.real+z1.real;
    z3.imagin=z2.imagin+z1.imagin;
    return z3;
}
int main (){
    complex z[3];
    for (int i=0; i<2; i++){
    cout <<"Enter the real part of the number "<<i<<": ";
    cin >>z[i].real;
    cout <<"Enter the imaginary part of the number "<<i<<": ";
    cin >>z[i].imagin;
    }
    z[2]=addition(z[0],z[1]);
    cout <<"Z= "<< z[2].real<< " + "<<z[2].imagin<<'i';
}*/

// Exercise 5
/*
struct address{
    string street, city;
    int postal_code;
};
struct contact{
    string last_name,first_name, birth_date;
    struct address;
    int tel1,tel2,tel3;
};
int main (){
    contact A[255];
    for (int i=0; i<5;i++){
        cout <<"The contact N"<<i<<" \nenter the last name: ";
        getline(cin>>ws,A[i].last_name);
        cout << "enter the first name: ";
        getline(cin>>ws,A[i].first_name);
        cout << "enter the birthday: ";
        getline(cin>>ws,A[i].birth_date);
        cout << "enter the the telephone: ";
        cin.ignore();
        cin>>A[i].tel1;
        cout <<"Do you want to enter another phone y for yes and n for no: ";
        char c;
        cin.ignore();
        cin >> c;
        int t=1;
        if (c=='y'){
        cout << "enter the the telephone: ";
        cin.ignore();
        cin>>A[i].tel2;
        cout <<"Do you want to enter another phone y for yes and n for no: ";
        if (c=='y')
        {
        cin.ignore();
        cin>>A[i].tel3;
        cout <<"Do you want to enter another phone y for yes and n for no: ";
        }
        }
        cout << "enter the the street: ";
        getline(cin>>ws,A[i].address.street);
        cout << "enter the city";
        getline(cin>>ws,A[i]);
        cout << "enter the postal code";
        cin.ignore();
        cin>>A[i];
        cin.ignore();

    }
    }
//part2
//Exercise 1
void print (int n){
    if(n==0){
        cout << n;
    }
    else print(n-1);
    cout <<n<<' ';
}
int main (){
    print(50);
    return 0;
}
//Exercise 2
int sum (int n){
    if (n==1){
        return n;
    }
    else return sum(n-1)+n;
}
int main (){
    cout <<sum (10);
    return 0;
}
//Exercise 3
int HCF (int m,int n){
    if(n==1 || m==1){
        return 1;
    }
    else if (n<m) return HCF (m-n,n);
    else return HCF (m,n-m);
}
int main (){
    int  n,m;
    cout <<"Enter two digit m and n"<<endl;
    cin>>m>>n;
    cout <<HCF (m,n)<<endl;
}
//Exercise 4
int power(int n,int m){
    if(m==0){
        return 1;
    }
    else {
        return n*power (n,m-1);
    }
}
int main (){
    int  n,m;
    cout <<"Enter two digit m and it's power n"<<endl;
    cin>>m>>n;
    cout <<power (m,n)<<endl;
}
//Exercise 5
void tower_of_hanoi(int n, char srod, char frod, char temprod) {
    if (n == 1) {
        cout << "Move disk 1 from " << srod << " to " << frod << endl;
        return;
    }

    tower_of_hanoi(n - 1, srod, temprod,frod);
    cout << "Move disk " << n << " from " << srod << " to " << frod << endl;
    tower_of_hanoi(n - 1, temprod, frod, srod);
}

int main() {
    cout << "Enter the number of disks";
    int n;
    cin >>n;
    tower_of_hanoi(3, 'A', 'C', 'B');

    return 0;
}*/
/*
//LAB 14
//Exercise 1
int main (){
    int *p=nullptr;
    int v=10;
    p = &v;
    cout << "what value you want to store in v"<<endl;
    cin >> *p;
    int w=*p;
    int* r=p;
    cout << "what value you want to store in v"<<endl;
    cin >> *r;
}
//Exercise 2
void swap1 (int* ptrvl1,int* ptrvl2){
    int c= *ptrvl1;
    *ptrvl1=*ptrvl2;
    *ptrvl2=c;
}
int main (){
    int a=5,b=6;
    cout << "Before the swap:"<<endl;
    cout << "a= "<<a<<endl;
    cout << "b= "<<b<<endl;
    swap1(&a,&b);
    cout << "After the swap:"<<endl;
    cout << "a= "<<a<<endl;
    cout << "b= "<<b<<endl;
}
//Exercise 3
int main (){
    cout <<"enter the size of the array: ";
    int n;
    cin >>n;
    double A[n];
    for (int i=0;i<n;i++){
        cout <<"Enter the "<<i<<" element of the array: ";
        cin >>A[i];
        cin.ignore();
    }
    double* ptr=A;
    cout << "-------------------------"<<endl;
    cout <<setw(12) <<"| The adress "<< " |"<<setw(8)<< "the value |"<<endl;
    cout << "-------------------------"<<endl;
    for (int i=0;i<n;i++){
        cout << "| "<<setw(12)<<ptr <<" |"<<setw(8)<< *ptr<<"|"<<endl;
        cout << "-------------------------"<<endl;
        ++ptr;
    }
}
//Exercise 4
float arraySum(float* arr,int n){
    float sum=0;
    for (int i=0;i<n;i++){
        sum+=*(arr+i);
    }
    return sum;
}
float matrixsum(float* M,int col,int row){
    float sum=0;
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            sum+=*M;
            M++;
        }
    }
    return sum;
}
int main(){
    cout <<"enter the size of the array: ";
    int n;
    cin >>n;
    int sum=0;
    float* arr= new float[n];
    for (int i=0;i<n;i++){
        cout <<"Enter the "<<i<<" element of the array: ";
        cin >>arr[i];
        cin.ignore();
    }
    sum=arraySum(arr,n);
    cout << "The sum of the array= "<<sum<<endl;

    cout << "Enter the number of rows: ";
    int row;
    cin>>row;
    cout << "Enter the number of columns: ";
    int col;
    cin>>col;
    float* Matrix = new float[row*col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Enter element M[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> Matrix[i * col + j];
        }
    }
    cout << "The sum of Matrix="<<matrixsum(Matrix,col,row)<<endl;
    delete[] arr;
    delete[] Matrix;
}/*
//Exercise 5
double* maximum (double* A, int n){
    double* max=A;
    if (A==nullptr){return NULL;}
    for (int i=0; i<n;i++){
        if (*max<*(A+i)){
            *max=*(A+i);
        }
    }
    return max;
}
int main (){
    cout << "Enter the number n of elments: ";
    int n;
    cin >>n;
    double* A= new double[n];
    for (int j = 0; j < n; ++j) {
            cout << "Enter element A[" << j + 1 << "]: ";
            cin >> *(A+j);
    }
    cout <<"The maximum value is: " <<*maximum(A,n)<<endl;
}/*
int main (){
    int* p ,a=8;
    p=&a;
    cout << "p++: "<<p<<endl;
    cout << "*P: "<<*p<<endl;
    p++;
    cout << "p++: "<<p<<endl;
    cout << "*P: "<<*p<<endl;
    p=&a;
    cout << "p++: "<<p<<endl;
    cout << "*P: "<<*p<<endl;
    (*p)++;
    cout << "p++: "<<p<<endl;
    cout << "*P: "<<*p<<endl;
    return 0;
}*/
/*
//Lab 15
//Exercise 1
int main (){
    int *var1 = new int;
    *var1=4;
    cout << *var1<<endl;
    float *var2=new float;
    *var2=5;
    cout<< *var2<<endl;
    delete var1;
    delete var2;
}
//Exercise 2
int main (){
    cout << "Enter the number of student: ";
    int n;
    cin >>n;
    int * A= new int [n];
    for ( int i=0; i<n; i++){
        cout << "Enter the data of the studesnt number: "<<i+1<<": ";
        cin >> *(A+i);
    }
    for ( int i=0; i<n; i++){
        cout << "student "<<i+1<<": "<<*(A+i)<<endl;
    }
}
//Exercise 3
int* splite(int *A1,int *A2,int n1,int n2,int p){
    int * A3= new int [n1+n2];
    for (int i=0;i<p;i++){
        *(A3+i)=*(A1+i);
    }
    for(int i=0;i<n2;i++){
        *(A3+i+p)=*(A2+i);
    }
    for (int i=p;i<n1;i++){
        *(A3+i+n2-1)=*(A1+i);
    }
    return A3;
}

int main (){
    int * A1= new int [5];
    for (int i=0;i<5;i++){
        *(A1+i)=i+8;
    }
    int * A2= new int [6];
    for (int i=0;i<5;i++){
        *(A2+i)=i*4;
    }
    int * A3=splite(A1,A2,5,6,4);
    for (int i=0;i<10;i++){
        cout <<*(A3+i)<<endl;
    }

    delete [] A3;
    delete [] A2;
    delete [] A1;
}
//Eint func(int x)
if (x > 20)
return 0;
ELSE{
IF (x % 2 == 1)
return 1 + func(x + 1);
else
return  1 + func(x + 3)}
//exrcise 1
#include <iomanip>
struct node
{
    int data;
    node *next;
};
//create a node
node* create_node(int value){
    node*newelement  =new node();
    newelement->next=nullptr;
    newelement->data=value;
    return newelement;
}
// display the linked list
void display(node *&head)
{
    node *p = head;
    cout << setw(15) << "The address " << setw(9) << " The data"<<endl;
    while (p != nullptr)
    {
        cout << setw(15) << p << setw(9) << p->data<<endl;
        p = p->next;
    }
}
// insert the begining
void insert_begining(node *&head, int v)
{
    node *target=create_node(v);
    node *p = new node;
    p = head->next;
    head->next = p;
}
// insert at the end
void insert_end(node *&head, int v)
{   
    node* new_tail=create_node(v);
    if (head==NULL){
        head->next=new_tail;
    }
    node*ptr=head;
    
    while (ptr->next)
    {
        ptr=ptr->next;
    }
    ptr->next=new_tail;
    new_tail->next=NULL;
    new_tail->data=v;
    delete ptr;
}

// search an element in the list
bool search(node *&head, int target)
{
    node *ptr = head;
    while (ptr != nullptr)
    {
        ptr->data = target;
        return true;
    }
    delete ptr;
    return false;
}
// delete node
void delete_node(node *&head, node *p)
{   
    if (head==NULL) return;
    if (p==head){
        head=head->next;
    }
    node * ptr =head->next;
    while (ptr->next != p)
    {
        ptr = ptr->next;
    }
    ptr->next = p->next;
    delete p;   
}
int main()
{
    node *head = NULL;
    create_node(5);
    insert_end(head, 3);
    insert_end(head, 8);
    insert_begining(head, 1);
    insert_begining(head, 20);
    cout << endl;
    display(head);
    cout <<search(head,450);
    delete head;
}
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

// Initialized head node 
Node* initialize() {
  Node* head = new Node();
  head->data = 0;
  head->next = NULL;
  return head;
}
// Reverses the linked list
void reverse(Node* &head) {

    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while(current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
}
// Insert new node at end 
void insert(Node*& head, int value) {

  Node* temp = head;
  
  // Allocate and set new node
  Node* newNode = new Node();
  newNode->data = value;
  newNode->next = NULL;

  // If empty, new node becomes head
  if(head == NULL) {
    head = newNode;
    return;
  }

  // Traverse to end
  while(temp->next) {
    temp = temp->next; 
  }
  
  // Insert at the last node
  temp->next = newNode;
}

// Print linked list
void print(Node* head) {
  while(head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {

  Node* head = initialize();
  
  insert(head, 5);
  insert(head, 8); 
  insert(head, 2);
  reverse(head);
  print(head);

  return 0;
}
*/
// void mystery(string a, string &b) {
// a.erase(0,1);
// // erase(size_t pos, size_t len)
// b += a[0];
// b.insert(3, "FOO"); // insert(size_t pos, const char* s)
// }
// int main() {
// string a = "Ensia", b = "Tree";
// mystery(a, b);
// cout << a << " " << b << endl;
// return 0; }
#include <iostream>
#include <cstring>

struct person {
    const char* name;
    int age;
    person* next;
};

void insert_in_order(person* &list, const char* n, int a) {
    person* new_person = new person;
    new_person->name = n;
    new_person->age = a;
    new_person->next = nullptr;
    
    person* tmp = new person;
    tmp->next = list;
    
    while (list) {
        if (strcmp(list->name, new_person->name) == 0) {
            new_person->next = list->next;
            list->next = new_person;
            return;
        }
        if (strcmp(list->name, new_person->name) > 0) {
            new_person->next = list;
            tmp->next = new_person;
            return;
        }
        tmp = list;
        list = list->next;
    }
    
    tmp->next = new_person;
}

void print_list(person* list) {
    while (list) {
        std::cout << "Name: " << list->name << ", Age: " << list->age << std::endl;
        list = list->next;
    }
}

int main() {
    person* head = nullptr;
    
    insert_in_order(head, "John", 30);
    insert_in_order(head, "Alice", 25);
    insert_in_order(head, "Bob", 35);
    insert_in_order(head, "Charlie", 40);
    
    print_list(head);
    
    return 0;
}