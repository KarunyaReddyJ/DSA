#include<bits/stdc++.h>
using namespace std;
int breakRecords(int A, vector<vector<int> > &B) {
    int components=0;
    vector<bool> visited(A+1,false);
    vector<vector<int>> adj(A+1);
    for(const vector<int>&v : B){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    for(int i=1;i<=A;i++){
        if(!visited[i]){
            visited[i]=true;
            components++;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int k=q.front();
                q.pop();
                for(int& x : adj[k]){
                    if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
                }
            }
        }
    }
    return components;
}
int main(){
    vector<vector<int>> B={{1,2},{3,4},{2,4}};
    int A=4;
    cout<<breakRecords(A,B);
}