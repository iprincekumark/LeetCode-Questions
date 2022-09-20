class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int lo=i+1, hi=nums.size()-1, target = 0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==target){
                        vector<int> help;
                        help.push_back(nums[i]);
                        help.push_back(nums[lo]);
                        help.push_back(nums[hi]);
                        ans.push_back(help);
                        
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo++, hi--;
                    }
                    else if(nums[lo]+nums[hi]<target) lo++;
                    else hi--;
                }
            }
        }
        return ans;
    }
};