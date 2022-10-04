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
    bool help(TreeNode* root, int targetSum){
        if(!root)   return false;
        int value = targetSum - root->val;
        if(root->left == NULL && root->right == NULL)   return (value == 0);
        return hasPathSum(root->left, value) || hasPathSum(root->right, value);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root, targetSum);
    }
};