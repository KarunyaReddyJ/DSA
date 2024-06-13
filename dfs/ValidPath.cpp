#include <bits/stdc++.h>
using namespace std;

bool safe(int r, int c, int n, int m) {
    return r >= 0 && c >= 0 && r <= n && c <= m;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> adj(A+1, vector<int>(B+1, 1));
    vector<vector<bool>> visited(A+1, vector<bool>(B+1, false));
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    auto distance = [&](int cx, int cy, int i, int j) {
        return sqrt((cx - i) * (cx - i) + (cy - j) * (cy - j));
    };

    // Marking the cells based on the circles
    for (int i = 0; i < C; ++i) {
        for (int row = 0; row <= A; ++row) {
            for (int col = 0; col <= B; ++col) {
                if (distance(E[i], F[i], row, col) <= D) {
                    adj[row][col] = 0;
                }
            }
        }
    }

    // If the start or end point is blocked, return "NO" immediately
    if (adj[0][0] == 0 || adj[A][B] == 0) return "NO";
    
    // BFS to find the path from (0,0) to (A,B)
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int r=p.first,c=p.second;
        if (r == A && c == B) return "YES";
        
        for (auto p : directions) {
            int dr=p.first,dc=p.second;
            int nr = r + dr, nc = c + dc;
            if (safe(nr, nc, A, B) && adj[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return "NO";
}

int main() {
    int x = 2, y = 3, N = 2, R = 1;
    vector<int> A = {2, 0}, B = {2, 3};
    cout << solve(x, y, N, R, A, B) << endl; // Example call
    return 0;
}
