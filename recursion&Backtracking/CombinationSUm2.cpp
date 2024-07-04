#include<bits/stdc++.h>
using namespace std;
class Solution {
    set<int> hashSet;
    vector<vector<int>> ans;
    int base=31;
    int mod=1e9+9;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        explorePossibilities(candidates,target,0,path);
        return ans;
    }
private:
    void explorePossibilities(vector<int>& candidates, int target,int index,vector<int>& path){
        if(target==0){ 
            if(hashTheValue(path))  ans.push_back(path);
            return;
        }
        if(target<0 || index==candidates.size()) return;
        target-=candidates[index];
        path.push_back(candidates[index]);
        explorePossibilities(candidates,target,index+1,path);
        path.pop_back();
        target+=candidates[index];
        explorePossibilities(candidates,target,index+1,path);
    }
    bool hashTheValue(vector<int>& v){
        int value=0;
        for(int& x : v){
            value=(value*base+x)%mod; 
        }
        if(hashSet.find(value)!=hashSet.end()) return false;
        hashSet.insert(value);
        return true;
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
    ans=s.combinationSum2(candidates,target);
    for(const vector<int>& v : ans){
        for(const int& x : v) cout<<x<<" ";
        cout<<endl;
    }
}