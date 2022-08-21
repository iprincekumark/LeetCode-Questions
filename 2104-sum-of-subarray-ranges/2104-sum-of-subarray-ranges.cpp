class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int ln=nums.size(), i, j, min, max;
        long long sum=0;
        vector<int> help;
        for(i=0; i<ln; i++) {
            min = nums[i], max = nums[i];
            for(j=i;j<ln;j++)
            {
                if(nums[j] < min) min = nums[j];
                if(nums[j] > max) max = nums[j];
                sum += max - min;
            }
        }
        return sum;
    }
};