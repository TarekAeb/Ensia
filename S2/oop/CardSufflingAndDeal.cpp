#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Card{
public:
    Card(int f=1,int s=1):face(f),suit(s){}
    static const string faces[];
    static const string suits[];
    string toString();
private:
    int face,suit;
};
string Card::toString(){
    return faces[face]+" of "+suits[suit];
}
const string Card::faces[]={"Ace", "Two", "Three", "Four", "Five", "Six","Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::suits[]={"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards{
public:
    DeckOfCards(){
        for (int i=0;i<13;i++){
            for (int j=0;j<4;j++){
                Deck.push_back(Card(i,j));
            }
        }
    }
    void shuffle();
    Card dealCard();
    bool moreCard();
private:
    vector<Card> Deck;
    int currentCard;
};
void DeckOfCards::shuffle(){
    for (int i=0;i<52;i++){
        int n = rand()%51;
        swap(Deck[i],Deck[n]);
    }   
}
Card DeckOfCards::dealCard(){
    return Deck[currentCard++];
}
bool DeckOfCards::moreCard(){
    return currentCard<52;
}


int main (){
    DeckOfCards A;
    A.shuffle();
    while (A.moreCard()){
        Card card=A.dealCard();
        cout << card.toString()<<endl;
    }
    return 0;
}