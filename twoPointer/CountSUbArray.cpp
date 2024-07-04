#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0, oddCount = 0;
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // To handle the case when exactly k odd numbers are found

        for (int num : nums) {
            if (num % 2 == 1) oddCount++;
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                count += prefixCount[oddCount - k];
            }
            prefixCount[oddCount]++;
        }
        return count;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    Solution s;
    cout<<s.numberOfSubarrays(v,k);
}