/*#include <iostream>

using namespace std;

int main()
{
    int num0=0,num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0,result;


     for (num1=0; num1=9; num1++){
       for (num2=0; num2=9; num2++){
         for (num3=0; num3=9; num3++){
           for (num4=0; num4=9; num4++){
             for (num6=0; num6=9; num6++){
               for (num7=0; num7=9; num7++){
                 for (num8=0; num8=9; num8++){
                   for (num9=0; num9=9; num9++){

                        num0=num1+num2*10+num3*100+4000+num4*10000;
                        num5= 509+num6*10;
                        result=7000392+ num7*1000+num8*10000+num9*100000;

                         if((num0*num5)== result){cout<<" num0= "<<num0<<" num6= "<<num5<<" result "<<result;
                         return 0;}



                                                }
                                              }
                                             }
                                           }
                                         }
                                       }
                                     }
                                   }
 return 0;
}

#include<iostream>
#include<string>
using namespace std;
void fun (string str){
  int space=0,numeric=0,spe_char=0,upper=0,lower=0;
  for (char ch : str){
    if (isspace(ch)){space++;}
    else if(isupper(ch)){
      upper++;
    }
    else if (islower(ch)){
      lower++;
    }
    else if(isdigit(ch)){
      numeric++;
    }
    else spe_char++;
  }
  std::cout << "Uppercase letters: " << upper << std::endl;
  std::cout << "Spaces letters: " << space << std::endl;
  std::cout << "Lowercase letters: " << lower << std::endl;
  std::cout << "Numerical values: " << numeric << std::endl;
  std::cout << "Special characters: " << spe_char << std::endl;
}
int main(){
  string phrase;
  cout <<"Enter a phrase: "<<endl;
  getline(cin,phrase);
  fun(phrase);
  return 0;
}*/
//Exercise 3 TP pointers

