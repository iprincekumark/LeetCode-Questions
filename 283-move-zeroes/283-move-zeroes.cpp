class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j=0, l=nums.size();
        for(i=0; i<l; i++)
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        
        /*
        int i, j, countOfZero=0, l = nums.size();
        vector<int> out;
        for(i=0; i<l; i++) {
            if(nums[i] == 0)
                countOfZero++;
            if(nums[i] > 0)
                out.push_back(nums[i]);
        }
        for(i=0; i<countOfZero; i++) {
            out.push_back(0);
        }
        nums.swap(out);
        */
    }
};