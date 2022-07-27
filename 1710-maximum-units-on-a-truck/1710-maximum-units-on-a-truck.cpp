class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int limit=0, totalUnits=0, leftBox=0;
        priority_queue<pair<int, int>> pq;
        for(auto v:boxTypes) {
            pq.push({v[1], v[0]});
        }
        while(!pq.empty() && limit<truckSize) {
            if((pq.top().second + limit) < truckSize) {
                limit += pq.top().second;
                totalUnits += pq.top().first * pq.top().second;
            }
            else {
                leftBox = truckSize - limit;
                totalUnits += pq.top().first * leftBox;
                limit += leftBox;
            }
            pq.pop();
        }
        return totalUnits;
    }
};