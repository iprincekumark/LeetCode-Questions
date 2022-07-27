class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i, max=0, count=0, ln=costs.size();
        sort(costs.begin(), costs.end());
        for(i=0; i<ln; i++) {
            max += costs[i];
            count++;
            if(max==coins)
                return count;
            if(max>coins)
                return count-1;
        }
        return count;
    }
};