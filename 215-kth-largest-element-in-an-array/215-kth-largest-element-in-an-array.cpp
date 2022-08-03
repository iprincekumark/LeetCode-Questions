class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ln=nums.size();
        for(int i=0; i<ln; i++) {
            pq.push(nums[i]);
        }
        for(int i=0; i<ln; i++) {
            nums[i] = pq.top();
            pq.pop();
        }
        return nums[k-1];
    }
};