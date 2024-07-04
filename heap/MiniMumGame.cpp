#include<bits/stdc++.h>
using namespace std;
// struct compare{
//     bool operator()(int const& p1,int const& p2){
//         return p1.edge>p;
//     }
// };
class Solution {
    priority_queue<int,vector<int>,greater<int>()> pq;
public:
    vector<int> numberGame(vector<int>& nums) {
        for(int& x : nums) pq.push(x);
        vector<int> ans;
        while(!pq.empty()){
            int k1=pq.top();
            pq.pop();
            int k2=pq.top();
            pq.pop();
            ans.push_back(k2);
            ans.push_back(k1);
        }
        return ans;
    }
};
int main(){

}