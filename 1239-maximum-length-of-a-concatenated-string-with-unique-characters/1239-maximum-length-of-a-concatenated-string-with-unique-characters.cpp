class Solution {
public:
    bool ok(string s, string t){
        map <char, int > x;
        for(int i = 0; i < s.size(); i++){
            x[s[i]]++;
            if(x[s[i]] >1)return false;
        }
        for(int i = 0; i < t.size(); i++){
            x[t[i]]++;
            if(x[t[i]]>1)return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        vector <string> v;
        int ans = 0;
        v.push_back("");
        for(int i = 0; i < arr.size(); i++){
            int n = v.size();
            for(int j = 0; j < n; j++){
                if(ok(v[j],arr[i])){
                    string t = v[j]+arr[i];
                    v.push_back(t);
                    ans = max(ans,(int)t.size());
                }
            }
        }
        return ans;
    }
};