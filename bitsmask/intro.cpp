#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;  
    vector<vector<int>> C(n,vector<int>(n));
    for(vector<int>& v : C) for(int& x : v) cin>>x;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p,q;
    for(int i=0;i<n;i++)
        p.push({C[n-1][i],1<<i});
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &u=p,&v=q;
    queue<pair<int,int>> tempQueue;
    for(int i=n-2;i>-1;i--){
        for(int j=0;j<n;j++){
            while(!u.empty() && u.top().second&(1<<j)){
                tempQueue.push(u.top());
                u.pop();
            }
            if(!u.empty()){
                pair<int,int> top=u.top();
                top.second|=1<<j;
                v.push({top.first+C[i][j],top.second});
            }
            while(!tempQueue.empty()){
                u.push(tempQueue.front());
                tempQueue.pop();
            }
        }
        while(!u.empty()) u.pop();
        swap(u,v);
    }
    cout<<u.top().first;
}