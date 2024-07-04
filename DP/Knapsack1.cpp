#include <bits/stdc++.h>
using namespace std;
using i64=long long;
void print(vector<vector<i64>>& v) {
    for (vector<i64>& vec : v) {
        for (i64& x : vec) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<vector<i64>> data(n, vector<i64>(2));
    for (auto& v : data) {
        for (i64& x : v) {
            cin >> x;
        }
    }

    vector<vector<i64>> dp(n + 1, vector<i64>(w + 1, (i64)0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i + 1][j]; 
            if (j >= data[i][0]) {   
                dp[i][j] = max(dp[i][j], data[i][1] + dp[i + 1][j - data[i][0]]);
            }
        }
    }

    //print(dp);
    cout << dp[0][w] << endl;

    return 0;
}
