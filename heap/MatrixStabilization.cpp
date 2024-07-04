#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for(auto& arr : matrix){
            for(int& x : arr) cin>>x;
        }
        vector<pi> dir={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        auto isStrictlyGreater=[&](int r,int c)->pair<bool,int>{
            bool isstrictlygreater=true;
            int nextGreater=INT_MIN;
            for(pi& p : dir){
                int n_r=p.first+r,n_c=p.second+c;
                if(n_r>=0 && n_r<n && n_c>=0 && n_c<m){
                     isstrictlygreater&=(matrix[r][c]>matrix[n_r][n_c]);
                     nextGreater=max(nextGreater,matrix[n_r][n_c]);
                }
            }
            return {isstrictlygreater,nextGreater};
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isStrictlyGreater(i,j).first)
                    pq.push({i,j});
            }
        }
        while(!pq.empty()){
            pi top=pq.top();
            pq.pop();
            auto p=isStrictlyGreater(top.first,top.second);
            matrix[top.first][top.second]=p.second;
        }
        for(auto& arr : matrix){
            for(int& x : arr) cout<<x<<" ";
            cout<<endl;
        }
    }
}