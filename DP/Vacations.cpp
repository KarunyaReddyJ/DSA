//https://codeforces.com/problemset/problem/698/A
#include<bits/stdc++.h>
using namespace std;
int recursion(vector<int>& vacations,size_t level,int lastChoice,vector<vector<int>>& dp){
    if(level==vacations.size()) return 0;
    if(dp[level][lastChoice]!=-1) return dp[level][lastChoice];
    int rest=INT_MAX,gym=INT_MAX,contest=INT_MAX;
    rest=1+recursion(vacations,level+1,0,dp);
    int a=vacations[level];
    if((a==1|| a==3) && lastChoice!=2) contest=recursion(vacations,level+1,2,dp);
    if((a==2|| a==3) && lastChoice!=1) gym=recursion(vacations,level+1,1,dp);
    dp[level][lastChoice]=min(rest,min(gym,contest));
    return dp[level][lastChoice];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3,-1));
    vector<int> vacations(n);
    for(int& x : vacations) cin>>x;
    cout<<recursion(vacations,0,0,dp); // initially i tok lastCoice as -1 assuming intially ihavent chose any work but encountered error as i was using it as index in an array later changed to 0 
}