class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = INT_MAX, index=-1;
        for(int i=0; i<points.size(); i++)
            if(points[i][0] == x || points[i][1] == y)
            {
                int temp = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(temp < ans)
                {
                    ans = temp;
                    index = i;
                }
            }
        return index;
    }
};