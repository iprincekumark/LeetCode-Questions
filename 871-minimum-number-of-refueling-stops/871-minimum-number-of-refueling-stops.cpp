class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0, count=0, max=startFuel, ln=stations.size();
        priority_queue<int> pq;
        while(max < target) {
            while(i<ln && stations[i][0]<=max) {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) 
                return -1;
            max += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};