#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dp;
    bool choseOne;
public:
Solution(size_t n=1e2):dp(n,-1){
    choseOne=false;
};
    int rob(vector<int>& nums,size_t i=0) {
        // if(i==nums.size()-1 && !choseOne ) return nums.back();
        // if(i>=nums.size()-1 ) return 0;
        // if(dp[i]!=-1) return dp[i];
        // int select=nums[i],deselect=0;
        // bool temp=choseOne;
        // if(i==0){
        //     choseOne=true;
        //     select+=rob(nums,i+2);
        //     choseOne=temp;
        // }
        // else
        //     select+=rob(nums,i+2);
        // deselect=rob(nums,i+1);
        // dp[i]= max(select,deselect);
        // return dp[i];
        if(nums.size()==1) return nums[0];
        return max(robber(nums,0,nums.size()-1),robber(nums,1,nums.size()));
    }
    vector<int> print(){
        return dp;
    }
    private:
    int robber(vector<int>& nums,int i,int end) {
        if(1==end) return nums[end];
        int l1=nums[end],l2=0;
        for(int i=nums.size()-2;i>=0;i--){
            int maxBenefit=max(nums[i]+l2,l1);
            l2=l1;
            l1=maxBenefit;
        }
        return l1;
    }
};
    
int main(){
    Solution s;
    vector<int> nums={200,3,140,20,10};
    cout<<s.rob(nums)<<endl;
    vector<int> dp=s.print();
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" "<<dp[i]<<endl;
    }
}