//https://codeforces.com/contest/1985/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int& x : v)
        cin>>x;
    long long int sum=0,max_element=v[0];
    int count=0;
    for(int& x : v){
        sum+=x;
        max_element=max(max_element,(long long)x);
        if(2*max_element==sum) count++;
    }
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}