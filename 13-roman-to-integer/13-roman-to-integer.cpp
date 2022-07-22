class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rTi = {{'I', 1}, 
                                        {'V', 5}, 
                                        {'X', 10}, 
                                        {'L', 50}, 
                                        {'C', 100}, 
                                        {'D', 500}, 
                                        {'M', 1000}};
        int i, ln = s.size(), ans = rTi[s.back()];
        if(ln==0 || ln>15)
            return 0;
        else {
            for(i=ln-2; i>-1; i--) {
                if(rTi[s[i]] < rTi[s[i+1]])
                    ans -= rTi[s[i]];
                else
                    ans += rTi[s[i]];
            }
        }
        return ans;
    }
};