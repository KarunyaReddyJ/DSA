#include <bits/stdc++.h>
using namespace std;
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
struct pair_multiset_hash {
    size_t operator() (const pair<int, int>& p) const {
        // Combine hash values of pair<int, int>
        size_t hash_value = hash<int>{}(p.first);
        hash_value ^= hash<int>{}(p.second) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2); // Boost's hash_combine

        return hash_value;
    }
};

long long unq(multiset<int>& m,int val){
    int inSize=m.size();
    m.erase(val);
    return (long long)(m.size()*(inSize-m.size()));
}
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    cin>>v;
    unordered_map<pair<int,int>,multiset<int>,pair_multiset_hash> pre,in,post;
    for(int i=0;i<n-1;i++){
        if(i!=0)
            pre[make_pair(v[i],v[i+1])].insert(v[i-1]);
        if(i<n-2){
            post[make_pair(v[i],v[i+1])].insert(v[i+2]);
            in[make_pair(v[i],v[i+2])].insert(v[i+1]);
        }
    }
    long long pairs=0;
    for(int i=0;i<n-2;i++){
        multiset<int>& tpre=pre[make_pair(v[i+1],v[i+2])];
        multiset<int>& tin=in[make_pair(v[i],v[i+2])];
        multiset<int>& tpost=post[make_pair(v[i],v[i+1])];
        pairs+=unq(tpre,v[i]);
        pairs+=unq(tin,v[i+1]);
        pairs+=unq(tpost,v[i+2]);
    }
    cout<<pairs<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
