class Solution {
public:
    int arraySign(vector<int>& nums) {
        int i , c = 0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0)
                return 0;
            else if(nums[i] < 0)
                c++;
        }
        if(c %2 == 0)
            return 1;
        else
            return -1;
    }
};