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

bool isMirror(TreeNode* left,TreeNode* right){
    if( left  == nullptr && right == nullptr){
        return true;
    }
    if(left == nullptr || right == nullptr){
        return false;
    }
    if(left->val == right->val){
        bool leftMirror = isMirror(left->left, right->right);
        bool rightMirror = isMirror(left->right, right->left);
        return leftMirror && rightMirror;
    } else {
        return false;
    }
}

