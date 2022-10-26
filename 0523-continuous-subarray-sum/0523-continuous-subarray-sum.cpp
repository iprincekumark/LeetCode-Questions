class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(k)
                sum %= k;
            if(m.count(sum) && i - m[sum] >= 2){
                return true;
            }
            if(!m.count(sum)) m[sum] = i;
        }
        return false;
    }  
};