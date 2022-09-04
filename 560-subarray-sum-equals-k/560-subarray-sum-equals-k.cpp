class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSum=0, totalNumber=0, search=0;
        unordered_map<int, int> mp;
        mp[totalSum]=1;
        for(auto it:nums){
            totalSum += it;
            search = totalSum - k;
            if(mp.find(search) != mp.end()) 
                totalNumber += mp[search];
            mp[totalSum]++;
        }
        return totalNumber;
    }
};