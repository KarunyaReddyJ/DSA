#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
struct compare {
    bool operator()(pi const& p1,pi const& p2){
        return p1.second>p2.second;
    }
};
vector<int> uniformCostSearch(vector<vector<pi>>& adj,int start){
    vector<bool> visited(adj.size(),false);
    priority_queue<pi,vector<pi>,compare> pq;
    vector<int> costs(adj.size(),INT_MAX);
    pq.push({start,0});
    costs[start]=0;
    while(!pq.empty()){
        pi current=pq.top();
        pq.pop();
        if(visited[current.first]) continue;
        visited[current.first]=true;
        for(pi& neighbour : adj[current.first]){
            int currentCost=neighbour.second+current.second;
            if(costs[neighbour.first]>currentCost){
                costs[neighbour.first]=currentCost;
                pq.push({neighbour.first,currentCost});
            }
        }
    }
    return costs;
}
void ucsForAll(vector<vector<pi>>& adj){
    for(int i=0;i<adj.size();i++){
        vector<int> costs=uniformCostSearch(adj,i);
        cout<<"start "<<i<<endl;
        for(size_t i=0;i<costs.size();i++)
            cout<<i<<"->"<<costs[i]<<endl;
        cout<<endl;
    }
}
int main(){
    vector<vector<pi>> adj={{{1,4},{2,2}},{{2,1}},{{3,1}},{{0,5}}};
    ucsForAll(adj);
}