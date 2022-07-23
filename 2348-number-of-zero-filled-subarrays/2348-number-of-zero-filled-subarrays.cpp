class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long s=nums.size();
        long long count=0;
        long long ans=0;   
        for(auto x:nums){
            if(x==0) count++;
            else{
                ans=ans+(count*(count+1)/2);
                count=0;
            }
        }
        ans=ans+(count*(count+1)/2);
        return ans;
    }
};