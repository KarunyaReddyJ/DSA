#include<bits/stdc++.h>
using namespace std;
class Solution {
    string state="";
    typedef pair<int,int> pi;
    pi explore(int depth,int lastChosen){
        int n=state.length();
        if(depth==n)
            return {1,(lastChosen==n)};
        if(state[depth]=='0'){
            state[depth]='1';
            return explore(depth+1,depth+1);
        }
        pi p={0,0};
        for(int i=0;i<n;i++){
            if(state[i]=='0'){
            state[i]='1';
            auto [ways,fc]=explore(depth+1,i+1);
            p={p.first+ways,fc+p.second};
            state[i]='0';
        }
        }
        return p;
    }
public:
    double nthPersonGetsNthSeat(int n) {
        for(int i=1;i<=n;i++) state.push_back('0');
        auto [ways,fc]=explore(0,-1);
        return (double)(fc/ways);
    }
};
int main(){

}