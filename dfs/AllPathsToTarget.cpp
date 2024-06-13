#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void dfs(int node,vector<int>& path,int target,vector<vector<int>>& paths,vector<vector<int>>& graph,vector<bool>& pathVisited){
	    path.push_back(node);
	    pathVisted[node]=true;//cycle detection
	    if(node==target)
	        paths.push_back(path);
	    else{
	        for(int x : graph[node])
	        if(!pathVisited[x])
	            dfs(x,path,target,paths,graph);
	    }
	    pathVisited[node]=false;
	    path.pop_back();
	}
	
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<bool> pathVisited(graph.size(),false);
        vector<int> path;
        dfs(0,path,graph.size()-1,paths,graph,pathVisited);
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
