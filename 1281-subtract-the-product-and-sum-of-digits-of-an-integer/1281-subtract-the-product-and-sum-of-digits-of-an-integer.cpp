class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, prod=1;
        for(; n>0; n/=10) {
            sum += n%10;
            prod *= n%10;
        }
        return prod-sum;
    }
};