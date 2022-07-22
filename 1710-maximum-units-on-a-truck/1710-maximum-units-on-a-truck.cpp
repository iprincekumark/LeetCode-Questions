class Solution {
public:
    static bool myfunction(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units=0;
        sort(boxTypes.begin(), boxTypes.end(), myfunction);
        for(auto v:boxTypes) {
            int mini = min(v[0], truckSize);
            units += v[1]*mini;
            truckSize -= mini;
            if(!truckSize) 
                break;
        }
        return units;
    }
};