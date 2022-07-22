class Solution {
public:
    int balancedStringSplit(string s) {
        int ln=s.size(), i, ans=0, out=0;
        for(i=0; i<ln; i++) {
            if('R' == s[i]){
                ans++;
                out += (ans==0)? 1:0;
            }
            if('L' == s[i]){
                ans--;
                out += (ans==0)? 1:0;
            }
        }
        return out;
    }
};