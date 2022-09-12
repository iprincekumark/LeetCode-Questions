class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int countVowelSubstrings(string word) {
        int ans=0, size=word.size();
        unordered_map<char, int> mp;
        for(auto i=0; i<size; ++i){
            mp.clear();
            for(auto j=i; j<size && isVowel(word[j]); ++j){
                mp[word[j]]++;
                if(mp.size()==5)    ans++;
            }
        }
        return ans;
    }
};