#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int& el : arr){
            pq.push({abs(el-x),x});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            int el=pq.top().second;
            ans.push_back(el);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){

}