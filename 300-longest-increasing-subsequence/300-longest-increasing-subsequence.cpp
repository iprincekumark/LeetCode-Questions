class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> out;
        for(int x : nums) {
            if(out.empty() || ( out[out.size()-1] < x ))
                out.push_back(x);
            else {
                auto it = lower_bound(out.begin(), out.end(), x);
                *it = x;
            }
        }
        return out.size();
    }
    /*
    int lengthOfLIS(vector<int>& nums) {
        int i, j, n=nums.size(), list[n]; 
        list[0] = 1;
        for(i=1; i<n; i++) {
            list[i]=1;
            for(j=0; j<i; j++)
                if(nums[i] > nums[j]  &&  list[i] < list[j]+1)
                    list[i] = list[j]+1;
        }
        return *max_element(list, list+n);
    }
    */
};

        
        
        
        /*
        int lis[n]; 

	    lis[0] = 1; 

	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
	} 
	return *max_element(lis, lis+n); 
        
        
        
        
    
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};
*/