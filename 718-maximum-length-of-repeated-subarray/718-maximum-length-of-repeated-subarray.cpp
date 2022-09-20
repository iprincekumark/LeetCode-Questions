class Solution {
public:
    void out(vector < vector <int> > v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    int findLength(vector<int>& A, vector<int>& B) {
        int ret = 0;
        int n = A.size();
        int m = B.size();
        vector < vector <int> > dp(n, vector <int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i] == B[j]){
                    dp[i][j] = max(dp[i][j], 1 + (i - 1 >= 0 && j - 1 >= 0 ? dp[i-1][j-1] : 0));
                    ret = max(dp[i][j], ret);
                }
            }
        }
        //out(dp);
        return ret;
    }
};