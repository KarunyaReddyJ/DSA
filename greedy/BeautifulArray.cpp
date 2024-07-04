#include<bits/stdc++.h>
using namespace std;

void printVec(auto& v){
    for(auto it=v.begin();it!=v.end();it++) 
        cout<<*it<<" ";
    cout<<endl;
}

void solve(){
    int n,k,x;
    cin>>n>>k;
    multiset<int> ms;
    for(int i=0;i<n;i++){
        cin>>x;
        ms.insert(x);
    }
   auto getIndex=[&](int x)->auto{
        int last=*(--ms.end());
        for(int i=0;x+i*k<=last;i++){
            auto it=ms.find(x+i*k);
            if(it==ms.end()) continue;
            return it;
        }
        return ms.end();
    };
    int ops=0;
    for(auto i=ms.begin();i!=ms.end() && ms.size()>1;i++){
        auto ki=getIndex(*i);
        if(ki==ms.end()){
            cout<<"index "<<*i<<endl;
            printVec(ms);
            cout<<-1<<endl;
            return;
        }
        ops+=(*ki-*i)/k;
        ms.erase(i);
        ms.erase(ki);
    }
    cout<<ops<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) 
        solve();
}