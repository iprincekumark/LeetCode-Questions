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
    vector<int> inorder;
    void help(TreeNode* root) {
        if(root == NULL)
            return ;
        help(root->left);
        inorder.push_back(root->val);
        help(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        help(root);
        return inorder;
    }
};