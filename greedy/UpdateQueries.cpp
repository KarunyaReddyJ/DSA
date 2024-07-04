#include<bits/stdc++.h>
using namespace std;
class Solution{
    int n,m,x;
    string s;
    char c;
    public:
    void solve(){
        cin>>n>>m;
        cin>>s;
        set<int>indices;
        for(int i=0;i<m;i++){
            cin>>x;
            indices.insert(x);
        }
        priority_queue<char,vector<char>,greater<char>> pq;
        for(int i=0;i<m;i++){
            cin>>c;
            pq.push(c);
        }
        for(int x : indices){
            s[x-1]=pq.top();
            pq.pop();
        }
        cout<<s<<endl;
    }
    
};
int main(){
    int t;
    cin>>t;
    while(t--){
        Solution s=Solution();
        s.solve();
    }
}