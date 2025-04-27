#include<iostream>
#include<unistd.h>
using namespace std;
//variable declaration
const int width=20,height=20;
int Map[width][height];
int score=0;
int headx,heady;
enum eDirection {
STOP = 0,
LEFT,
RIGHT,
UP,
DOWN
};
eDirection DIR;
void show(int M[][height]){
    system("clear");
    cout << "######################"<<endl;
    for (int i=0;i<20;i++){
        cout << "#";
        for (int j=0;j<20;j++){
            cout << M[i][j];
        }
        cout <<"#"<<endl;
    }
    cout << "######################"<<endl;
    cout <<"score: "<<score;
}
void Setup(bool &gameOver, eDirection &dir){
    gameOver=false;
    dir=STOP;
    headx=width/2;
    heady=height/2;
    Map[headx][heady]=0;
    int fruitx= rand%20 +0;
    int fruitx= rand%20 +0;
}
int main(){
    show(Map);

}