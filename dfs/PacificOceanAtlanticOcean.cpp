#include<bits/stdc++.h>
using namespace std;

void dfs(int r,int c,vector<vector<int>>& heights,set<pair<int,int>>& both,bool& p,bool& a){
    if(both.find({r,c})!=both.end()){
        p=true;
        a=true;
        return;
    }
    vector<int> x={-1,1,0,0},y={0,0,-1,1};
    for(int i=0;i<4;i++){
        int X=x[i],Y=y[i];
        if(r+X<0 || c+Y<0){
            p=true;
            if(a)
                return;
        }
        else if(r+X>=heights.size() || c+Y>=heights[0].size()){
            a=true;
            if(p)
                return;
        }
        if(heights[r+X][c+Y]<=heights[r][c]) 
            dfs(r+X,c+Y,heights,both,p,a);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
     set<pair<int,int>> both;
     vector<vector<int>> ans;
     for(int i=0;i<heights.size();i++){
        vector<int> v;
        for(int j=0;j<heights[0].size();j++){
            bool a=false,p=false;
            dfs(i,j,heights,both,p,a);
            if(a&&p){
                both.insert({i,j});
                v.push_back(i);
                v.push_back(j);
                ans.push_back(v);
            }
        }
     }
     return ans;
}
int main(){

}