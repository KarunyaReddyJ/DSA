//https://codeforces.com/problemset/problem/189/A
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int recur(int length,vector<int>& dp){
    if(length==0) return 0;
    if(length<0) return INT_MIN;
    if(dp[length]!=-1) return dp[length];
    int l1=INT_MIN,l2=INT_MIN,l3=INT_MIN;
    l1=1+recur(length-a,dp);
    l2=1+recur(length-b,dp);
    l3=1+recur(length-c,dp);
    dp[length]=max(l1,max(l2,l3));
    return dp[length];
}
void solve(){
    int n;
    cin>>n>>a>>b>>c;
    vector<int> dp(n+1,-1);
    cout<<recur(n,dp);
}
int main(){
    int t=1;
    while(t--) 
        solve();
}