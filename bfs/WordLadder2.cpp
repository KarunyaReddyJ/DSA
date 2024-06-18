#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, int> levels;
    vector<vector<string>> paths;

public:
    // Function to check if two words differ by exactly one character
    bool mismatch(const string& s1, const string& s2) {
        int mis = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                mis++;
                if (mis > 1) return false;
            }
        }
        return mis == 1;
    }

    // Function to find all shortest paths from beginWord to endWord
    vector<vector<string>> wordLadder2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            cerr << "Error: endWord is not in the wordList" << endl;
            return {};
        }

        wordSet.insert(beginWord);

        // Create adjacency list
        for (const string& word : wordSet) {
            for (const string& other : wordSet) {
                if (mismatch(word, other)) {
                    adjList[word].push_back(other);
                }
            }
        }

        // Perform BFS to find the shortest path levels
        queue<string> q;
        q.push(beginWord);
        levels[beginWord] = 0;

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            int currentLevel = levels[current];

            for (const string& neighbor : adjList[current]) {
                if (levels.find(neighbor) == levels.end()) { // Not visited
                    levels[neighbor] = currentLevel + 1;
                    q.push(neighbor);
                }
            }
        }

        // If endWord is not reachable, return an empty path
        if (levels.find(endWord) == levels.end()) {
            cerr << "Error: No path found from beginWord to endWord" << endl;
            return {};
        }

        // Backtrack to find all paths from endWord to beginWord
        vector<string> currentPath = {endWord};
        backtrack(endWord, beginWord, currentPath);

        return paths;
    }

    void backtrack(const string& word, const string& beginWord, vector<string>& currentPath) {
        if (word == beginWord) {
            paths.push_back(vector<string>(currentPath.rbegin(), currentPath.rend()));
            return;
        }

        for (const string& neighbor : adjList[word]) {
            if (levels.find(neighbor) != levels.end() && levels[neighbor] == levels[word] - 1) {
                currentPath.push_back(neighbor);
                backtrack(neighbor, beginWord, currentPath);
                currentPath.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = solution.wordLadder2(beginWord, endWord, wordList);

    if (result.empty()) {
        cout << "No valid paths found" << endl;
    } else {
        for (const auto& path : result) {
            for (const string& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
