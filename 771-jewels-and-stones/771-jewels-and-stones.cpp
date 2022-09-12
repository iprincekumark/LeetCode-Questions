class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_map<char, int> mp;
        for(auto &i:stones)
            mp[i]++;
        for(auto &i:jewels)
            if(mp[i]>0)
                count+=mp[i];
        return count;
    }
};