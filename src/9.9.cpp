#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> board_t;

int boardNumber = 1;

void printBoard(board_t &board) {
    cout << "Board " << boardNumber++ << endl << endl;
    cout << "  abcdefgh" << endl;
    for(int y = 0; y < 8; y++) {
        cout << 8 - y << " ";
        for(int x = 0; x < 8; x++) {
            cout << (board[x][y] == ' ' ? '.' : board[x][y]);
        }
        cout << " " << 8 - y << endl;
    }
    cout << "  abcdefgh" << endl << endl << endl;
}

bool canPlace(board_t &board, int x, int y) {
    // horizontal and vertical
    for(int i = 0; i < 8; i++) {
        if(board[x][i] == 'Q' || board[i][y] == 'Q') return false;
    }

    // down-right subdiagonal
    int x1 = x, y1 = y;
    while(x1 < 8 && y1 < 8) if(board[x1++][y1++] == 'Q') return false;

    // up-right subdiagonal
    x1 = x; y1 = y;
    while(x1 < 8 && y1 >= 0) if(board[x1++][y1--] == 'Q') return false;

    // down-left subdiagonal
    x1 = x; y1 = y;
    while(x1 >= 0 && y1 < 8) if(board[x1--][y1++] == 'Q') return false;

    // up-left subdiagonal
    x1 = x; y1 = y;
    while(x1 >= 0 && y1 >= 0) if(board[x1--][y1--] == 'Q') return false;

    return true;
}

void place(board_t &board, int x, int y) {
    board[x][y] = 'Q';
}

void remove(board_t &board, int x, int y) {
    board[x][y] = ' ';
}

void placeQueens(board_t &board, int queens, int x0, int y0) {
    if(queens == 0) {
        printBoard(board);
        return;
    }

    bool first = true;
    for(int y = 0; y < 8; y++) {
        for(int x = 0; x < 8; x++) {
            if(first) {
                first = false;
                x = x0;
                y = y0;
            }

            if(canPlace(board, x, y)) {
                place(board, x, y);
                placeQueens(board, queens - 1, x, y);
                remove(board, x, y);
            }
        }
    }
}

int main() {
    board_t board(8, vector<char>(8, ' '));
    placeQueens(board, 8, 0, 0);
    return 0;
}