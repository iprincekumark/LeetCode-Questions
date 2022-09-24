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
    vector < vector <int> > res;
    void dfs(TreeNode* root, int sum, vector <int>& temp){
        if(!root)return;
        if(!root->left && !root->right){
            if(sum == root->val){
                //cout << "Found " << endl;
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        temp.push_back(root->val);
        //cout << sum << " " << sum - root->val << endl;
        dfs(root->left, sum - root->val, temp);
        dfs(root->right, sum - root->val, temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        vector <int> temp;
        dfs(root, sum, temp);
        return res;
    }
};