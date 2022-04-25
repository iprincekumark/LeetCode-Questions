class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size(), i, j, k, flag;
        vector<int> out;
        
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                flag=0;
                if(nums1[i] == nums2[j]){
                    for(k=j+1; k<n; k++) {
                        if(nums2[k] > nums2[j]) {
                            out.push_back(nums2[k]);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                        out.push_back(-1);
                }
            }
        }
        return out;
    }
};