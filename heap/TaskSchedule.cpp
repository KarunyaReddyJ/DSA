#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> pi;
struct queueElement{
    int time;
    pi p;
};
class Solution {
    unordered_map<char,int> charCount;
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    queue<queueElement> q;
public:
    int leastInterval(vector<char>& tasks, int n){
        for(char c : tasks) charCount[c]++;
        for(auto x : charCount)
            pq.push({x.second,x.first});
        int time= 0;
        while(!pq.empty() || !q.empty()){
            if(!q.empty() && time-q.front().time>n) {
                pq.push(q.front().p);
                q.pop();
            }
            if(pq.empty()){
                cout<<time<<'i'<<endl;
                time++;
                continue;
            }
            pi current=pq.top();
            pq.pop();
            current.first-=1;
            if(current.first) q.push({time,current});
            time++;
        }
        return time;
    }
};
int main(){
    int n,k;
    cin>>k>>n;
    vector<char> chars(k);
    for(char & c : chars) cin>>c;
    Solution s;
    cout<<s.leastInterval(chars,n);
}