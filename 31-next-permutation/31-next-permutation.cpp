class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1, i, j, bugP=0;
        for(i=n; i>0; i--) {
            if(nums[i]>nums[i-1]) {
                bugP=i;
                break;
            }
        }
        if(bugP==0)
            sort(nums.begin(), nums.end());
        else {
            int min = INT_MAX, unsettle= nums[bugP-1];
            for(j=bugP; j<=n; j++) {
                if(nums[j]-unsettle > 0  &&  nums[j]-unsettle) {
                    int temp = nums[j];
                    nums[j] = nums[bugP-1];
                    nums[bugP-1] = temp;
                }
            }
            sort(nums.begin()+bugP, nums.end());
        }
    }
};