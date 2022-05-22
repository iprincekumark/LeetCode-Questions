class Solution {
public:
    int countAroundMid(string s, int ind, bool even) {
        int left = ind, right = even ? ind+1 : ind, res = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            res++;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += countAroundMid(s, i, true);
            res += countAroundMid(s, i, false);
        }
        return res;
    }
};