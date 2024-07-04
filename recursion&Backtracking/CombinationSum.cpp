#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        explorePossibilities(candidates,target,0,path);
        return ans;
    }
private:
    void explorePossibilities(vector<int>& candidates, int target,int index,vector<int>& path){
        if(target==0){ 
            ans.push_back(path);
            return;
        }
        if(target<0 || index==candidates.size()) return;
        target-=candidates[index];
        path.push_back(candidates[index]);
        explorePossibilities(candidates,target,index,path);
        path.pop_back();
        target+=candidates[index];
        explorePossibilities(candidates,target,index+1,path);
    }
};
int main(){
    int n;
    int target=7;
    cin>>n>>target;
    vector<int> candidates(n); 
    for(int& x : candidates) cin>>x;
    Solution s;
    vector<vector<int>> ans;
    ans=s.combinationSum(candidates,target);
    for(const vector<int>& v : ans){
        for(const int& x : v) cout<<x<<" ";
        cout<<endl;
    }
}