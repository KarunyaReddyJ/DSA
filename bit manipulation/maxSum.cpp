#include<bits/stdc++.h>
using namespace std;
#define ll long long
int oneSComplement(int number,int bits){
    int k=1;
    for(int i=1;i<=bits;i++,k*=10){
        if((number/k)%2==0)
            number+=k;
        else
            number-=k;
    }
    return number;
}
ll maxSum(int numberOfBits,int maxOperations,vector<int> arr){
    vector<int> diff;
    ll sum=0;
    for(int x : arr){
        sum+=x;
        diff.push_back(oneSComplement(x,numberOfBits)-x);
    }
    sort(diff.begin(),diff.end(),greater<int>());
    for(int i=0;i<maxOperations && diff[i]>0;i++)
        sum+=diff[i];
    return sum;
}
int main(){
    cout<<maxSum(2,1,{11,01});
}