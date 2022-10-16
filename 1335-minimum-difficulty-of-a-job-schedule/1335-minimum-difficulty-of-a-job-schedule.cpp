class Solution {
public:
    int solve(vector <int> &v, int idx, int k, vector < vector <int> >&dp){
        if(idx == v.size() && k == 0) return 0;
        if(k < 0 || idx == v.size() && k > 0) return 1e6;
        if(dp[idx][k] != -1) return dp[idx][k];
        int maxVal = 0;
        int ret = INT_MAX;
        for(int i = idx; i < v.size(); i++){
            maxVal = max(v[i], maxVal);
            ret = min(ret, maxVal + solve(v, i + 1, k - 1, dp));
        }
        return dp[idx][k] = ret;
    }
    int minDifficulty(vector<int>& j, int d) {
       int n = j.size();
        if(d > n) return -1;
        vector < vector <int> > dp(n, vector<int> (d + 1, -1));
       return solve(j, 0, d, dp);
    }
};