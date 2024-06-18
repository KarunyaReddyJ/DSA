/*
https://leetcode.com/problems/counting-bits/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int noOfBits(int n){ //logn time
        int count=0;
        while(n){
            n&=(n-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        ans[0]=0;
        for(int i=1;i<=n;i++){
                ans[i]=ans[i/2];
            if(i&1) ans[i]+=1;
        }
        return ans;
    }
};
int main(){
    vector<int> ans;
    Solution s;
    int n;
    cin>>n;
    auto start = std::chrono::high_resolution_clock::now();
    ans=s.countBits(n);
      auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Output the duration in seconds
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;
    cout<<"done\n";
    for(int x : ans) cout<<x<<" ";
}