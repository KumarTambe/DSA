#include<bits/stdc++.h>
using namespace std;

bool isMirror(TreeNode* p, TreeNode* q){
    if(p == nullptr && q == nullptr) return true;
    if(p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;
    bool isLeft = isSameTree(p->left,q->right);
    bool isRight = isSameTree(p->right,q->left);
    return isLeft && isRight;
}

bool isSymmetric(TreeNode* root){
    if(root == nullptr) return true;
    bool isTrue = isMirror(root->left,root->right);
    return isTrue;
}