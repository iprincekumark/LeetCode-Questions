class Solution {
public:
    int dfs(int i, int j,vector <int>& v1, vector <int>& v2, vector<vector<int>>& dp){
        if(i >= v2.size()) return 0;
        int ret = INT_MIN;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        ret = dfs(i + 1, j + 1, v1, v2, dp) + v2[i] * v1[j];
        int lastPtr = (i ) - (j );
        ret = max(ret, dfs(i + 1, j, v1, v2, dp) + v2[i] * v1[((int)v1.size()) - 1 - lastPtr]);
        return dp[i][j] = ret;
    }
    int maximumScore(vector<int>& v1, vector<int>& v2) {
        vector<vector<int>> dp(v2.size(), vector<int>(v2.size(), INT_MIN));
        long long int  ret = INT_MIN;
        int m = v2.size();
        int n = v1.size();
        return dfs(0, 0, v1, v2, dp);
        return ret;
    }
};