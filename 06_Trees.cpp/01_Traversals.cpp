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

void helper(TreeNode* root,vector<int>&result) {
    if(root == nullptr) return;
    helper(root->left,result);
    result.push_back(root->val);
    helper(root->right,result);
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    helper(root,result);
    return result;
}