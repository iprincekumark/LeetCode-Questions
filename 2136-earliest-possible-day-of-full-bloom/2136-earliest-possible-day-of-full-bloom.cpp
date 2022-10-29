#define ss second
#define ff first
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        int diffA = a.ss - a.ff;
        int diffB = b.ss - b.ff;
        return diffA > diffB;
    }
    static bool cmp2(pair<int, int>& a, pair<int, int>& b){
        
        return  a.ss > b.ss;
    }
    int earliestFullBloom(vector<int>& v1, vector<int>& v2) {
        int ret = 0;
        int time = 0;
        vector<pair<int, int>> v;
        int n = v1.size();
        for(int i = 0; i < n; i++){
            v.push_back({v1[i], v2[i]});
        }
        sort(v.begin(), v.end(), cmp2);
        for(auto& it : v){
            time += it.ff;
            // cout << it.ff << " " << it.ss << endl;
            ret = max(ret, time + it.ss);
        }
        return ret;
    }
};