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
    vector<int> postorder;
    void help(TreeNode* root) {
        if(root == NULL)
            return ;
        help(root->left);
        help(root->right);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        help(root);
        return postorder;
    }
};