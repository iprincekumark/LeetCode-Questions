class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0)
            return ans;
        vector<int> curr;
        help(0, curr, nums);
        return ans;
    }
    void help(int start, vector<int> curr, vector<int>& nums) {
        ans.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            help(i + 1, curr, nums);
            curr.pop_back();
        }
    }
};