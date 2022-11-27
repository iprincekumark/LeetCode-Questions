
class Solution {
public:
	int countSubarrays(vector<int>& nums, int k) {
		int ret = 0;
		map<int, int> cnt;
		cnt[0 ] = 1;
		int sum  = 0;
        bool add = false;
		for (int i : nums) {
			if(i < k) sum++;
            else if(i > k) sum--;
            if(i == k) add = true;
            if(add){
                ret += cnt[sum];
                ret += cnt[sum + 1];
            }
            // cout << i << " " << ret << " " << sum << endl;
			if(!add)cnt[sum]++;
		}
		return ret;
	}
};