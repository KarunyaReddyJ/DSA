//https://codeforces.com/problemset/problem/1829/D
#include<bits/stdc++.h>
using namespace std;
bool recursion(int n,int m){
    if(n==m) return true;
    if(n%3 || n<m) return false;
    int x=n/3;
    if(recursion(x,m)) return true;
    return recursion(2*x,m);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> dp(n+1,-1);
    if(recursion(n,m)) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}