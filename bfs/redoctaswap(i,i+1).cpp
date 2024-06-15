//https://atcoder.jp/contests/abc264/tasks/abc264_d
#include<bits/stdc++.h>
using namespace std;
void swap(char& c1,char& c2){
    char t=c1;
    c1=c2;
    c2=t;
}
int bfs(string s){
    queue<pair<string,int>> q;
    string target="atcoder";
    set<string> set;
    set.insert(s);
    q.push({s,0});
    while(!q.empty()){
        auto current=q.front();
        q.pop();
        if(current.first==target)
            return current.second;
        string next=current.first;
        for(int i=0;i<6;i++){
            swap(next[i],next[i+1]);
            if(set.find(next)==set.end()){
                q.push({next,current.second+1});
                set.insert(next);
            }
            swap(next[i],next[i+1]);
        }
    }
    return -1;
}
int main(){
    string s;
    cin>>s;
    cout<<bfs(s);
}