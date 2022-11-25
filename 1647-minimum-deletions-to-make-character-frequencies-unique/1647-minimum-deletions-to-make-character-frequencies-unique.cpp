class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequency(26);
        for(auto &ch:s)
            frequency[ch-'a']++;
        int totalDeletions = 0, nextUsedFreq = s.size();
        sort(frequency.begin(), frequency.end(), greater<int>());
        for(auto &freq:frequency){
            nextUsedFreq = min(nextUsedFreq, freq);
            totalDeletions += freq - nextUsedFreq;
            if(nextUsedFreq>0)  nextUsedFreq--;
        }
        return totalDeletions;
    }
};