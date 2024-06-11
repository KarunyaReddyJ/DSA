#include <bits/stdc++.h>
#include "TreeStruct.cpp"
using namespace std;

vector<vector<int>> levelOrder(TreeNode* A) {
    if (!A) return {}; // If the tree is empty, return an empty vector.
    
    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});
    vector<vector<int>> ans;

    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        
        // If we are at a new level that does not exist in ans yet
        if (ans.size() <= now.second)
            ans.push_back({}); // Create a new level
        
        // Add the current node's value to its corresponding level
        ans[now.second].push_back(now.first->val);
        
        // Push the left child to the queue, if it exists
        if (now.first->left != NULL)
            q.push({now.first->left, now.second + 1});
        
        // Push the right child to the queue, if it exists
        if (now.first->right != NULL)
            q.push({now.first->right, now.second + 1});
    }

    return ans;
}
