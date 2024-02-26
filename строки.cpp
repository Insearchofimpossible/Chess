#include <iostream>
#include <string>
using namespace std;
int board[8][8] = { 0 }, iteration = 0;         
void resetBoard() {for (int i = 0; i < 8; i++) { for (int j = 0; j < 8; j++) board[i][j] = 0; }}
void setQueen(int i, int j) {
    for (int x = 0; x < 8; x++) {
        board[x][j]++;
        board[i][x]++;
        int d = j - i + x;
        if (0 <= d && d <= 7) { board[x][d] ++; }
        d = j + i - x;
        if (0 <= d && d <= 7) { board[x][d] ++; }
    } board[i][j] = -1;
}
void removeQueen(int i, int j) {
    for (int x = 0; x < 8; x++) {
        board[x][j]--;
        board[i][x]--;
        int d; d = j - i + x;
        if (0 <= d && d <= 7) { board[x][d] --; }
        d = j + i - x;
        if (0 <= d && d <= 7) { board[x][d] --; }
    } board[i][j] = 0;
}
bool tryQueen(int i) {
    bool result = false;
    for (int j = 0; j < 8; j++) {
        if (board[i][j] == 0) {
            setQueen(i, j);
            if (i == 7) { result = true; }
            else {
                result = tryQueen(i + 1);
                if (not result) removeQueen(i, j);
            }
        }
    }
    return result;
}

int main() {
    tryQueen(0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
}