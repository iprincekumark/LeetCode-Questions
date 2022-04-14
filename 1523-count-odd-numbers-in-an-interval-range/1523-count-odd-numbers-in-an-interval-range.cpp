class Solution {
public:
    int countOdds(int low, int high) {
        int i, c;
        (low%2==0 && high%2==0)? c=(high-low)/2: c=(high-low)/2 +1;
        return c;
    }
};