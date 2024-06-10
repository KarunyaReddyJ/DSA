#include<bits/stdc++.h>
#include "TreeStruct.cpp"
using namespace std;
void flatten(TreeNode* root) {
    stack<TreeNode*> st;
    flatter(root,st);
}
void flatter(TreeNode* root,stack<TreeNode*>& st){
    if(root==nullptr) return;
    else if(root->left==nullptr && root->right==nullptr){
        if(st.empty())
            return;
        root->right=st.top();
        st.pop();
    }
    else if(root->left!=nullptr){
        if(root->right)
            st.push(root->right);
        TreeNode* leftNode=root->left;
        root->right=leftNode;
        root->left=nullptr;
    }
    flatter(root->right,st);
}
int main(){
     
}