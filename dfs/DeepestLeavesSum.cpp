#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int depth(TreeNode* root){
    if(root==nullptr) return 0;
    return 1+max(depth(root->left),depth(root->right));
}
int leaveSum(TreeNode* root,int d){
    if(root==nullptr)
        return 0;
    if(d==0)
        return root->val;
    return leaveSum(root->left,d-1)+leaveSum(root->right,d-1);
}
int deepestLeavesSum(TreeNode* root) { 
    int d=depth(root);
    return leaveSum(root,d);
}
int main(){
    TreeNode* root;
}