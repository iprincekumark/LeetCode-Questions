class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> played;
        map<int, int> cnt;
        for(auto& it : matches){
            played.insert(it[0]);
            played.insert(it[1]);
            cnt[it[1]]++;
        }
        vector<vector<int>> ret(2);
        for(auto& it : played){
            if(cnt[it] == 1) ret[1].push_back(it);
            else if(cnt[it] == 0) ret[0].push_back(it);
        }
        sort(ret[1].begin(), ret[1].end());
        sort(ret[0].begin(), ret[0].end());
        return ret;
    }
};