#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> answer;
public:
    void swap(int& n1,int& n2){
        int t=n1;
        n1=n2;
        n2=t;
    }
    void permutations(vector<int>& nums,int ind){
        if(ind==nums.size()-1){
            answer.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            permutations(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums,0);
        return answer;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3,4,5,6,7,8,9,0};
    vector<vector<int>> answers=sol.permute(nums);
    for(vector<int>& v : answers){
        for(int& x : v)
            cout<<x<<" ";
        cout<<endl;
    }
}