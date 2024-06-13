#include<bits/stdc++.h>
using namespace std;
int solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1,false),path(A+1,false);
    vector<vector<int>> adj(A+1);
    for(vector<int>& v : B)
        adj[v[0]].push_back(v[1]);
    function<bool(int)> dfs=[&](int node)->bool{
        visited[node]=true;
        path[node]=true;
        for(int& neighnour : adj[node] ){
            if(path[neighnour])
                return true;
            if(dfs(neighnour))
                return true;
        }
        path[node]=false;
        return false;
    };
    for(int i=1;i<=A;i++)
        if(dfs(i))
            return true;
    return false;
}
int main(){
}