#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> paths;
    if (root == nullptr) return paths;
    
    stack<pair<TreeNode*, string>> st;
    st.push({root, to_string(root->val)});
    
    while (!st.empty()) {
        auto p = st.top();
        auto node=p.first;
        string path=p.second;
        st.pop();
        
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        }
        
        if (node->right != nullptr) {
            st.push({node->right, path + "->" + to_string(node->right->val)});
        }
        
        if (node->left != nullptr) {
            st.push({node->left, path + "->" + to_string(node->left->val)});
        }
    }
    
    return paths;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> paths = binaryTreePaths(root);
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
