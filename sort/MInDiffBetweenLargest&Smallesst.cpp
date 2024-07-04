#include<bits/stdc++.h>
using namespace std;
    int minDifference(vector<int>& nums) {
          if (nums.size() <= 4) return 0;
        multiset<int> st(nums.begin(),nums.end());
         for(const int & x : st) cout<<x<<" ";
         cout<<endl;
        function<int(int)> explore=[&](int turn){
            if(turn==3) return *st.rbegin()-*st.begin();
            int s1=*st.begin(),s2=*(++st.begin()),l1=*st.rbegin(),l2=*(++st.rbegin());
            if(l1==s1) return 0;
            if(l2-s1>l1-s2){
                st.erase(s1);
                st.insert(l2);
                return explore(turn+1);
            }
            else if(l2-s1<l1-s2){
                st.erase(l1);
                st.insert(s2);
                return explore(turn+1);
            }
            else{
                st.erase(s1);
                st.insert(l2);
                int k1= explore(turn+1);
                st.erase(l2);
                st.insert(s1);

                st.erase(l1);
                st.insert(s2);
                int k2=explore(turn+1);
                return min(k1,k2);
            }
        };
        int n= explore(0);
        for(const int & x : st) cout<<x<<" ";
        return n;
    }

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int& x : v) cin>>x;
    cout<<"\n"<<minDifference(v);
}