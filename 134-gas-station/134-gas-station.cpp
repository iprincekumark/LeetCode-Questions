class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        if( (accumulate(gas.begin(), gas.end(), 0)) < (accumulate(cost.begin(), cost.end(), 0)))
            return -1;
        int n=gas.size();
        int remaining_fuel=0;
        int ans=0;
        for(int i=0; i<n; i++) {
            remaining_fuel += gas[i]-cost[i];
            if(remaining_fuel<0){
                ans = i+1;
                remaining_fuel = 0;
            }
        }
        return ans;
        */
        int i, left=0, ans=0, lg= gas.size(), totalgas, totalcost;
        totalgas = (accumulate(gas.begin(), gas.end(), 0));
        totalcost = (accumulate(cost.begin(), cost.end(), 0));
        if(totalgas < totalcost)
            return -1;
        for(i=0; i<lg; i++) {
            left += gas[i] - cost[i];
            if(left<0) {
                ans = i+1;
                left=0;
            }
        }
        return ans;
        
    }
};