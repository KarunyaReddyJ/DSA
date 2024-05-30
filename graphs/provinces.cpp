#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& isConnected,vector<bool>& visited,int start){
    stack<int> s;
    s.push(start);
    while(s.size()){
        int x=s.top();
        s.pop();
        if(visited[x])
            continue;
        for(int y=0;y<isConnected.size();y++){
            if(!visited[y] && isConnected[x][y] && x!=y)
                s.push(y);
        }
        visited[x]=true;
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int provinces=0;
    vector<bool> visited(isConnected.size(),false);
    for(int i=0;i<isConnected.size();i++){
        if(!visited[i]){
            dfs(isConnected,visited,i);
            provinces++;
        }
    }
    return provinces;
}
int main(){
    vector<vector<int>> v={{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(v);
}