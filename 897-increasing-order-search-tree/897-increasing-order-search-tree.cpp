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
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root)
    {
        vector<int>v;
        inorder(root,v);
        TreeNode*temp=new TreeNode(v[0]);
        TreeNode* r=temp;
        for(int i=1;i<v.size();i++)
        {
            temp->right=new TreeNode(v[i]);
            temp=temp->right;
        }
        return r;
    }
};