#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int r, int c) {
    for (int i = 0; i < r; i++)
        if (board[i][c] == 'Q')
            return false;
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = r, j = c; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
int c=0;
void NQueen(vector<string>& board, int r ,int& answers) {
    if (r == board.size()) {
     answers++;
        return;
    }

    for (int c = 0; c < board.size(); c++) {
        if (isSafe(board, r, c)) {
            board[r][c] = 'Q';
            NQueen(board, r + 1,answers);
            board[r][c] = '.';
        }
    }
    return;
}
int solveNQueens(int n) {
    string s(n, '.');
    int answers=0;
    vector<string> board(n, s);
    NQueen(board,0,answers);
    return answers;
    }
int main() {
    int n;
    cin >> n;
    cout<<solveNQueens(n);
    return 0;
}
