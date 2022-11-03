class Solution {
public:
    int r,c;
    int dfs(int i, int j, vector < vector <int> >& v){
        int n = v[0].size();
        // cout << i << " " << j << endl;
        if(i >= r){
            // cout << "LAST!" << endl;
            int ret = j >= 0 && j < c ? j : -1;
            // cout << ret << endl;
            return ret;
        }
        if(i < 0 || j < 0 || i >= v.size() || j >= c) return -1;
        if(v[i][j] == 1){
            if(j + 1 < n && v[i][j + 1] == -1) return -1;
            int ret =  dfs(i + 1, j + 1, v);
            // cout << ret << endl;
            return ret;
        }else{
            if(j - 1 >= 0 && v[i][j - 1] == 1) return -1;
            int ret =  dfs(i + 1, j - 1, v);
            // cout << ret << endl;
            return ret;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        r = grid.size();
         c = grid[0].size();
        vector <int> ret(c);
        for(int i = 0; i < c; i++){
            // cout << "start: " << i << endl;
            ret[i] = dfs(0, i, grid);
        }
        return ret;
    }
};