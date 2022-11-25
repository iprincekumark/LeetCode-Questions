class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=NULL, num2=NULL, count1=0, count2=0, limit = nums.size()/3;
        for(auto &num:nums){
            if(num==num1)   count1++;
            else if(num==num2)  count2++;
            else if(count1==0) {
                num1 = num;
                count1 = 1;
            }
            else if(count2==0) {
                num2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        int x=0, y=0;
        for(auto &num:nums){
            if(num==num1)   ++x;
            else if(num==num2)  ++y;
        }
        vector<int> ans;
        if(x>limit) ans.push_back(num1);
        if(y>limit) ans.push_back(num2);
        return ans;
    }
};