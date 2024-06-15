//https://codeforces.com/contest/1985/problem/D
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    string s="";
    for(int i=0;i<n;i++){
        cin>>s;
        v[i]=s;
    }
    int x1,y,x2;
    for(x1=0;x1<n;x1++){
        for(y=0;y<m;y++){
            if(v[x1][y]=='#')
                break;
        }
    }
    for(x2=n-1;x2>=0;x2--){
            if(v[x2][y]=='#')
                break;
    }
    cout<<(x1+x2-1)/2+1<<" "<<1+y<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}