#include <bits/stdc++.h>
using namespace std;

// Improved hash function to include expr, ops, and i
std::size_t fnv1aHash(const std::string& str, int ops, int i) {
    std::size_t hash = 2166136261u; // FNV offset basis
    const std::size_t prime = 16777619u; // FNV prime

    for (char c : str) {
        hash ^= static_cast<std::size_t>(c);
        hash *= prime;
        hash|=(ops<<i);
    }
    // Incorporate ops and i into the hash
    hash ^= ops;
    hash *= prime;
    hash ^= i;
    hash *= prime;
    
    return hash;
}

class Solution {
    unordered_map<size_t, unsigned long long> cache;
public:
    void solve() {
        int n; cin >> n;
        string s, expr = ""; cin >> s;
        if(n<=2){
            int n=(s[0]-'0')*10+(s[1]-'0');
            cout<<n<<endl;
            return;
        }

        int a[20],b[20],c,ans=1e9;
        for(int i=0;i<s.length();i++) a[i]=s[i]-'0';
        for(int i=0;i<n-1;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(i==j) b[c++]=a[j]*10+a[j+1];
                else if(i!=j-1) b[c++]=a[j];
            }
            int current=0;
            for(int j=0;j<n-1;j++) {
                if(b[j]==0){
                    cout<<0<<endl;
                    return;
                }
                if(b[j]!=1) current+=b[j];
            }
            if(current==0) current=1;
            ans=min(current,ans);
        }
        cout<<ans<<endl;
    }    
};

int main() {
    int t;
    cin >> t;
     cin.tie(nullptr)->sync_with_stdio(false);
    while (t--) {
        Solution s;
        s.solve();
    }
    return 0;
}
