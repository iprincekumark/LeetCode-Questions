class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans,curr;
        while(i<j) {
            curr = (j-i)*min(height[i],height[j]);
            ans = max(ans,curr);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};