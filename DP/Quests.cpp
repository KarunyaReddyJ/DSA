#include<bits/stdc++.h>
using namespace std;
using i64=long long;
class Solution{
    public:
    void solve(){
        //DP


        // int n,k,x;cin>>n>>k;
        // int A[n],maxUpto[n],maxNum=-1;
        // for(int& x : A) cin>>x;
        // for(int i=0;i<n;i++){
        //     cin>>x;
        //     maxNum=max(maxNum,x);
        //     maxUpto[i]=maxNum;
        // }
        // vector<int> L1(n,0),L2(n);
        // vector<int>& x1=L1,&x2=L2;
        // for(int _=k-1;_>0;_--){
        //     for(int j=0;j<min(n,_);j++){
        //         int l1=x1[j]+maxUpto[j],l2=0;
        //         if(j<min(_,n-1)) 
        //             l2=x1[j+1]+A[j+1];
        //         x2[j]=max(l1,l2);
        //     }
        //     swap(x1,x2);
        // }
        // cout<<x1[0]+A[0]<<endl;


        //Greedy

        int n,k;
        cin>>n>>k;
        vector<i64> A(n),B(n);
        i64 maxEl=-1,ums=0;
        for(i64& x : A){ 
            cin>>x;
            ums+=x;
            x=ums;
        }
        for(i64& x : B){
            cin>>x;
            maxEl=max(maxEl,x);
            x=maxEl;
        }
        i64 ans=0;
        for(int i=0;i<min(k,n);i++){
            ans=max(ans,A[i]+B[i]*(k-1-i));
        }
        cout<<ans<<endl;
    }
};
int main(){
    int t;cin>>t;
    while(t--){
        Solution s;
        s.solve();
    }
}