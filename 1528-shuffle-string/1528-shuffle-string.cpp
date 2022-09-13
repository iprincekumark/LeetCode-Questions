class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int, char> mp;
        string ans;
        for(int i=0; i<indices.size(); ++i){
            mp[indices[i]] = s[i];
        }
        sort(indices.begin(), indices.end());
        for(auto i:indices)
            ans += mp[i];
        return ans;
    }
};