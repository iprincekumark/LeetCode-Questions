class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0, i, j, r=grid.size(), c=grid[0].size();
        for(i=0; i<r; i++) {
            for(j=0; j<c; j++) {
                if(grid[i][j]=='1') {
                    help(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    void help(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        if(grid[i][j]=='0')
            return;
        grid[i][j]='0';
        help(grid, i+1, j);
        help(grid, i-1, j);
        help(grid, i, j+1);
        help(grid, i, j-1);
    }
};