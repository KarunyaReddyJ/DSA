#include <bits/stdc++.h>
using namespace std;

struct node {
    string word;
    int transformations;
};

class Solution {
    bool present = false;
    unordered_map<string, vector<string>> adjList;
    queue<node> q;
    set<string> visited;
public:
    int letterDifferences(string s1, string& s2) {
        int mismatch = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                mismatch++;
                if (mismatch > 1) return -1;
            }
        }
        return mismatch;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Check if endWord is in wordList
        for (string& s : wordList) {
            if (s == endWord) present = true;
        }
        if (!present) return 0;

        // Initialize adjacency list and visited set
        wordList.push_back(beginWord);
        for (string& s1 : wordList) {
            for (string& s2 : wordList) {
                if (letterDifferences(s1, s2) == 1) {
                    adjList[s1].push_back(s2);
                }
            }
        }

        // BFS initialization
        q.push({beginWord, 1});
        visited.insert(beginWord);

        // BFS
        while (!q.empty()) {
            node current = q.front();
            string word = current.word;
            int transformations = current.transformations;
            q.pop();

            if (word == endWord) return transformations;

            for (string& s : adjList[word]) {
                if (visited.find(s) == visited.end()) {
                    visited.insert(s);
                    q.push({s, transformations + 1});
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    string beginword = "kite", endWord = "ashy";
    vector<string> wordList = {"ante", "does", "jive", "achy", "kids", "kits", "cart", "ache", "ands", "ashe", "acne", "aunt", "aids", "kite", "ants", "anne", "ashy"};
    cout << sol.ladderLength(beginword, endWord, wordList) << endl;
}
