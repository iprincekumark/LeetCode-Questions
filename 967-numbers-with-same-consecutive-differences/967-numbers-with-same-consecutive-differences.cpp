class Solution {
public:
    vector<int> ans;
    void help(int num, int n, int k){
        auto noOfDigits = [] (int num, int count=0) { while(num>0) { count++, num /= 10; } return count;};
        if(noOfDigits(num) == n){
            ans.push_back(num);
            return;
        }
        for(int i=0; i<10; ++i){
            if(abs((num%10)-i) == k){
                int temp = num*10 + i;
                help(temp, n, k);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(auto i=1; i<10; ++i){
            help(i, n, k);
        }
        return ans;
    }
};