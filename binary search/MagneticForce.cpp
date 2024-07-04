#include<bits/stdc++.h>
using namespace std;
class Solution {
    int smallest,largest,width;
    vector<int> cache;
public:
    Solution(): cache(1e5,-1){};
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        smallest=position.front(),largest=position.back();
        width=(largest-smallest)/(m-1);
        return recursion(position,0);
        return width;
    }
private:
    int recursion(vector<int>& position,int index){
        if(index>=position.size()-1) return INT_MAX;
        int nextIndex=lower_bound(position.begin(),position.end(),position[index]+width)-position.begin();
        if(position[nextIndex]==position[index]+width)
            return width;
        if(cache[index]!=-1) return cache[index];
        int lW=min(position[nextIndex-1]-position[index],recursion(position,index+1));
        int rW=min(position[nextIndex+1]-position[index],recursion(position,index+1));
        cache[index]=max(lW,rW);
        return cache[index];
    }
};
int main(){
    Solution s;
    int n,m;
    cin>>n>>m;

    vector<int> positions(n);
    for(int& x : positions) cin>>x;
    cout<<s.maxDistance(positions,m);
}