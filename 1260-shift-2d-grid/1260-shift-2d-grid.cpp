class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int i;
        const int r = grid.size();
        const int c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (i = 0; i < r * c; ++i) {
            int ori_y = i / c;
            int ori_x = i % c;
            int new_y = (ori_y + (ori_x + k) / c) % r;
            int new_x = (ori_x + k) % c;
            
            ans[new_y][new_x] = grid[ori_y][ori_x];
        }
        return ans;
    }
};