/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* out;
    void findCorrespondingNode(TreeNode* O, TreeNode* C, TreeNode* T) {
        if(O == NULL)
            return ;
        if(O == T)
            out = C;
        findCorrespondingNode(O->left, C->left, T);
        findCorrespondingNode(O->right, C->right, T);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        findCorrespondingNode(original, cloned, target);
        return  out;
    }
};