#include<bits/stdc++.h>
using namespace std;
using i64=long long;
class Solution{
    int totalZeroes(int x){
        int count=0,i=~x;
        while(i){
            i=i&(i-1);
            count++;
        }
        return count-61;
    }
    public:
    void solve(){
        i64 days;cin>>days;
        vector<vector<i64>> data(3,vector<i64>(days));
        vector<vector<i64>> dp(8,vector<i64>(days+1,INT64_MIN));
        for(auto &v : data) for(auto &x : v) cin>>x;
        for(int i=0;i<=days;i++) dp[7][i]=0;
        for(int i=days-1;i>-1;i--){
            for(int j=7;j>-1;j--){
                int zrs=totalZeroes(j);
                if(zrs>days-i){ 
                    dp[j][i]=INT64_MIN;
                    continue;
                }
                i64 l1=dp[j][i+1];
                for(int k=0;k<3;k++)
                    if((j&(1<<k))==0) 
                        l1=max(l1,data[k][i]+dp[j|(1<<k)][i+1]);
                dp[j][i]=l1;
            }
        }
        cout<<dp[0][0]<<endl;
    }
};
int main(){
    int t;cin>>t;
    while(t--){
        Solution s;
        s.solve();
    }
}