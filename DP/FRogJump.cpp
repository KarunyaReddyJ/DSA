#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> heights(n),dp(n,INT_MAX);
    //p1 two steps
    // for(int& x : heights) cin>>x;
    // int x1=abs(heights[n-1]-heights[n-2]),x2=0;
    // for(int i=n-3;i>=0;i--){
    //     int y=min(abs(heights[i]-heights[i+1])+x1,abs(heights[i]-heights[i+2])+x2);
    //     x2=x1;x1=y;
    // }
    // cout<<x1;

    //k steps
    int k;cin>>k;
    for(int& x : heights) cin>>x;
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<=i+k;j++)
        if(j<n)
            dp[i]=min(dp[i],abs(heights[i]-heights[j])+dp[j]);
    }
    cout<<dp[0];
}