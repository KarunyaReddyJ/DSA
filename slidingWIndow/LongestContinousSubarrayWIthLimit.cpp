#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int longestWindow=1,window=1;
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        maxHeap.push({nums[0],0});
        minHeap.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            if(max(maxHeap.top().first,nums[i])-min(minHeap.top().first,nums[i])<=limit){
                maxHeap.push({nums[i],i});
                minHeap.push({nums[i],i});
                longestWindow=max(longestWindow,++window);
                continue;
            }
            int ind;
            if(nums[i]>maxHeap.top().first)
                ind=minHeap.top().second;
            else if(nums[i]<minHeap.top().first)
                ind=maxHeap.top().second;
            while(!maxHeap.empty()) maxHeap.pop();
            while(!minHeap.empty()) minHeap.pop();
            for(int j=ind+1;j<=i;j++){ 
                maxHeap.push({nums[j],j});
                minHeap.push({nums[j],j});
            }
            window=i-ind;
            longestWindow=max(longestWindow,window);
        }
        return longestWindow;
    }
};
int main(){
    int n,limit;
    cin>>n>>limit;
    Solution s;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    cout<<s.longestSubarray(v,limit);
}