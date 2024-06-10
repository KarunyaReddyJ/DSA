#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int node,vector<int>& path,int target,vector<vector<int>>& paths,vector<vector<int>>& graph){
    path.push_back(node);
    if(node==target)
        paths.push_back(path);
    else{
        for(int x : graph[node])
            dfs(x,path,target,paths,graph);
    }
    path.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(0,path,graph.size()-1,paths,graph);
        return paths;
    }
};
int main(){
    Solution solution=Solution();
    vector<vector<int>> graph={{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> ans=solution.allPathsSourceTarget(graph);
    for(auto& v : ans){
        for(int x : v)
            cout<<x<<" ";
        cout<<endl;
    }
}