#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    unordered_map<int, int> a,b;
    for(int x : arr)
        a[x]++;
    for(int x : brr)
        b[x]++;
    vector<int> ans;
    for(auto x : b){
        auto it=a.find(x.first);
        if(it==a.end()){
            for(int i=0;i<x.second;i++)
                ans.push_back(x.first);
        }
        else if(it->second!=x.second){
            for(int i=it->second;i<x.second;i++)
                ans.push_back(x.first);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++) {
        cin>>brr[i];
    }
    vector<int> result = missingNumbers(arr, brr);
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}