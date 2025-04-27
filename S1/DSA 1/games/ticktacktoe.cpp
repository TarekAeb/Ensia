#include <iostream>
#include <chrono>
#include<thread>
#include<string>
using namespace std;

int showBoard (char board[], int i){
    cout <<"press 1 to restore.\n2 to exit,\n3 for more information about the game,\n4 to resume";
    int n;
    cin >>n;
    switch (n){
    case 1 :{board [i]=' ';
    return 0;}
    case 2 :{cout<<"exiting..."<<endl;
    return 1;}
    case 3 :{cout <<"Game Guide:\nThe Tic-Tac-Toe game rigorously evaluates the winning condition following each player’s move, continuously inspecting the 1x9 game board for patterns indicative of victory. The winning criteria are fulfilled when a player successfully places three markers consecutively in a row, either horizontally, vertically, or diagonally within the linear structure of the 1x9 gameboard."<<endl;
    return 0;}
    case 4:return 0;
    }
    return 0;
    }

void placeMark (char board[]){
    cout << "-------------" << endl;
    for (int i = 0; i < 9; ++i) {
        cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "|" << endl;
            cout << "-------------" << endl;
        }
    }}
//function to check win
bool checkWin (char board[]){
    for (int i=0;i<6 ;i+=3){
        if ((board[i]=='X' && board[i+1]=='X'&& board[i+2]=='X')||(board[i]=='O' && board[i+1]=='O'&& board[i+2]=='O')){
            return true;
        } 
    }
    for (int i=0; i<3; i++){
        if ((board[i]=='X' &&  board[i+3]=='X' && board[i+6]=='X')||(board[i]=='O' &&  board[i+3]=='O' && board[i+6]=='O')){
            return true;
        } 
    }
    if ((board[0]=='X'&& board[4]=='X' && board[8]=='X')||(board[0]=='O'&& board[4]=='O' && board[8]=='O')||(board[2]=='X' &&board[4]=='X' && board[6]=='X')||(board[2]=='O' &&board[4]=='O' && board[6]=='O')){
        return true;
    }
    return false;
}
//function to check tie
bool checkTie(char board[]){
    for (int i=0 ; i<9;i++){
        if (board[i]==' '){
        return false;
        }
    }
    return false;
    }
//main block
int main(){
    char board [9]= {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int n,currentPlayer=1;
    char X='X',currentPlay= X, O='O';

    cout << "\033[32m";
    cout <<"Welcome to Tic-Tac-Toe game!\n";
    cout << "\033[0m";
    cout <<" Player 1: X \n Player 2: O"<<endl;
    placeMark(board);
    while (!checkTie(board) && !checkWin(board)){
        if (currentPlay=='X'){currentPlayer=1;}
        else {currentPlayer=2;}
        cout << "Player "<<currentPlayer<<" it is your turn!"<<endl;
        cout << "where do you want to play(1-9)? ";
        cin>>n;
        if (n<9 && n>=0 && board[n]==' '){
            board [n]=currentPlay;
            placeMark(board);
            if (checkWin(board)){cout << "the player"<<currentPlayer<<" win!"<<endl; return 0;}
            if (checkTie(board)){cout << "it is a tie!"<<endl; return 0;}
            if (showBoard(board,n)==1){return 0;}
            if (currentPlay==X){currentPlay=O;}
            else currentPlay=X;
            }
        else {cout << "place token choose another one"<<endl; continue;}}
    return 0;
}
