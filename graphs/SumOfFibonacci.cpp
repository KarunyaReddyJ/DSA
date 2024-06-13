#include<bits/stdc++.h>
using namespace std;
int fibsum(int A) {
    int num=0;
    function<void(int,int,int&)> dfs=[&](int a,int b,int& rem){
        if(rem==0)  return;
        else if((long long)(a+b)>rem){
            if(rem>=b){
                rem-=b;
                num++;
            }
            dfs(b-a,a,rem);
            return;
        }
        dfs(b,a+b,rem);
    };
    dfs(0,1,A);
    return num;
}
int main(){
    int n;
    cin>>n;
    cout<<fibsum(n);
}