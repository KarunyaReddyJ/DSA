#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int node,edge;
}pi;
struct compare{
    bool operator()(pi const& p1,pi const& p2){
        return p1.edge>p2.edge;
    }
};
vector<int> dijsktra(vector<vector<pi>>& adj){
    priority_queue<pi,vector<pi>,compare> pq;
    vector<int> distances(adj.size(),INT_MAX);
    int src=0;
    distances[src]=0;
    pq.push({src,0});
    while(!pq.empty()){
        pi current=pq.top();
        pq.pop();
        for(pi& neighbour : adj[current.node]){
            int total_distance=neighbour.edge+current.edge;
            if(total_distance<distances[neighbour.node]){
                distances[neighbour.node]=total_distance;
                pq.push({neighbour.node,total_distance});
            }
        }
    }
    return distances;
}
int main(){
    vector<vector<pi>> adj={{{1,4},{2,2}},{{2,1}},{{3,1}},{{0,3}}};
    vector<int> distance=dijsktra(adj);
    for(int x : distance) cout<<x<<" ";
}