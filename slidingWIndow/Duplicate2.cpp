#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,int> hashMap;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<=k;i++){
            if(hashMap.find(nums[i])!=hashMap.end()) return true;
            hashMap[nums[i]]=i;
        }
        for(int i=k+1;i<nums.size();i++){
            hashMap.erase(nums[i-k-1]);
            if(hashMap.find(nums[i])!=hashMap.end()) return true;
            hashMap[nums[i]]=i;
        }
        return false;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    Solution s;
    for(int& x : nums) cin>>x;
    cout<<s.containsNearbyDuplicate(nums,k);
}