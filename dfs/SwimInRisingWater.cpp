#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMaxPath=INT16_MIN;
    int mini(vector<int> v){
        int minVal=v[0];
        for(int& x : v)
            minVal=min(x,minVal);
        return minVal;
    }
    int swimInWater(vector<vector<int>>& grid){
        stack<pair<int,int>> st;
        map<pair<int,int>,int> visited;
        function<int(int,int)> dfs=[&](int x,int y)->int{
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return minMaxPath;
            int left=0,right=0,top=0,bottom=0;
            if(x-1>=0){
                top=dfs(x-1,y);
                visited[{x-1,y}]=top;
            }
            else if(x+1>grid.size()){
                bottom=dfs(x+1,y);
                visited[{x+1,y}]=bottom;
            }
            else if(y-1>=0){
                left=dfs(x,y-1);
                visited[{x,y-1}]=left;
            }
            else if(y+1>grid[0].size()){
                right=dfs(x,y+1);
                visited[{x,y+1}]=right;
            }
            return mini({left,right,top,bottom});
        };
        return dfs(0,0);
    }
};