#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    // Array to store the ways to reach up to the last 6 levels
    vector<int> dp(6, 0);
    dp[0] = 1; // Base case: One way to stay at level 0

    // Iterate over each level from 1 to n
    for (int level = 1; level <= n; ++level) {
        int current_ways = 0;
        // Sum the ways to reach the last 6 levels
        for (int i = 0; i < 6; ++i) {
            current_ways = (current_ways + dp[i]) % MOD;
        }
        // Shift the array to the left and add the new number of ways at the end
        for (int i = 0; i < 5; ++i) {
            dp[i] = dp[i + 1];
        }
        dp[5] = current_ways;
    }

    cout << dp[5] << endl;
    return 0;
}
