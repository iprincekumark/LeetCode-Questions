class Solution {
public:
    int countBinarySubstrings(string s) {
        int ln=s.size(), i=1, prev=0, curr=1, count=0;
        while(i<ln) {
            if(s[i-1] != s[i]) {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            else 
                curr++;
            i++;
        }
        count += min(prev, curr);
        return count;
    }
};