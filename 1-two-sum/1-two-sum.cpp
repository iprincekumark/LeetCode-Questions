class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, ln=nums.size(), flag=0;
        vector<int> ans;
        for(i=0; i<ln-1; i++) {
            for(j=i+1; j<ln; j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        return ans;
    }
};