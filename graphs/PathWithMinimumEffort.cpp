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
        auto node=pq.top().second;
        pq.pop();
        if(node.first==dest.first && node.second==dest.second)
            return distances[dest.first][dest.second];
        for(auto di : directions){
            int x=node.first+di.first,y=node.second+di.second;
            if(x<0 || y<0 || x>=adj.size()|| y>=adj[0].size()) continue;
            else if(distances[x][y]>abs(adj[x][y]-adj[node.first][node.second])){
                pq.push({abs(adj[x][y]-adj[node.first][node.second]),{x,y}});
                setAs(abs(adj[x][y]-adj[node.first][node.second]),{x,y});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> adj={{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout<<shotestPath(adj,{0,0},{3,4});
}