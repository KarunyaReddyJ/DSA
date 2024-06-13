#include<bits/stdc++.h>
using namespace std;
string topologicalSort(vector<vector<char>>& prereq,unordered_set<char>& count){
    set<char> visited;
    unordered_map<char,string> adj;
    string order="";
    for(vector<char>& v : prereq)
        adj[v[0]].push_back(v[1]);
    // for(auto x : adj){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    function <void(char)> dfs=[&](char node){
        visited.insert(node);
        for(char neigbour : adj[node]){
            if(visited.find(neigbour)==visited.end())
                dfs(neigbour);
        }
        order.push_back(node);
    };
    ///whats problems below 
    for(auto x : count){
       // cout<<x<<endl;
        if(visited.find(x)==visited.end()){
            dfs(x);
        }
    }
    reverse(order.begin(),order.end());
    return order;
}
string alienOrder(vector<string> &words) {
    vector<vector<char>> prereq;
    unordered_set<char> count;
    function <int(string&,string&)> extract=[&](string& first,string& second){
        int i=0;
        while(i<min(first.length(),second.length()) && first[i]==second[i])
            i++;
        if(i==min(first.length(),second.length()))
            return -1;
        return i;
    };
    for(int i=0;i<words.size()-1;i++){
        int ind=extract(words[i],words[i+1]);
        if(ind!=-1){
            prereq.push_back({words[i][ind],words[i+1][ind]});
            count.insert(words[i][ind]);
            count.insert(words[i+1][ind]);
        }
    }
    return topologicalSort(prereq,count); //ab toh chalega
}
int main(){
    vector<string> words={
        
    };
    cout<<alienOrder(words);
    cout<<words.size();
}