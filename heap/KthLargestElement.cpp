#include<bits/stdc++.h>
using namespace std;
class Solution {
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int& x : nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
int main(){

}