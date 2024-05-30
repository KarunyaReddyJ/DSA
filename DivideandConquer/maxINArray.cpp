#include<bits/stdc++.h>
using namespace std;
int maxInArray(vector<int>& v,int l,int h){
    if(l>h)
        return INT_MIN;
    if(l==h)
        return v[l];
    int mid=((h-l)>>1)+l;
    int leftMax=maxInArray(v,l,mid);
    int rightMax=maxInArray(v,mid+1,h);
    return max(leftMax,rightMax);
}
int main(){
    vector<int> v={10,4,6,28,20,17,21,9};
    cout<<maxInArray(v,0,7);
}