typedef long long int lli;
const lli MOD = 1e9 + 7;
class Solution {
public:
    lli add(lli a, lli b){
        return ((a % MOD) + (b  % MOD)) % MOD;
    }
    lli mul(lli a, lli b){
        return ((a % MOD) * (b  % MOD)) % MOD;
    }
    /*
    string getBin(lli x){
        string ret = "";
        while(x > 0){
            if(x & 1){
                ret += '1';
            }else{
                ret += '0';
            }
            x >>= 1;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    */
    lli fastPow(lli base, lli p){
        lli ret = 1;
        while(p > 0){
            if(p & 1){
                ret = mul(ret, base);
            }
            base = mul(base, base);
            p >>= 1;
        }
        return ret;
    }
    int concatenatedBinary(int n) {
        lli ret = 0;
        lli base = 0;
        for(lli i = n; i >= 1; i--){
            lli cnt = 0;
            lli x = i;
            while(x > 0){
                cnt++;
                // cout<<cnt<<endl;
                x >>= 1;
            }
            // cout << cnt << " " << ret << " " << base << endl;
            ret = add(ret, mul(i, fastPow(2, base)));
            base = add(base, cnt);
        }
        return ret;
    }
};