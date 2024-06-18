#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> dp;
public:
Solution(int n): dp(n,-1){};
    int rob(vector<int>& nums) {
        if(1==nums.size()) return nums.back();
        int l1=nums.back(),l2=0;
        for(int i=nums.size()-2;i>=0;i--){
            int maxBenefit=max(nums[i]+l2,l1);
            l2=l1;
            l1=maxBenefit;
        }
        return l1;
    }
};
int main(){
    vector<int> nums={2,1,1,2};
    Solution s(nums.size());
    cout<<s.rob(nums);
}