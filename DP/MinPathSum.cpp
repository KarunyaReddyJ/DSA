#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp;
public:
Solution(): dp(200,vector<int>(200,-1)) {};
    int recursion(vector<vector<int>>& grid,int x,int y){
        if(x<0 || y<0) return INT_MAX;
        if(x==0 && y==0) return grid[x][y];
        if(dp[x][y]!=-1) return dp[x][y];
        int up=INT_MAX,left=INT_MAX;
        up=recursion(grid,x-1,y);
        left=recursion(grid,x,y-1);
        dp[x][y]=grid[x][y]+min(up,left);
        return dp[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return recursion(grid,grid.size()-1,grid[0].size()-1);
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid={{1,2,3},{4,5,6}};
    cout<<s.minPathSum(grid);
}