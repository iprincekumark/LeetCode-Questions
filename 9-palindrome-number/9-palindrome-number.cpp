class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        long long rev=0, ans=x;
        while(x!=0){
            rev = (rev*10) + (x%10);
            x = x/10;
        }
        if(rev == ans)
            return true;
        return false;
    }
};