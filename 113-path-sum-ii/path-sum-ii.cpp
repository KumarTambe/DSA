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
    void findPaths(TreeNode* root, int remaining, vector<int>& path, vector<vector<int>>& result) {
    if (root == nullptr) return;
    path.push_back(root->val);                
    remaining -= root->val;
    if (root->left == nullptr && root->right == nullptr && remaining == 0) {
        result.push_back(path);
    }
    findPaths(root->left, remaining, path, result);    
    findPaths(root->right, remaining, path, result);
    path.pop_back();                          
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    findPaths(root, targetSum, path, result);
    return result;
}
};