class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ln=nums.size(), l=0, h=ln-1, mid;
        while(l<=h) {
            mid=l+(h-l)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(nums[mid] < target) 
                l = mid+1;
            else
                h = mid-1;
        }
        return -1;
    }
};