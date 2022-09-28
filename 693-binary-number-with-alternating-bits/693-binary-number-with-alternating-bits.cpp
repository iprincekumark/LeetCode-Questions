class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n&1;
        while((n&1) == bit){
            bit = 1-bit;
            n = n>>1;
        }
        if(n==0)    return true;
        return false;
    }
};