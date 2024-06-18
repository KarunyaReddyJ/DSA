#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> dp;
public:
    Solution(int n) : dp(n, -1) {}

    int minimizeCost(vector<int>& height, int n, int k) {
        if (n == 1) return 0;
        dp[n - 1] = 0;

        deque<pair<int, int>> dq; // Deque to store (cost, index) pairs
        dq.push_back({0, n - 1});

        for (int i = n - 2; i >= 0; i--) {
            // Remove elements from the deque that are out of the current window
            while (!dq.empty() && dq.front().second > i + k) {
                dq.pop_front();
            }

            int res = INT_MAX;
            if (!dq.empty()) {
                res = abs(height[i] - height[dq.front().second]) + dq.front().first;
            }

            dp[i] = res;

            // Maintain deque for future minimum values
            while (!dq.empty() && dq.back().first >= dp[i]) {
                dq.pop_back();
            }
            dq.push_back({dp[i], i});
        }
        return dp[0];
    }
};

int main() {
    vector<int> height = {1, 3, 5, 8, 4, 7, 10};
    int n = height.size();
    Solution s(n);
    int k = 3;
    int result = s.minimizeCost(height, n, k);
    cout << result << endl;
    return 0;
}
