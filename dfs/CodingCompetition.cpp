#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
class Solution {
    unordered_map<int,vector<int>> adj;
    queue<pi> q;
    unordered_map<int,int> nodesAtDepth;
    private:
    public:
    int solve() {
        int n, x,path=1;
        cin >> n;
        for(int i=2;i<=n;i++){
            cin>>x;
            adj[x].push_back(i);
        }
        q.push({1,0});
        while(!q.empty()){
            auto [node,depth]=q.front();
            q.pop();
            for(int& x : adj[node]){
                q.push({x,depth+1});
                nodesAtDepth[depth+1]++;
            }
        }
        int teams=0,rem=0;
        for(auto& x : nodesAtDepth){
            teams+=(x.second)/2;
            if(x.second>1)
            rem+=x.second%2;
        }
        teams+=rem/2;
        return teams;
    }
};

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    
    int t;
    cin >> t;
    while (t--) {
        Solution s;
        cout  << s.solve() << endl;
    }
    
    return 0;
}
