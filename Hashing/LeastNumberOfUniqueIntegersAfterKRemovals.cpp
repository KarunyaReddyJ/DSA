#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()(pair<int,int> const& p1,pair<int,int> const& p2){
        return p1.first>p2.first;
    }
};
class Solution {
    unordered_map<int,int> frequency;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> p;
    vector<int> freqAray;
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        for(int& x : arr) frequency[x]++;
        freqAray=vector<int>(arr.size()+1,0);
        int total=frequency.size();
        for(auto x : frequency) freqAray[x.second]++;
        for(int i=1;i<=arr.size() && k>0;i++){
            int removable=k/i;
            total-=removable;
            k-=removable*i;
            if(k<=i) break;
        }
        //for(auto x : frequency) p.push({x.second,x.first});
        // while(k){
        //     int f=p.top().first;
        //     k-=min(k,f);
        //     if(k) p.pop();
        // }
        return total;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    Solution s;
    cout<<s.findLeastNumOfUniqueInts(v,k);
}