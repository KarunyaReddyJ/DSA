#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false;
        
        int openUnlocked = 0, closeUnlocked = 0, openLocked = 0, closeLocked = 0;
        
        // Left to right check
        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0') {
                openUnlocked++;
            } else if (s[i] == '(') {
                openLocked++;
            } else {
                closeLocked++;
            }

            // Check if too many close parenthesis are locked
            if (closeLocked > openLocked + openUnlocked) {
                return false;
            }
        }

        openUnlocked = closeUnlocked = openLocked = closeLocked = 0;

        // Right to left check
        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                closeUnlocked++;
            } else if (s[i] == ')') {
                closeLocked++;
            } else {
                openLocked++;
            }

            // Check if too many open parenthesis are locked
            if (openLocked > closeLocked + closeUnlocked) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;
    string s, locked;
    cin >> s >> locked;
    cout << (sol.canBeValid(s, locked) ? "true" : "false") << endl;
    return 0;
}
