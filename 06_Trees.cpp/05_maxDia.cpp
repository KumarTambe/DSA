/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxHeight(TreeNode* root,int& maxDia){
        if(root == nullptr) return 0;
        int left = maxHeight(root->left , maxDia);
        int right = maxHeight(root->right , maxDia);
        maxDia = max(maxDia, left + right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        maxHeight(root,maxDia);
        return maxDia;
    }
};