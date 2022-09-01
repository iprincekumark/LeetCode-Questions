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
    int count=0;
    void help(TreeNode* root, int par){
        if(root==NULL)  return ;
        if(root->val >= par) {
            count++;
            par = root->val;
        }
        help(root->left, par);
        help(root->right, par);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        help(root, root->val);
        return count;
    }
};