#include<bits/stdc++.h>
using namespace std;
class Solution {
    int sum=0;
public:
    bool canPartition(vector<int>& nums) {
        sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        return recursion(nums,0,0);
    }
private:
    bool recursion(vector<int>& nums,int index,int sumSoFar){
        if(sumSoFar*2==sum) return true;
        if(index==nums.size() || sumSoFar*2>sum) return false;
        sumSoFar+=nums[index];
        if(recursion(nums,index+1,sumSoFar)) return true;
        sumSoFar-=nums[index];
        return recursion(nums,index+1,sumSoFar);
    }
};
int main(){
    vector<int> nums={100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      100,100,100,100,100,100,100,100,100,
                      
                      
                      100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97};
    Solution s;
    cout<<s.canPartition(nums);
}