class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
         int m=grid.size();//row
        int n=grid[0].size();//column
        vis[i][j]=1;

        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = row + delrow;//n=neighbour
                    int ncol = col + delcol;
                    if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1' ){
                         if(abs(delrow) + abs(delcol) != 1) continue;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();//row
        int n=grid[0].size();//column
       vector<vector<int>> vis(m, vector<int>(n, 0));
       int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0) {
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
return cnt;
    }
};