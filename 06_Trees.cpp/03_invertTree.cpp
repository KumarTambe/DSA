#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

TreeNode invertTree(TreeNode* root){
    if(root == nullptr) return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    inertTree(root->right);
    return root;
}