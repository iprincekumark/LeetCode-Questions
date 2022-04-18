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
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(root == NULL)
            return ;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return ans.at(k-1);
    }
};
/*
class Solution {
public:
    int sol, Kth;
    void findKth(TreeNode* root) {
        if(root == NULL)
            return;
        findKth(root->left);
        Kth--;
        if(Kth == 0)
            sol = root->val;
        findKth(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        Kth = k;
        findKth(root);
        return sol;
        
    }
};

*/