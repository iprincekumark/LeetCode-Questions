class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int l1 = ransomNote.size(), l2 = magazine.size();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        while(1) {
            for(auto i:ransomNote)
                mp1[i]++;
            for(auto i:magazine)
                mp2[i]++;
            break;
        }
        for(auto &ch:ransomNote) {
            if(mp1[ch] > mp2[ch])
                return false;
        }
        return true;
    }
};