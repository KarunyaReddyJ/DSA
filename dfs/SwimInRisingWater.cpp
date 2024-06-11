#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mini(vector<int> v){
        int minVal=v[0];
        for(int& x : v)
            minVal=min(x,minVal);
        return minVal;
    }
    int swimInWater(vector<vector<int>>& grid){
        map<pair<int,int>,int> visited;
        set<pair<int,int>> vis;
        function<int(int,int)> dfs=[&](int x,int y)->int{
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return grid[x][y];
            vis.insert({x,y});
            int left=INT_MAX,right=INT_MAX,top=INT_MAX,bottom=INT_MAX;
            if(x-1>=0){
                if(vis.find({x-1,y})==vis.end()){
                    top=dfs(x-1,y);
                }
                //left=visited[{x-1,y}];
            }
            else if(x+1<grid.size()){
                if(vis.find({x+1,y})==vis.end())
                bottom=dfs(x+1,y);
            }
            else if(y-1>=0){
                if(vis.find({x,y-1})==vis.end())
                left=dfs(x,y-1);
                //visited[{x,y-1}]=left;
            }
            else if(y+1<grid[0].size()){
                if(vis.find({x,y+1})==vis.end())
                right=dfs(x,y+1);
                //visited[{x,y+1}]=right;
            }
            return max(grid[x][y],mini({left,right,top,bottom}));
        };
        return dfs(0,0);
    }
};