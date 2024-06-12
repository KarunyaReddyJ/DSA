#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int paths=0;
    stack<int> st;
    vector<vector<int>> adj(A.size()+1);
    for(vector<int>& v : B)
        adj[min(v[0],v[1])].push_back(max(v[1],v[0]));
    int good=0;
    function <void(int)> dfs=[&](int node){
        good+=A[node-1];
        if(good>C){
            good-=A[node-1];
            return;
        }
        else if(adj[node].size()==0){
            paths++;
            good-=A[node-1];
            return;
        }
        for(int x : adj[node])
            dfs(x);
        good-=A[node-1];
    };
    dfs(1);
    return paths;
}
int main(){
    vector<int> A={1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1};
    vector<vector<int>> B={{10, 6},
  {3, 2},
  {12, 7},
  {9, 5},
  {2, 1},
  {8, 3},
  {7, 1},
  {4, 2},
  {6, 3},
  {11, 4},
  {5, 3},
  {13, 11}};
cout<<solve(A,B,7);
}