int dir [4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp[50][50][2000];
struct Data{
  int x, y, k, length;
    Data(int a, int b, int c, int d){
        x = a;
        y = b;
        k = c;
        length = d;
    }
};
class Solution {
public:
    void pre(){
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                for(int k = 0; k < 2000; k++){
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
    }
    bool ok(int x, int y, int r, int c){
        return (x < r && y < c && x >= 0 && y >= 0);
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        pre();
        int r = grid.size();
        int c = grid[0].size();
        queue <Data> q;
        Data root(0, 0, k, 0);
        q.push(root);
        while(!q.empty()){
            Data node = q.front();
            q.pop();
            int x = node.x;
            int y = node.y;
            int k = node.k;
            int length = node.length;
            if(x == r - 1 && y == c - 1) return length;
            length++;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx == r - 1 && ny == c - 1)return length;
                if(ok(nx, ny, r, c)){
                    if(grid[nx][ny] == 0){
                          if(length < dp[nx][ny][k]){
                              q.push(Data(nx, ny, k, length));
                              dp[nx][ny][k] = length;
                          }
                    }else{
                        if(k > 0 && length < dp[nx][ny][k]){
                             q.push(Data(nx, ny, k - 1, length));
                             dp[nx][ny][k] = length;
                          }
                    }
                }
            }
        }
        return -1;
    }
};