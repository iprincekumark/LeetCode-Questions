class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; ++i){
            int binaryBit=0, m=i;
            while(m>0){
                m = m & (m-1);
                binaryBit++;
            }
            ans.push_back(binaryBit);
        }
        return ans;
    }
};