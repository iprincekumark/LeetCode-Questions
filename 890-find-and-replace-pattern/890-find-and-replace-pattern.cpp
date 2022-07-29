class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int i, j, ln=pattern.size();
        vector<string> ans;
        for(i=0; i<words.size(); i++) {
            map<char, char> mp1;
            map<char, char> mp2;
            int flag=0;
            for(j=0; j<ln; j++) {
                auto it1 = mp1.find(pattern[j]);
                if(it1 == mp1.end()) 
                    mp1.insert({pattern[j], words[i][j]});
                else
                    if(it1->second != words[i][j]) {
                        flag=1;
                        break;
                    }
                
                auto it2 = mp2.find(words[i][j]);
                if(it2 == mp2.end())
                    mp2.insert({words[i][j], pattern[j]});
                else
                    if(it2->second != pattern[j]) {
                        flag=1;
                        break;
                    }
            }
            if(!flag)
                ans.push_back(words[i]);
        }
        return ans;
    }
};