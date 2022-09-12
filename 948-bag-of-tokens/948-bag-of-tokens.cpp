class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int ret = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = n - 1;
        int curr = 0;
        while(i <= j &&  power >= tokens[i]){
            while(i <= j && power >= tokens[i]){
                power -= tokens[i];
                curr++;
                i++;
            }
            //cout << curr << " " << power << " " <<i << endl;
            ret = max(curr, ret);
            while(j >= i && curr && power < tokens[i]){
                curr--;
                power += tokens[j];
                j--;
            }
        }
        return ret;
    }
};