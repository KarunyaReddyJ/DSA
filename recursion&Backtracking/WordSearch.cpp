#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        visited=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && exploreTheBoard(board,word,i,j)) 
                    return true;
            }
        }
        return false;
    }
private:
bool inBound(int var,int lowerBound,int upperBound){
    return var<upperBound && var>lowerBound;
}
    bool exploreTheBoard(vector<vector<char>>& board, string word,int x,int y,int index=1){
        if(index==word.size()) return true;
        visited[x][y]=true;
        for(vector<int> v: directions){
            int dx=v[0],dy=v[1];
            if(inBound(x+dx,-1,board.size()) && inBound(y+dy,-1,board[0].size())  &&  !visited[x+dx][y+dy] && board[x+dx][y+dy]==word[index] && exploreTheBoard(board,word,x+dx,y+dy,index+1)){
                return true;
            }
        }
        visited[x][y]=false;
        return false;
    }
};

int main(){
    vector<vector<char>> board={{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
    string str="abcd";
    Solution s;
    cout<<s.exist(board,str);
}