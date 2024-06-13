#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> schedule;
    vector<bool> path(numCourses,false),visited(numCourses,false);
    stack<int> st;
    for(vector<int>& v : prerequisites)
        adj[v[0]].push_back(v[1]);
    function <bool(int)> dfs=[&](int node)->bool{
        path[node]=true;
        visited[node]=true;
        for(int neighbour : adj[node]){
            if(path[neighbour]) return true;
            if(!visited[neighbour])
                if(dfs(neighbour)) return true;
        }
        path[node]=false;
        schedule.push_back(node);
        return false;
    };
    for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            if(dfs(i)) return {};
        }
    }
    return schedule;
}
int main(){
    vector<vector<int>> prerequisties={{1,0},{2,0},{3,1},{3,2}};
    vector<int> schedule=findOrder(4,prerequisties);
    for(int x : schedule)
        cout<<x<<" ";
}