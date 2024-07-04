#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool solved;
public:
Solution(){
    solved=false;
}
    void solveSudoku(vector<vector<char>>& board,int row=0,int col=0) {
        if(row==board.size()) {
            solved=true;
            return;
        }
        if(board[row][col]!='.'){
            solveSudoku(board,row+(col+1)/9,(col+1)%9);
            return;
        }
        for(char c='1';c<='9';c++){
            if(isSafe(board,row,col,c)){ 
                board[row][col]=c;
                solveSudoku(board,row+(col+1)/9,(col+1)%9);
            }
            if(solved) return;
            else board[row][col]='.';
        }
    }
private:
    bool isSafe(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++) 
            if(board[row][i]==c || board[i][col]==c) return false;
        int rowFactor=row/3,colFactor=col/3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(board[rowFactor*3+i][colFactor*3+j]==c) return false;
        return true;
    }
};
int main(){
    vector<vector<char>> board={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    s.solveSudoku(board);
    for(const vector<char>& v : board ){
        for(const char& c : v) cout<<c<<" ";
        cout<<endl;
    }
}