#include<bits/stdc++.h>
using namespace std;

int shotestPath(vector<vector<int>>& adj,pair<int,int> src,pair<int,int> dest){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> distances(adj.size(),vector<int>(adj[0].size(),INT_MAX));
    pq.push({0,src});
    auto setAs=[&](int d,pair<int,int> point){
        distances[point.first][point.second]=d;
    };
    vector<pair<int,int>> directions={
        {-1,0},{1,0},{0,1},{0,-1}
    };
    setAs(0,src);
    while(!pq.empty()){
        auto current=pq.top();
        pq.pop();
        auto node=current.second;
        int distance=current.first;
        if(node.first==dest.first && node.second==dest.second)
            return distance+1;
        for(auto di : directions){
            int x=node.first+di.first,y=node.second+di.second;
            if(x<0 || y<0 || x>=adj.size()|| y>=adj[0].size()) continue;
            if(adj[x][y]==1 && distances[x][y]>distance+1){
                pq.push({distance+1,{x,y}});
                setAs(distance+1,{x,y});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> adj={{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,0}};
    cout<<shotestPath(adj,{0,0},{2,2});
}