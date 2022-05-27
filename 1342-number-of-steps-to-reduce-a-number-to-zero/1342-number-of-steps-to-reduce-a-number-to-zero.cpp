class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        
        while(num){
            // odd
            if(num & 1)
                num--;
            else //even
                num >>=1;
            cnt++;
        }
        return cnt;
    }
};