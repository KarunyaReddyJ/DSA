#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> adj){
    stack<int> st;
    vector<bool> visited(adj.size()+1,false);
    function <void(int)> dfs=[&](int node){
        visited[node]=true;
        for(int neighnour : adj[node])
            if(!visited[neighnour])
                dfs(neighnour);
        st.push(node);
    };
    for(int i=0;i<adj.size();i++){
        if(!visited[i])
            dfs(i);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    vector<vector<int>> adj={{},{0,2},{3},{},{0,5},{3}};
    vector<int> topo=topologicalSort(adj);
    for(int& x : topo)
        cout<<x<<" ";
}