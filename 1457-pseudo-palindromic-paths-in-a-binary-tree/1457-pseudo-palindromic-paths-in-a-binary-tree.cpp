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
    int ret;
    bool ok(vector <int>& v){
        int odd = 0;
        for(auto& it : v){
            //cout << it << " ";
            odd += it & 1;
        }
        //cout << endl;
        return odd == 0 || odd == 1;
    }
    void dfs(TreeNode* node, vector <int>& v){
        if(!node) return;
        v[node->val]++;
        if(!node->left && !node->right){
            if(ok(v)) ret++;
            v[node->val]--;
            return;
        }
        dfs(node->left, v);
        dfs(node->right, v);
        v[node->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ret = 0;
        vector <int> cnt(10);
        dfs(root, cnt);
        return ret;
    }
};