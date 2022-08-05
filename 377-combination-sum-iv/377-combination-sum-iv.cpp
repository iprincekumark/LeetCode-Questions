class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> sumArray(target+1, -1);
        sumArray[0]=1;
        countSum(nums, target, sumArray);
        return sumArray[target];
    }
    int countSum(vector<int>& nums, int target, vector<int>& sumArray) {
        if(sumArray[target]>-1)
            return sumArray[target];
        int count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<=target)
                count += countSum(nums, target-nums[i], sumArray);
        }
        sumArray[target] = count;
        return count;
    }
};