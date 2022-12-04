typedef long long int lli;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        lli ret = INT_MAX;
        lli sum = 0;
        for(int i : nums) sum += i;
        lli n = nums.size();
        lli pre = 0;
        lli idx = -1;
        for(int i = 0; i < n; i++){
            pre += nums[i];
            lli suff = sum - pre;
            lli pre_avg = pre / (i + 1);
            lli suff_avg = n - 1 - i == 0? 0:suff / (n - 1 - i);
            if(abs(pre_avg - suff_avg) < ret){
                ret = abs(pre_avg - suff_avg);
                idx = i;
            }
        }
        // cout << ret << endl;
        return idx;
    }
};