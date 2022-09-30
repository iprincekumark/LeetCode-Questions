class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        /*
        int size=buildings.size(), xAxis, height=-1, i=0;
        vector<vector<int> > ans;
        priority_queue<pair<int, int> > pq;
        //for(int i=0; i<size || ;){
        while(i<size || (buildings[i][0] > xAxis)){
            if(pq.empty())  xAxis = buildings[i][0];
            else    xAxis = pq.top().second;
            
            if((buildings[i][0] > xAxis) || i>(size+1))
                while(!pq.empty() && (pq.top().second <= xAxis))
                    pq.pop();
            else {
                xAxis = buildings[i][0];
                while((buildings[i][0]==xAxis) && i<size){
                    pq.push(make_pair(buildings[i][2], buildings[i][1]));
                    ++i;
                }
            }
            if(pq.empty())  height=0;
            else    height=pq.top().first;
            
            if(ans.empty() || (ans[1].back() != height)){
                vector<int> temp;
                temp.push_back(xAxis);
                temp.push_back(height);
                ans.push_back(temp);
            }
        }
        return ans;
        
        
        */
        vector<pair<int, int> > events;
        vector<vector<int>> contour;
        multiset<int> heights;
        for(const vector<int>& building: buildings) {
            events.emplace_back(make_pair(building[0], -1 * building[2]));
            events.emplace_back(make_pair(building[1], building[2]));
        }
        sort(events.begin(), events.end());
        int max_height_so_far = 0, curr_height = 0;
        heights.emplace(0);
        for(const pair<int, int>& event: events) {
            if(event.second < 0)
                heights.emplace(-1 * event.second);
            else
                heights.erase(heights.find(event.second));
            curr_height = *heights.rbegin();
            if(curr_height != max_height_so_far) {
                contour.emplace_back(vector<int>{event.first, curr_height});
                max_height_so_far = curr_height;
            }
        }
        return contour;
    }
};