class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());
        vector<int> ans;
        int sPtr=0, ePtr=numbers.size()-1;
        while(sPtr!=ePtr){
            int sum = numbers[sPtr] + numbers[ePtr];
            if(sum==target){
                ans.push_back(sPtr+1);
                ans.push_back(ePtr+1);
                break;
            }
            else if(sum<target)
                sPtr++;
            else
                ePtr--;
        }
        return ans;
    }
};