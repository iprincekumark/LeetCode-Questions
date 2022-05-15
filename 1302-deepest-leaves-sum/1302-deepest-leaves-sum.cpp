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
    int sum =0, maxLevel = 0;
    void eachLevelSum(TreeNode* root, int level) {
        if(root == NULL) 
            return ;                    
        if(level > maxLevel) 
            sum = 0, maxLevel = level;     
        if(level == maxLevel) 
            sum += root->val;         
        eachLevelSum(root->left, level+1);     
        eachLevelSum(root->right, level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        eachLevelSum(root, 0);
        return sum;
    }
};