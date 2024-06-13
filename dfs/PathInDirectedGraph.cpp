#include<bits/stdc++.h>
using namespace std;
int solve(int A, vector<vector<int> > &B) {
    vector<bool> visited(A+1,false);
    vector<vector<int>> adj(A+1);
    for(vector<int>& v : B)
        adj[v[0]].push_back(v[1]);
    function <bool(int)> dfs=[&](int node)->bool{
        if(node==A)
            return true;
        for(int& neighbour : adj[node]){
            if(!visited[neighbour]){
                visited[neighbour]=1;
                if(dfs(neighbour)) return true;
            }
        }
        return false;
    };
    return dfs(1);
}
int main(){

}