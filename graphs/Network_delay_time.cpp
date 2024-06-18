#include<bits/stdc++.h>
using namespace std;
struct edge{
    int destination,weights;
};
struct compare{
    bool operator()(edge const& e1,edge const& e2){
        return e1.weights>e2.weights;
    }
};
class Solution {
private:
    int maxEdge=INT_MIN;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> adj(n+1);
        priority_queue<edge,vector<edge>,compare> pq;
        vector<int> distances(n+1,INT_MAX);
        for(vector<int> const& v : times)
            adj[v[0]].push_back({v[1],v[2]});
        distances[k]=0;
        pq.push({k,0});
        while(!pq.empty()){
            edge current=pq.top();
            pq.pop();
           // if(maxEdge<current.weights) maxEdge=current.weights;
            for(edge& e : adj[current.destination]){
                if(distances[e.destination]>current.weights+e.weights){
                    distances[e.destination]=current.weights+e.weights;
                    pq.push({e.destination,current.weights+e.weights});
                }
            }
        }
        for(int i=1; i<n+1;i++){
         if(distances[i]==INT_MAX) 
            return -1;
            maxEdge=max(maxEdge,distances[i]);
        }
        return maxEdge;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> times={{1,2,1},{2,3,2},{1,3,4}};
    cout<<sol.networkDelayTime(times,3,1);
}