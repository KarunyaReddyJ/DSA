#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> inorder;
    
    void Inorder(TreeNode* root) {
        if (root == nullptr) return;
        Inorder(root->right);
        if (inorder.empty())
            inorder.push_back(root->val);
        else
            inorder.push_back(root->val + inorder.back());
        Inorder(root->left);
    }
    
    void InorderFill(TreeNode* root, int &ind) {
        if (root == nullptr) return;
        InorderFill(root->right, ind);
        root->val = inorder[ind++];
        InorderFill(root->left, ind);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        Inorder(root);
        int ind = 0;
        InorderFill(root, ind);
        return root;
    }
};

void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

TreeNode* insert(TreeNode* node, int key) {
    if (node == nullptr) return new TreeNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);

    cout << "Original BST (inorder): ";
    printInorder(root);
    cout << endl;

    Solution s;
    root = s.bstToGst(root);

    cout << "GST (inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
