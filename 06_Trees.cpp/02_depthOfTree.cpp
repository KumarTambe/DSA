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

int depthOfTree(TreeNode* root){
    if(root == nullptr) return 0;
    int left = depthOfTree(root->left);
    int right = depthOfTree(root->right);
    return max(left,right) + 1;
}