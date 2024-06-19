#include <bits/stdc++.h>
using namespace std;
class Solution{
    
public:
    int minDays(vector<int> &bloomDay, int m, int k){
        if (bloomDay.size() < m * k)
            return -1;
        int last = *max_element(bloomDay.begin(), bloomDay.end());
        int start = 0, ans = -1;
        while (start <= last){
            int mid = (last - start) / 2 + start;
            if (!canMakeBouquet(bloomDay,m,k,mid))
                start = mid + 1;
            else{
                last = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
    private:
    bool canMakeBouquet(vector<int> &bloomDay,int m,int k,int day){
        int bouquet=0,flowers=0;
        for(int& boq : bloomDay){
            if(boq<=day){
                flowers++;
                if(flowers==k){
                    bouquet++;
                    flowers=0;
                }
            }
            else flowers=0;
            if(bouquet>=m) return true;
        }
        return false;
    }
};
int main(){
    vector<int> bloomDay = {7, 7, 7, 7,7, 7,12};
    Solution s;
    cout<<s.minDays(bloomDay,2,3);
}