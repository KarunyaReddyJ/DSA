#include<bits/stdc++.h>
using namespace std;
class Solution {
    int earlyRound=INT_MAX,lateRound=INT_MIN;
    int firstPlayer,secondPlayer;
    void print(vector<int>& v){
        for(int& x : v) cout<<x<<" ";
        cout<<endl;
    }
public:
    void backtrack(vector<int>& current,int i,int round,set<int>& qualified){
        if(current.size()-1-i<=i){
            if(current.size()-1-i==i) qualified.insert(current[i]);
            if(qualified.size()<=1) return;
            vector<int> nextRound(qualified.begin(),qualified.end());
            set<int> temp(qualified.begin(),qualified.end());
            qualified.clear();
            // cout<<"round "<<round<<" to "<<round+1<<endl;
            // print(current);
            // print(nextRound);
            backtrack(nextRound,0,round+1,qualified);
            qualified.insert(temp.begin(),temp.end());
            return;
        }
        if((current[i]==firstPlayer || current[i]==secondPlayer)&&(current[current.size()-1-i]==firstPlayer || current[current.size()-1-i]==secondPlayer)){
            earlyRound=min(earlyRound,round);
            lateRound=max(lateRound,round);
            return;
        }
        if(current[i]==firstPlayer || current[i]==secondPlayer){
            qualified.insert(current[i]);
            backtrack(current,i+1,round,qualified);
            qualified.erase(current[i]);
            return;
        }
        if(current[current.size()-1-i]==firstPlayer || current[current.size()-1-i]==secondPlayer){
            qualified.insert(current[current.size()-1-i]);
            backtrack(current,i+1,round,qualified);
             qualified.erase(current[current.size()-1-i]);
            return;
        }
        qualified.insert(current[i]);
        backtrack(current,i+1,round,qualified);
        qualified.erase(current[i]);
        qualified.insert(current[current.size()-1-i]);
        backtrack(current,i+1,round,qualified);
        qualified.erase(current[current.size()-1-i]);
    }
    vector<int> earliestAndLatest(int n, int firstPlayr, int secondPlayr) {
        vector<int> dq;
        firstPlayer=firstPlayr;
        secondPlayer=secondPlayr;
        set<int> s;
        for(int i=1;i<=n;i++) dq.push_back(i);
        backtrack(dq,0,1,s);
        cout<<"answer\n";
        return {earlyRound,lateRound};
    }
};
int main(){
    Solution s;
    int n,fP,sP;
    cin>>n>>fP>>sP;
    vector<int> ans=s.earliestAndLatest(n,fP,sP);
    cout<<ans[0]<<" "<<ans[1];
}
