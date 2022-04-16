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
    int keySum=0;
    void help(TreeNode* root) {
        if(root==NULL)
            return ;
        help(root->right);
        root->val += keySum;
        keySum = root->val;
        help(root->left);
        return ;
    }
    TreeNode* convertBST(TreeNode* root) {
        help(root);
        return root;
    }
};