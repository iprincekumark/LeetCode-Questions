typedef long long int lli;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ret = 0;
        unordered_map <lli, unordered_map <lli, lli> > dp, cnt;
        unordered_set <int> s (A.begin(), A.end());
        int n = A.size();
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                lli diff = (lli)A[i] - (lli)A[j];
                if(diff <= INT_MIN || diff > INT_MAX) continue;
                int temp = dp[j].count(diff) ? dp[j][diff] : 0;
                ret += temp;
                
                if(s.count(A[i] + diff))dp[i][diff] += temp + 1;
                
            }
        }
        return ret;
    }
};