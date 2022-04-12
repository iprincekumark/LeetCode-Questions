class Solution {
private:
    int mx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int my[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    int get_live_neighbors(vector<vector<int>> &board, int a, int b)
    {
        int n = 0;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = mx[i] + a, y = my[i] + b;
            
            if(0 <= x and x < board.size() and 0 <= y and y < board[0].size())
                if(board[x][y] == 1 or board[x][y] == 2)
                    n++;
        }
        
        return n;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        
        // 0 -> prev dead, now dead
        // 1 -> prev alive, now alive
        // 2 -> prev alive, now dead
        // 3 -> prev dead, now alive
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int neigh = get_live_neighbors(board, i, j);
                
                if(!board[i][j])
                {
                    if(neigh == 3)
                        board[i][j] = 3;
                }
                else
                {
                    if(neigh < 2 or neigh > 3)
                        board[i][j] = 2;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                board[i][j] %= 2;
    }
};