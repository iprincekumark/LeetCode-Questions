class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=NULL, count=0;
        for(auto &num:nums){
            if(count==0)    element=num;
            count += (num==element)? 1 : -1;
        }
        return element;
    }
};