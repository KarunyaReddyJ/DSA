#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> days(n,vector<int>(3));
    for(auto& v : days) for(auto& x : v) cin>>x;
    vector<int> v1(3,0),v2(3);
    vector<int>& x1=v1,&x2=v2;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++){
            int l1=INT_MIN;
            for(int k=0;k<3;k++){
                if(k!=j) l1=max(l1,days[i][k]+x1[k]);
            }
            x2[j]=l1;
        }
        swap(x1,x2);
    }
    cout<<*max_element(x1.begin(),x1.end());
}