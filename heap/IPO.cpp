#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<profits.size();i++)
            pq.push({capital[i],profits[i]});
        for(int i=1;i<=k;i++){
            priority_queue<pi> takens;
            while(!pq.empty() && pq.top().first<=w){
                takens.push({pq.top().second,pq.top().first});
                pq.pop();
            }
            pi p=takens.top();
            w+=p.first;
            while(!pq.empty()){
                pq.push({takens.top().second,takens.top().first});
                takens.pop();
            }
        }
        return w;
    }
};
int main(){

}