#include <iostream>
#include <unistd.h>
using namespace std;
//variables
const int width=20;
const int height=20;
char MAP[width][height];
int score=0;
int x,y,fruitx,fruity;
bool gameOver;

//function to create the direction
enum eDirection {
    STOP= 0,
    LEFT='a',
    Right='d',
    UP='w',
    DOWN='s',
};
eDirection dir= STOP;

//function to intializate the board
void init(char MAP[width][height]){
    for (int i=0;i<width; i++){
        for(int j=0;j<height; j++){
            if (i==0 || j==0 || i==width-1 || j==height-1){
                MAP [i][j]= '#';
            }
            else MAP [i][j]=' ';
        }
    }

}

//show the interface
void Draw(char MAP[width][height]){
    system("clear");
    for (int i=0;i<width; i++){
        for(int j=0;j<height; j++){
           cout << MAP[i][j];
        }
        cout <<endl;
    }
    cout <<"score : " <<score<<endl;
}
//funtion to intializate the first inputs
void Setup(bool &gameOver, eDirection &dir){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    MAP[x][y]='O';
    fruitx= rand()% 20 + 0;
    fruity= rand()% 20 + 0;
    MAP[fruitx][fruity]='F';
    score =0;

}
//function to to input the direction
void input(){
    if (_kbhit()){
        switch (_getche()){
            case 'w':{
            dir=UP;
            break;
            }
            case 'a':{
                dir=LEFT;
                break;
            }
            case 's':{
                dir=DOWN;
                break;
            }
            case 'd':{
                dir=Right;
                break;
            }
            case 'x':{
                gameOver=true;
            }
            default :

                break;
        }
    }
}
//funtion 
void logic(int &x,int &y){
    switch (dir){
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        case LEFT:
        x--;
        break;
        case Right:
        x++;
        break;
        default:
        break;
    }

}
int main()
{

    cout <<Right<<R"(

███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗
██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝
███████╗██╔██╗ ██║███████║█████╔╝ █████╗
╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝
███████║██║ ╚████║██║  ██║██║  ██╗███████╗
╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝

 ██████╗  █████╗ ███╗   ███╗███████╗
██╔════╝ ██╔══██╗████╗ ████║██╔════╝
██║  ███╗███████║██╔████╔██║█████╗
██║   ██║██╔══██║██║╚██╔╝██║██╔══╝
╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗
 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
)";
init(MAP);
Setup(gameOver,dir);

while (!gameOver){
    Draw(MAP);
    input();
    logic(x,y);

}


    return 0;
}