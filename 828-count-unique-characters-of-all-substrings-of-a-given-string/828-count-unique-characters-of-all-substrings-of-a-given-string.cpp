class Solution {
public:
    int uniqueLetterString(string str) {
        int n = str.size();
        int ans = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            int count = 0;
            int prev = -1;
            int pos = -1;
            for(int i = 0; i < n; i++)
            {
                if(str[i] == ch)
                {
                    count++;
                    prev = pos;
                    pos = i;
                }
                if(count == 1)
                {
                    ans += pos + 1;
                }
                else
                {
                    ans += pos - prev;
                }
            }
        }
        
        return ans;    
    }
};
    