class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int f=0,p1=-1,p2=-1;
        vector<int> n;
        n=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(n[i]!=nums[i] )
            {p1=i;break;}
        }
        for(int i=n.size()-1;i>=0;i--)
        {
            if(n[i]!=nums[i])
            {p2=i;break;}
        }
        if(p1==-1)
            return 0;
        return p2-p1+1;
    }
};