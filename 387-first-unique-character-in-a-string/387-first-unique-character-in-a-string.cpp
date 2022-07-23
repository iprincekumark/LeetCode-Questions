class Solution {
public:
    int firstUniqChar(string s) {
        int i, ln=s.size(), index;
        if(ln==1)
            return 0;
        vector<int> A(26,0);
        vector<int> K;
        for(i=0; i<ln; i++) {
            index = s[i] - 'a';
            A[index] += 1;
        }
        for(i=0; i<ln; i++) {
            index = s[i] - 'a';
            if(A[index] == 1)
                return i;
        }
        return -1;
    }
};