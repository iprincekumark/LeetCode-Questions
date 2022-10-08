class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minimum = INT_MAX, result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1, r = nums.size() - 1;
            if(i && nums[i] == nums[i - 1]) continue;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == target){
                    return sum;
                }
                else if(sum < target) l++;
                else r--;
                
                if(minimum > abs(target - sum)){
                    minimum = abs(target - sum);
                    result = sum;
                }
            }
        }
        return result;
    }
};