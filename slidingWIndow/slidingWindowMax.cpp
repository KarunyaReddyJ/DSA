#include<bits/stdc++.h>
using namespace std;
class Solution {
    priority_queue<int> maxHeap;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxs;
        for(int i=0;i<k;i++)
            maxHeap.push(nums[i]);
        maxs.push_back(maxHeap.top());
        for(int i=k;i<nums.size();i++){
            maxHeap.pop();
            maxHeap.push(nums[i]);
            maxs.push_back(maxHeap.top());
        }
        return maxs;
    }
};
int main(){

}