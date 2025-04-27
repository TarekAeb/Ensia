#include<iostream>
using namespace std;

struct term{
  int coeffecient,exponent;
  term *next; 
};

void insert_term(term*head,int coefficient, int exponent){
  term* newt=new term;
  while (head->next)
  {
    head=head->next;
  }
  newt->coeffecient=coefficient;
  newt->exponent=exponent;
  newt->next=NULL;
  head->next=newt;
}

void deleteTerm(term* head,int exponent){
  term *temp;
  while (head && head->next->exponent!=exponent){
    head=head->next;
  }
  temp=head;
  head->next=head->next->next;
  delete temp->next;
}

int evaluateExpression(term* head,int x){
  
}