#include<bits/stdc++.h>
using namespace std;
class DisjoinSetUnion{
    unordered_map<char,char> parent;
    public:
    DisjoinSetUnion(vector<char>& v){
        for(char& c : v) parent[c]=c;
    }
    char find(char c){
       if(parent[c]!=c) 
            parent[c]=find(parent[c]);
       return parent[c];
    }
    void unionSets(char u1,char u2){
        while(parent[u1]!=u1)
            u1=parent[u1];
        while(parent[u2]!=u2)
            u2=parent[u2];
        parent[u2]=u1;
    }
};
int main(){
    vector<char> elements={'a','b','c','d','e','f','g','h'};
    DisjoinSetUnion dsu= DisjoinSetUnion(elements);
    cout<<dsu.find('b')<<endl;
    dsu.unionSets('a','b');
    dsu.unionSets('c','d');
    dsu.unionSets('a','c');
    cout<<dsu.find('d');
}
