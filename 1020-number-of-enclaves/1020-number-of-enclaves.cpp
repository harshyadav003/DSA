class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int r = grid.size();
        int c = grid[0].size();
        vis[i][j] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int nrow = i + delrow[d];
            int ncol = j + delcol[d];
            if (nrow < r && ncol < c && nrow >= 0 && ncol >= 0 &&
                vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int moves = 0;
        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                if (row == 0 || col == 0 || row == r - 1 || col == c - 1) {
                    if (grid[row][col] == 1 && vis[row][col] == 0) {
                        dfs(row, col, grid, vis);
                    }
                }
            }
        }
        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                if (grid[row][col] == 1 && vis[row][col] == 0) {
                    moves++;
                    vis[row][col] == 1;
                }
            }
        }
        return moves;
    }
};