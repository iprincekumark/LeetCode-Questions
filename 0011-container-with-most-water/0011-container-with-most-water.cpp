class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, mostWaterArea=INT_MIN, area=0;
        while(left<right){
            area = min(height[left], height[right])*(right-left);
            mostWaterArea = (area>mostWaterArea)? area : mostWaterArea;
            if(min(height[left], height[right]) == height[left])    ++left;
            else    --right;
        }
        return mostWaterArea;
    }
};