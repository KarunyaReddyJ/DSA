#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0) return 0;
        vector<vector<int>> dp=triangle;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++) dp[i][j]+=min(dp[i+1][j],dp[i+1][j+1]);
        }
        return dp[0][0];
    }
};
int main(){
    Solution s;
    vector<vector<int>> triangle={{-10}};
    cout<<s.minimumTotal(triangle);
}