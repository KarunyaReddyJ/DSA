#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a[3];
        for(int& x : a) cin>>x;
        int minD=1e9;
        for(int i=1;i<=10;i++){
            int sum=0;
            for(int x : a) sum+=abs(x-i);
            minD=min(sum,minD);
        }
        cout<<minD<<endl;
    }
}