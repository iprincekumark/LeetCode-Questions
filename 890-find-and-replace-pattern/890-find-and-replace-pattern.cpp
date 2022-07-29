class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word:words) {
            vector<char> pt(26, '*');
            vector<char> wd(26, '*');
            int i, flag=0, ln=pattern.size();
            for(i=0; i<ln; i++) {
                char p = pattern[i];
                char w = word[i];
                if(pt[p -'a'] == '*' && wd[w -'a'] == '*') {
                    pt[p -'a'] = w;
                    wd[w -'a'] = p;
                }
                else if(!(pt[p-'a'] == w && wd[w-'a'] == p)) {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                   ans.push_back(word);
        }
        return ans;
    }
};