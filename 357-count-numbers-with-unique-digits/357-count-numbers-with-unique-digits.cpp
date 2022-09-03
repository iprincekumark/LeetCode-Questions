class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)    return 1;
        if(n==1)    return 10;
        int totalSum=10, temp=9, curr=9;
        while(temp && n-->1){
            curr *= temp--;
            totalSum += curr;
        }
        return totalSum;
    }
};