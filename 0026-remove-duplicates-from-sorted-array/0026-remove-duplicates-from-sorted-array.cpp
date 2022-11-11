class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        ans = nums.size()-count;
        return ans;
    }
};