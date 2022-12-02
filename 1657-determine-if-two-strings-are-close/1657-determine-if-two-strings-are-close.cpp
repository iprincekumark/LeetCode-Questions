class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map <char, int> cnt;
        map <char, int> cnt2;
        if(word1.size() != word2.size()) return false;
        for(auto& it : word1) cnt[it]++;
        vector <int> v1;
        vector <int> v2;
        for(auto& it : word2){
            if(cnt[it] > 0) cnt2[it]++;
            else return false;
        }
        
        for(auto& it : cnt){
            v1.push_back(it.second);
            v2.push_back(cnt2[it.first]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
    }
};