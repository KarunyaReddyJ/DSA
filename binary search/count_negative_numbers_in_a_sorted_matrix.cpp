#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& v3){
    for(int x : v3)
        cout<<x<<" ";
    cout<<endl;
}
bool isTHere(vector<int>& v,int x){
        int low=0,high=v.size()-1;
        while(low<=high){
            int mid=((high-low)>>1)+low;
            if(v[mid]==x)
                return true;
            else if(v[mid]<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();){
            int x=nums1[i];
            if(isTHere(nums2,nums1[i])){
                res.push_back(nums1[i]);
                while(i<nums1.size() && nums1[i]==x)    
                    i++;
            }
        }
        return res;
    }
int main(){
    vector<int> v1={1,2,2,1},v2={2,2};
    vector<int> v3=intersection(v1,v2);
    print(v3);
}