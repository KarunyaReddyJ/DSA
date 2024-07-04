#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> cache;
public:
    int change(int amount, vector<int>& coins) {
        cache=vector<vector<int>>(amount+1,vector<int>(coins.size(),-1));
        return recursion(amount,coins,-1);
    }
private: 
int recursion(int amount, vector<int>& coins,int lastChosen){
    if(amount==0) return 1;
        int ways=0;
        if(lastChosen!=-1 && cache[amount][lastChosen]!=-1) return cache[amount][lastChosen];
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0 && (lastChosen==-1 || coins[i]<=coins[lastChosen])) 
                ways+=recursion(amount-coins[i],coins,i);
        }
        cache[amount][lastChosen]=ways;
        return ways;
}
};
int main(){
    Solution s;
    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int& x : coins) cin>>x;
    cout<<s.change(amount,coins);
}