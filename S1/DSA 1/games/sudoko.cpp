#include <iostream>
using namespace std;

int M[9][9] ={
    {0, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

int A[10] = {0}; // Changed size to 10 to include indices 1-9

// Function to display the board
void showBoard(int M[][9]) {
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << "| " << M[i][j] << ' ';
            if (j == 8) {
                cout << '|' << endl << "-------------------------------------" << endl;
            }
        }
    }
}

// Function to check tie
bool checkTie(int board[][9]) {
    if (!checkTie(M)) return false;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to check win
bool checkWin(int M[][9]) {
    // Check rows
    for (int i = 0; i < 9; i++) {
        fill(A, A + 10, 0); // Reset the array for each iteration
        for (int j = 0; j < 9; j++) {
            if (A[M[i][j]] > 0) {
                return false;
            }
            A[M[i][j]]++;
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        fill(A, A + 10, 0); // Reset the array for each iteration
        for (int i = 0; i < 9; i++) {
            if (A[M[i][j]] > 0) {
                return false;
            }
            A[M[i][j]]++;
        }
    }

    // Check 3x3 subgrids
    for (int n = 0; n < 9; n += 3) {
        for (int m = 0; m < 9; m += 3) {
            fill(A, A + 10, 0); // Reset the array for each subgrid
            for (int i = n; i < n + 3; i++) {
                for (int j = m; j < m + 3; j++) {
                    if (A[M[i][j]] > 0) {
                        return false;
                    }
                    A[M[i][j]]++;
                }
            }
        }
    }

    return true;
}


// Main block
int main() {
    int x, y, n;
    cout << "\033[32m";
    cout << "Welcome to sudoku\n";
    cout << "\033[0m" << endl;
    cout << "The game preferences:\nYou need to choose the coordinate of the cell then the number you wish to store in it" << endl;
    while (!checkWin(M) && !checkTie(M)) {
        cout << "Enter the coordinate (x, y) of the cell:\nx: ";
        cin >> x;
        cin.ignore();
        cout << "y: ";
        cin >> y;
        cin.ignore();
        cout << "Enter a number (1-9): ";
        cin >> n;

        if (n >= 1 && n <= 9 && M[x][y]==0 && x<9 && x>=0 && y<9 && y>=0) {
            M[x][y] = n;
            showBoard(M);
        } else {
            cout << "Non-valid number (maybe placed token or number out of range!)" << endl;
            continue;
        }
    }

    if (checkWin(M)) {
        cout << "Congratulations! You win!" << endl;
    } else {
        cout << "It's a tie" << endl;
    }

    return 0;
}
