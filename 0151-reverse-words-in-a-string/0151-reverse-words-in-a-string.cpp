class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        reverseWordss(s);
        return getString(s);
    }
    string getString(string s){
        int i = 0;
         int j = s.size() - 1;
        while(s[i] == ' ' && i < s.size()) i++;
        while(j >= 0 && s[j] == ' ') j--;
        string ret = "";
        for(;i <= j; i++){
            if(ret.size() && ret.back() == ' ' && s[i] == ' ')continue;
            ret += s[i];
            
        }
        return ret;
    }
    void reverseWordss(string& s){
        int j = 0;
        for(int i = 0; i < s.size() ;i = j){
            
            if(s[i] == ' '){
                j = i + 1;
            }else{
                
                while(j + 1 < s.size() && s[j + 1] != ' ') j++;
                int x = i;
                int y = j;
                while(x < y){
                    swap(s[x], s[y]);
                    x++;
                    y--;
                }
                j++;
            }
        }
    }
};