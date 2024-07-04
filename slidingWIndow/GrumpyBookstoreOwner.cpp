#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalCustomers=0,maxGrumpy=INT_MIN,grump=0;
        for(int i=0;i<minutes;i++){
            grump+=grumpy[i]*customers[i];
            maxGrumpy=max(maxGrumpy,grump);
            totalCustomers+=customers[i]*(1-grumpy[i]);
        }
        for(int i=minutes;i<customers.size();i++){
            grump-=grumpy[i-minutes]*customers[i-minutes];
            grump+=grumpy[i]*customers[i];
            maxGrumpy=max(maxGrumpy,grump);
            totalCustomers+=customers[i]*(1-grumpy[i]);
        }
        return totalCustomers+maxGrumpy;
    }
};
int main(){
    int n,minutes;
    cin>>n>>minutes;
    vector<int> customers(n),grumpy(n);
    for(int&x : customers) cin>>x;
    for(int&x : grumpy) cin>>x;
    Solution s;
    cout<<s.maxSatisfied(customers,grumpy,minutes);
}