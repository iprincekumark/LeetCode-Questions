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
    vector<int> preorder;
    void help(TreeNode* root) {
        if(root == NULL)
            return ;
        preorder.push_back(root->val);
        help(root->left);
        help(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        help(root);
        return preorder;
    }
};