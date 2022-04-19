class Solution {
public:
    int numTrees(int n) {
        int i, j, catalan[n+1];
        catalan[0] = catalan[1] = 1;
        for(i=2; i<=n; i++) {
            catalan[i]=0;
            for(j=0; j<i; j++)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }
};