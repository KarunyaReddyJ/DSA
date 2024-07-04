#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,int> frequency;
    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(int& x : nums) frequency[x]++;
        for(auto x : frequency) pq.push({x.second,x.first});
        vector<int> ans;
        for(int i=0;i<k && !pq.empty();i++){
            int t=pq.top().second;
            pq.pop();
            ans.push_back(t);
        }
        return ans;
    }
};
int main(){

}