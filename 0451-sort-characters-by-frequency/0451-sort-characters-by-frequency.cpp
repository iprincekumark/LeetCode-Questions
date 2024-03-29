class Solution {
public:
    static bool cmp(pair <int, char> a, pair <int, char> b){
        return a.first < b.first;
    }
    string frequencySort(string s) {
        vector < pair <int, char> > v;
        map <char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        map <char, int> :: iterator i = m.begin();
        while(i != m.end()){
            v.push_back({i->second, i->first});
            i++;
        }
        sort(v.rbegin(), v.rend(), cmp);
        string ans = "";
        for(int i = 0; i < v.size(); i++){
            int t = v[i].first;
            while(t--)ans += v[i].second;
        }
        return ans;
    }
};