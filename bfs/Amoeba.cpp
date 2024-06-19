//https://atcoder.jp/contests/abc274/tasks/abc274_c
#include<bits/stdc++.h>
using namespace std;
void findGenerationsOfAmoabae(int n,vector<int> splits){
    vector<vector<int>> adj(2*n+1);
    for(int i=1;i<=n;i++){
        adj[splits[i-1]-1].push_back(2*i);
        adj[splits[i-1]-1].push_back(2*i+1);
    }
    queue<pair<int,int>> q;  //first=node,second=generation
    q.push({1,0});
    vector<int> generations(2*n+1,0);
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int generation=p.second,node=p.first;
        for(int& neighbour : adj[node-1]){
            q.push({neighbour,generation+1});
            generations[neighbour-1]=generation+1;
        }
    }
    for(int& x : generations)
        cout<<x<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> splits(n,0);
    for(int& x : splits)
        cin>>x;
    findGenerationsOfAmoabae(n,splits);
}