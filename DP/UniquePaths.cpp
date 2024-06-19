#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> dp;
public:
Solution(int n=100,int m=100):dp(m+1,vector<int>(n+1,-1)){};
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0) return 0;
        if(m==1 && n==1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=uniquePaths(m-1,n);
        int left=uniquePaths(m,n-1);
        dp[m][n]=up+left;
        return up+left;
    }
};
int main(){
    Solution s;
    int m,n;
    cin>>m>>n;
    cout<<s.uniquePaths(m,n);
}