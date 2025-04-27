#include <iostream>

using namespace std;
/*exercise 1
int main()
{
    cout << "Enter ten numbers" << endl;
    int array [10],number=0,i=0;

    for (i=0;i<=9;i++) {cin >> array[i];
    if (array[i]%2==0){
        number++;
    }}
    cout<< "the number of even number is "<< number;
    return 0;
}*/
int main (){
cout << "Enter ten numbers between 0 and 20" << endl;
    int array [10],i=0,j=0;

    for (i=0;i<=9;i++) {
            X:
            cin >> array[i];
            if (array[i] <=20 && array[i] >=0){
                 }
            else {cout<< "enter a number between 0 and 20";
            goto X; }

}for (j=0; j<=9;j++) cout<< array[j]<< ", " ;
}
