class Solution {
public:
    int numRollsToTarget(int n, int k, int tar) {
        int DP[n+1][tar+1];
        const int M=1e9+7;
        for(int i=n; i>=0; i--){
            for(int t=0; t<=tar; t++){
                if(i==n){
                    DP[i][t]=(t==0?1:0);
                    continue;
                }
                DP[i][t]=0;
                for(int j=1; j<=min(k, t); j++)
                    DP[i][t] = (DP[i][t]+DP[i+1][t-j])%M;
            }
        }
        return DP[0][tar];
    }
};