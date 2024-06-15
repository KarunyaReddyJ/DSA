//https://atcoder.jp/contests/abc211/tasks/abc211_d
#include<bits/stdc++.h>
using namespace std;
int bfs(int n,vector<vector<int>>& adj){
    queue<pair<int,int>> q;
    vector<int> distances(n+1,INT_MAX);
    int count=0;
    q.push({1,0});
    distances[1]=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        if(p.first==n){
            if(p.second==distances[n])
                count++;
            else if(p.second<distances[n]){
                distances[n]=p.second;
                count=1;
            }
            else
                break;
            continue;
        }
        for(int& neighbour : adj[p.first]){
            if(distances[neighbour]>=p.second+1){
                distances[neighbour]=p.second+1;
                q.push({neighbour,p.second+1});
            }
        }
    }
    return count;
}
int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<bfs(n,adj);
}