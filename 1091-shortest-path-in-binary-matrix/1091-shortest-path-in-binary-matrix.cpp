class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        if(grid[n-1][m-1]==1 || grid[0][0]==1)//if the starting or ending point is not clear return -1.
            return -1;
        grid[0][0]=1;//set distance for starting point as 1.
        q.push({0,0});//push the starting point in the queue as we traverse the grid using bfs.
        int ans=0;
        int dx[]={0,0,-1,1,-1,-1,1,1};
		int dy[]={1,-1,0,0,1,-1,1,-1};
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=dx[i]+temp.first,ny=dy[i]+temp.second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0)//to check whether the neighbour is valid and yet to be traversed.
                {
                    grid[nx][ny]=grid[temp.first][temp.second]+1;//increase the distance of the neighbour by 1.
                    q.push({nx,ny});
                }
            }
        }
        if(grid[n-1][m-1]==0)//if end element is 0 that means we dont have a clear path so we return -1.
            return -1;
        return grid[n-1][m-1];
    }
};