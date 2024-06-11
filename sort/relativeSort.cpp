#include<bits/stdc++.h>
using namespace std;
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> count(1001,0);
    for(int x : arr1)
        count[x]++;
    //for(int i=0;i<)
    int j=0;
    for(int x : arr2){
        while(count[x]-->0)
            arr1[j++]=x;
    }
    for(int i=0;i<1001;i++){
        while(count[i]-->0)
            arr1[j++]=i;
    }
    return arr1;
}
int main(){
    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19},arr2={2,1,4,3,9,6};
    arr1=relativeSortArray(arr1,arr2);
    for(int x : arr1)
        cout<<x<<" ";
}