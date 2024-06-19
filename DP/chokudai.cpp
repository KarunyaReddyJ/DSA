//https://atcoder.jp/contests/abc211/tasks/abc211_c
#include<bits/stdc++.h>
using namespace std;
string s,req="chokudai";
int length,mod=1000000007;
vector<vector<int>> dp(8,vector<int>(1e5,-1));
int recursion(int level,int ind){
    //base case
    if(level==8) return 1;
    //pruning
    if(ind==length) return 0;
    //exploring choices
    int chosen=0,notChosen=0;
    if(dp[level][ind]!=-1) return dp[level][ind];
    if(s[ind]==req[level]) chosen=recursion(level+1,ind+1);
    notChosen=recursion(level,ind+1);
    dp[level][ind]=(chosen%mod+notChosen%mod)%mod;
    return dp[level][ind];
}
void solve(){
    cin>>s;
    length=s.length();
    cout<<recursion(0,0);
}
int main(){
    int t=1;
    for(int i=1;i<=t;i++) solve();
}