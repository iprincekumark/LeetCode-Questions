class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        vector<int> ans;
        unordered_map<int, int> twoSum;
        for(i=0; i<nums.size(); i++) {
            if(twoSum.find(target-nums[i]) != twoSum.end()) {
                ans.push_back(twoSum[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            twoSum[nums[i]]=i;
        }
        return ans;
    }
};