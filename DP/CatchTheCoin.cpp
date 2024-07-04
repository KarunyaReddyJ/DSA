#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

class Solution {
    vector<pi> coins;
    vector<pi> directions = {{1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {1, -1}};
    set<pi> coin;
    set<pi> visited;

    void fall() {
        for (pi& p : coins) p.second -= 1;
    }

    void unFall() {
        for (pi& p : coins) p.second += 1;
    }

    void explore(pi coordinate) {
        if (coordinate.first > 50 || coordinate.first < -50 || coordinate.second > 50 || coordinate.second < -50)
            return;
        if (coin.find(coordinate) != coin.end()) visited.insert(coordinate);
        for (pi& dir : directions) {
            fall();
            pi next_coordinate = {coordinate.first + dir.first, coordinate.second + dir.second};
            explore(next_coordinate);
            unFall();
        }
    }

public:
    void solve() {
        int n;
        cin >> n;
        coins = vector<pi>(n);
        for (pi& p : coins) {
            cin >> p.first >> p.second;
            coin.insert(p);
        }
        pi coordinate = {0, 0};
        explore(coordinate);
        for (pi p : coin)
            cout << (visited.find(p) != visited.end() ? "YES\n" : "NO\n");
    }
};

int main() {
    Solution s;
    s.solve();
    return 0;
}
