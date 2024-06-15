#include<bits/stdc++.h>
using namespace std;

struct treeNode{
    int val;
    treeNode* left,*right;
    treeNode(int num){
        val=num;
        left=right=nullptr;
    }
    treeNode(int num,treeNode* l,treeNode* r){
        val=num;
        left=l;
        right=r;
    }
    void inorder(treeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
};


int main(){
    treeNode* root=new treeNode(1,new treeNode(2,new treeNode(4),nullptr),new treeNode(3));
    root->inorder(root);
}