#include<bits/stdc++.h>
using namespace std;    
int countPairs(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int count=0;
    for(int i=0;i<nums.size();){
        if(target<=2*nums[i])
            break;
        int ind=lower_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin()-1;
        int cnt=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin()-i;
        int options=ind-i;
        count+=(cnt*(2*options-cnt+1))>>1;
        i+=cnt;
    }
    return count;
}
int main(){
    vector<int> v={-6,2,5,-2,-7,-1,3};
    int target=-2;
    cout<<countPairs(v,target);
}

