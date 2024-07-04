//https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum,int index=0,int calculatedSum=0){
        // code here 
        inline vector<vector<int>> dp(100,vector<int>(101,-1));
        if(calculatedSum==sum) return true;
        if(index==arr.size() || calculatedSum>sum)return false;
        if(dp[index][calculatedSum]!=-1) return dp[index][calculatedSum];
        calculatedSum+=arr[index];
        if(isSubsetSum(arr,sum,index+1,calculatedSum)) return true;
        calculatedSum-=arr[index];
        dp[index][calculatedSum]=isSubsetSum(arr,sum,index+1,calculatedSum);
        return dp[index][calculatedSum];
    }
};
int main(){
    Solution s;
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int& x : arr) cin>>x;
    cout<<s.isSubsetSum(arr,sum);
}