class Solution {
public:
    vector <string> split(string& s, char delimiter){
        vector <string> ret;
        istringstream tokenStream(s);
        string token;
        while(getline(tokenStream, token, delimiter)) ret.push_back(token);
        return ret;
    }
    string reverseWords(string s) {
        vector <string> temp = split(s, ' ');
        string ret = "";
        for(string& x : temp){
            reverse(x.begin(), x.end());
            if(ret.size()) ret += " ";
            ret += x;
        }
        return ret;
    }
};