class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(auto &ch:s)
            freq[ch-'a']++;
        int ans=0, last = s.size()+1;
        sort(freq, freq+26, greater<int>());
        for(int i=0; i<26; i++){
            if(freq[i] == 0)    break;
            if(last <= freq[i]){
                ans += freq[i]-last + (last!=0);
                freq[i] = last - (last!=0);
            }
            last = freq[i];
        }
        return ans;
    }
};