class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, digit, position, ln=nums.size();
        for(i=0; i<ln; i++) {
            digit = nums[i];
            if(digit>= 1 && digit<=ln) {
                position = digit-1;
                if(nums[position] != digit){
                    swap(nums[position], nums[i]);
                    i--;
                }
                    
            }
        }
        for(i=0; i<ln; i++) 
            if(i+1 != nums[i])  return i+1;
        return digit+1;
    }
};