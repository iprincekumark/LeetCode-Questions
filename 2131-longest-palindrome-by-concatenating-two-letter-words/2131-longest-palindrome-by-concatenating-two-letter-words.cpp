class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ret = 0;
        map<string, int> cnt;
        for(auto& it : words){
            cnt[it]    ++;
        }
        bool odd = false;
        
        for(auto& it : cnt){
            
            string temp = it.first;
            reverse(temp.begin(), temp.end());
            if(it.first == temp){
                int x = it.second;
                if(it.second & 1){
                    ret += 2 * (it.second - 1);
                    odd = true;
                    
                }else{
                    ret += 2 * it.second;
                }
                continue;
            }
            int take = min(cnt[temp], cnt[it.first]);
            
            // cout << it.first << " " << take << endl;
            cnt[temp] -= take;
            
            cnt[it.first] -= take;
            ret += 2 * 2 * take;
            
        }
        
        return ret + (odd? 2 : 0) ;
        
    }
};