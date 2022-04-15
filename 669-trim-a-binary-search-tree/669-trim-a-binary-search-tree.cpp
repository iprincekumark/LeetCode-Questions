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
    TreeNode* help(TreeNode* root, int l, int h) {
        if(root == NULL)
            return NULL;
        if(root->val < l)
            return help(root->right, l, h);
        else if(root->val > h)
            return help(root->left, l, h);
        root->left = help(root->left, l, h);
        root->right = help(root->right, l, h);
        return root;
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return help(root, low, high);
    }
};