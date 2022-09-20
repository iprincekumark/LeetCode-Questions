class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1, zero=0;
        for(auto &it:nums)
            if(it!=0) product*=it;
            else zero++;
        if(zero==nums.size() || zero>1){
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        vector<int> ans;
        for(auto &it:nums)
            if(zero>0)
                if(it==0) ans.push_back(product);
                else ans.push_back(0);
            else ans.push_back(product/it);
        return ans;
    }
};