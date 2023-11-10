#include <iostream>
using namespace std;

const int ROWS = 20;
const int COLS = 20;

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '#';
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main() {
    initializeBoard();
    board[5][5] = 'P';
    printBoard();
    return 0;
}
