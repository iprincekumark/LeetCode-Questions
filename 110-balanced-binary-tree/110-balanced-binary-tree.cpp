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
    int help(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = help(root->left);
        if(lh == -1)
            return -1;
        int rh = help(root->right);
        if(rh == -1)
            return -1;
        
        if(1 < abs(lh-rh))
            return -1;
        else
            return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
    /*
    int depth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int l = depth(root->left), r = depth(root->right);
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int l = depth(root->left), r = depth(root->right);
        if(abs(l-r) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
    }
    */
};