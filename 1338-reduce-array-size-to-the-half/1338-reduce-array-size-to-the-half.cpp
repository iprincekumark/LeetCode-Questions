class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int ln=arr.size(), half = ln, ans=0;
        for(auto it:arr) {
            mp[it]++;
        }
        multimap<int, int, greater<int>> mm;
        for(auto it:mp) {
            mm.insert({it.second, it.first});
        }
        
        for(auto it = mm.begin(); it!=mm.end(); it++) {
            half -= it->first;
            ans++;
            if(half <= (ln/2))
                return ans;
                
        }
        return 0;
    }
};