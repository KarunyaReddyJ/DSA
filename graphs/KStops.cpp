#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int distance,stopsTillNow,node;
}node;
typedef struct{
    int destionation,weight;
}edge;
struct compare{
    bool operator()(node const& n1,node const& n2){
        return n1.distance>n2.distance;
    }
};
int shortestPathWithKStops(vector<vector<edge>>& adj,int k,int src,int dest){
    queue<node> pq;
    vector<int> distances(adj.size(),INT_MAX);
    pq.push({0,0,src});
    distances[src]=0;
    while(!pq.empty()){
        node current=pq.front();
        pq.pop();
        if(current.node==dest && current.stopsTillNow<=k+1)
            return current.distance;
        for(edge & neighbour : adj[current.node] ){
            if(current.distance+neighbour.weight<distances[neighbour.destionation]){
                distances[neighbour.destionation]=current.distance+neighbour.weight;
                pq.push({current.distance+neighbour.weight,current.stopsTillNow+1,neighbour.destionation});
            }
        }
    }
    return INT_MAX;
}
int main(){
    vector<vector<edge>> adj={{{1,1},{2,5}},{{2,1}},{{3,1}},{}};
    cout<<shortestPathWithKStops(adj,1,0,3);
}